/* Includes */
#include "mbed.h"
#include "XNucleoIKS01A2.h"

Serial pc(SERIAL_TX, SERIAL_RX);

/* Instantiate the expansion board */
static XNucleoIKS01A2 *mems_expansion_board = XNucleoIKS01A2::instance(D14, D15, D4, D5);

/* Retrieve the composing elements of the expansion board */
static LSM6DSLSensor *acc_gyro = mems_expansion_board->acc_gyro;

InterruptIn mybutton(USER_BUTTON);

volatile int mems_event = 0;
volatile int toggle_hw_event_enable = 0;
static int hw_event_is_enabled = 1;


/* User button callback. */
void pressed_cb() {
  toggle_hw_event_enable = 1;
}

/* Interrupt 1 callback. */
void int1_cb() {
  mems_event = 1;
}

/* Interrupt 2 callback. */
void int2_cb() {
  mems_event = 1;
}



/* Simple main function */
int main() {
  pc.baud(9600);
  


  /* Attach callback to LSM6DSL INT1 */
  acc_gyro->attach_int1_irq(&int1_cb);
  /* Attach callback to LSM6DSL INT2 */
  acc_gyro->attach_int2_irq(&int2_cb);
  
  /* Enable LSM6DSL accelerometer */
  acc_gyro->enable_x();
 
  acc_gyro->enable_wake_up_detection();
  
  printf("\r\n--- Starting new run ---\r\n");
 
  while(1) {
    if (mems_event) {
      mems_event = 0;
      LSM6DSL_Event_Status_t status;
      acc_gyro->get_event_status(&status);


      if (status.WakeUpStatus) {
        /* Output data. */
       pc.printf("u");
        wait(0.1);
      }
    }

    if (toggle_hw_event_enable) {
      toggle_hw_event_enable = 0;
      if (hw_event_is_enabled == 0) {

        acc_gyro->enable_wake_up_detection();
        hw_event_is_enabled = 1;
      } else {
 
        acc_gyro->disable_wake_up_detection();
        hw_event_is_enabled = 0;
      }
    }
  }
}
