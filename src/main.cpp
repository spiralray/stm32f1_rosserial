/* Includes ------------------------------------------------------------------*/
#include "config/stm32plus.h"
#include "config/gpio.h"
#include "config/timing.h"

#include "ros.h"
#include <std_msgs/String.h>


using namespace stm32plus;

/* Defines -------------------------------------------------------------------*/

/* Variables -----------------------------------------------------------------*/

/* Constants -----------------------------------------------------------------*/

/* Function prototypes -------------------------------------------------------*/

/* Functions -----------------------------------------------------------------*/

/**************************************************************************/
/*!
    @brief  Main Program.
	@param  None.
    @retval None.
 */
/**************************************************************************/
int main(void)
{
  //Initialise Systick
  MillisecondTimer::initialise();
  Nvic::initialise();

  ros::NodeHandle  nh;

  std_msgs::String str_msg;
  ros::Publisher chatter("chatter", &str_msg);

  char hello[13] = "hello world!";

  nh.initNode();
  nh.advertise(chatter);
  while(1){
      str_msg.data = hello;
      chatter.publish( &str_msg );
      nh.spinOnce();
      MillisecondTimer::delay(1000);
  }

}

/* End Of File ---------------------------------------------------------------*/

