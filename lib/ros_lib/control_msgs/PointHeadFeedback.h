#ifndef _ROS_control_msgs_PointHeadFeedback_h
#define _ROS_control_msgs_PointHeadFeedback_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"

namespace control_msgs
{

  class PointHeadFeedback : public ros::Msg
  {
    public:
      float pointing_angle_error;

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      int32_t * val_pointing_angle_error = (int32_t *) &(this->pointing_angle_error);
      int32_t exp_pointing_angle_error = (((*val_pointing_angle_error)>>23)&255);
      if(exp_pointing_angle_error != 0)
        exp_pointing_angle_error += 1023-127;
      int32_t sig_pointing_angle_error = *val_pointing_angle_error;
      *(outbuffer + offset++) = 0;
      *(outbuffer + offset++) = 0;
      *(outbuffer + offset++) = 0;
      *(outbuffer + offset++) = (sig_pointing_angle_error<<5) & 0xff;
      *(outbuffer + offset++) = (sig_pointing_angle_error>>3) & 0xff;
      *(outbuffer + offset++) = (sig_pointing_angle_error>>11) & 0xff;
      *(outbuffer + offset++) = ((exp_pointing_angle_error<<4) & 0xF0) | ((sig_pointing_angle_error>>19)&0x0F);
      *(outbuffer + offset++) = (exp_pointing_angle_error>>4) & 0x7F;
      if(this->pointing_angle_error < 0) *(outbuffer + offset -1) |= 0x80;
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer)
    {
      int offset = 0;
      uint32_t * val_pointing_angle_error = (uint32_t*) &(this->pointing_angle_error);
      offset += 3;
      *val_pointing_angle_error = ((uint32_t)(*(inbuffer + offset++))>>5 & 0x07);
      *val_pointing_angle_error |= ((uint32_t)(*(inbuffer + offset++)) & 0xff)<<3;
      *val_pointing_angle_error |= ((uint32_t)(*(inbuffer + offset++)) & 0xff)<<11;
      *val_pointing_angle_error |= ((uint32_t)(*(inbuffer + offset)) & 0x0f)<<19;
      uint32_t exp_pointing_angle_error = ((uint32_t)(*(inbuffer + offset++))&0xf0)>>4;
      exp_pointing_angle_error |= ((uint32_t)(*(inbuffer + offset)) & 0x7f)<<4;
      if(exp_pointing_angle_error !=0)
        *val_pointing_angle_error |= ((exp_pointing_angle_error)-1023+127)<<23;
      if( ((*(inbuffer+offset++)) & 0x80) > 0) this->pointing_angle_error = -this->pointing_angle_error;
     return offset;
    }

    const char * getType(){ return "control_msgs/PointHeadFeedback"; };
    const char * getMD5(){ return "cce80d27fd763682da8805a73316cab4"; };

  };

}
#endif