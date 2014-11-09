#ifndef _ROS_control_msgs_GripperCommand_h
#define _ROS_control_msgs_GripperCommand_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"

namespace control_msgs
{

  class GripperCommand : public ros::Msg
  {
    public:
      float position;
      float max_effort;

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      int32_t * val_position = (int32_t *) &(this->position);
      int32_t exp_position = (((*val_position)>>23)&255);
      if(exp_position != 0)
        exp_position += 1023-127;
      int32_t sig_position = *val_position;
      *(outbuffer + offset++) = 0;
      *(outbuffer + offset++) = 0;
      *(outbuffer + offset++) = 0;
      *(outbuffer + offset++) = (sig_position<<5) & 0xff;
      *(outbuffer + offset++) = (sig_position>>3) & 0xff;
      *(outbuffer + offset++) = (sig_position>>11) & 0xff;
      *(outbuffer + offset++) = ((exp_position<<4) & 0xF0) | ((sig_position>>19)&0x0F);
      *(outbuffer + offset++) = (exp_position>>4) & 0x7F;
      if(this->position < 0) *(outbuffer + offset -1) |= 0x80;
      int32_t * val_max_effort = (int32_t *) &(this->max_effort);
      int32_t exp_max_effort = (((*val_max_effort)>>23)&255);
      if(exp_max_effort != 0)
        exp_max_effort += 1023-127;
      int32_t sig_max_effort = *val_max_effort;
      *(outbuffer + offset++) = 0;
      *(outbuffer + offset++) = 0;
      *(outbuffer + offset++) = 0;
      *(outbuffer + offset++) = (sig_max_effort<<5) & 0xff;
      *(outbuffer + offset++) = (sig_max_effort>>3) & 0xff;
      *(outbuffer + offset++) = (sig_max_effort>>11) & 0xff;
      *(outbuffer + offset++) = ((exp_max_effort<<4) & 0xF0) | ((sig_max_effort>>19)&0x0F);
      *(outbuffer + offset++) = (exp_max_effort>>4) & 0x7F;
      if(this->max_effort < 0) *(outbuffer + offset -1) |= 0x80;
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer)
    {
      int offset = 0;
      uint32_t * val_position = (uint32_t*) &(this->position);
      offset += 3;
      *val_position = ((uint32_t)(*(inbuffer + offset++))>>5 & 0x07);
      *val_position |= ((uint32_t)(*(inbuffer + offset++)) & 0xff)<<3;
      *val_position |= ((uint32_t)(*(inbuffer + offset++)) & 0xff)<<11;
      *val_position |= ((uint32_t)(*(inbuffer + offset)) & 0x0f)<<19;
      uint32_t exp_position = ((uint32_t)(*(inbuffer + offset++))&0xf0)>>4;
      exp_position |= ((uint32_t)(*(inbuffer + offset)) & 0x7f)<<4;
      if(exp_position !=0)
        *val_position |= ((exp_position)-1023+127)<<23;
      if( ((*(inbuffer+offset++)) & 0x80) > 0) this->position = -this->position;
      uint32_t * val_max_effort = (uint32_t*) &(this->max_effort);
      offset += 3;
      *val_max_effort = ((uint32_t)(*(inbuffer + offset++))>>5 & 0x07);
      *val_max_effort |= ((uint32_t)(*(inbuffer + offset++)) & 0xff)<<3;
      *val_max_effort |= ((uint32_t)(*(inbuffer + offset++)) & 0xff)<<11;
      *val_max_effort |= ((uint32_t)(*(inbuffer + offset)) & 0x0f)<<19;
      uint32_t exp_max_effort = ((uint32_t)(*(inbuffer + offset++))&0xf0)>>4;
      exp_max_effort |= ((uint32_t)(*(inbuffer + offset)) & 0x7f)<<4;
      if(exp_max_effort !=0)
        *val_max_effort |= ((exp_max_effort)-1023+127)<<23;
      if( ((*(inbuffer+offset++)) & 0x80) > 0) this->max_effort = -this->max_effort;
     return offset;
    }

    const char * getType(){ return "control_msgs/GripperCommand"; };
    const char * getMD5(){ return "680acaff79486f017132a7f198d40f08"; };

  };

}
#endif