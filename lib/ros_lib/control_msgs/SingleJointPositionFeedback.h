#ifndef _ROS_control_msgs_SingleJointPositionFeedback_h
#define _ROS_control_msgs_SingleJointPositionFeedback_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"
#include "std_msgs/Header.h"

namespace control_msgs
{

  class SingleJointPositionFeedback : public ros::Msg
  {
    public:
      std_msgs::Header header;
      float position;
      float velocity;
      float error;

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      offset += this->header.serialize(outbuffer + offset);
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
      int32_t * val_velocity = (int32_t *) &(this->velocity);
      int32_t exp_velocity = (((*val_velocity)>>23)&255);
      if(exp_velocity != 0)
        exp_velocity += 1023-127;
      int32_t sig_velocity = *val_velocity;
      *(outbuffer + offset++) = 0;
      *(outbuffer + offset++) = 0;
      *(outbuffer + offset++) = 0;
      *(outbuffer + offset++) = (sig_velocity<<5) & 0xff;
      *(outbuffer + offset++) = (sig_velocity>>3) & 0xff;
      *(outbuffer + offset++) = (sig_velocity>>11) & 0xff;
      *(outbuffer + offset++) = ((exp_velocity<<4) & 0xF0) | ((sig_velocity>>19)&0x0F);
      *(outbuffer + offset++) = (exp_velocity>>4) & 0x7F;
      if(this->velocity < 0) *(outbuffer + offset -1) |= 0x80;
      int32_t * val_error = (int32_t *) &(this->error);
      int32_t exp_error = (((*val_error)>>23)&255);
      if(exp_error != 0)
        exp_error += 1023-127;
      int32_t sig_error = *val_error;
      *(outbuffer + offset++) = 0;
      *(outbuffer + offset++) = 0;
      *(outbuffer + offset++) = 0;
      *(outbuffer + offset++) = (sig_error<<5) & 0xff;
      *(outbuffer + offset++) = (sig_error>>3) & 0xff;
      *(outbuffer + offset++) = (sig_error>>11) & 0xff;
      *(outbuffer + offset++) = ((exp_error<<4) & 0xF0) | ((sig_error>>19)&0x0F);
      *(outbuffer + offset++) = (exp_error>>4) & 0x7F;
      if(this->error < 0) *(outbuffer + offset -1) |= 0x80;
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer)
    {
      int offset = 0;
      offset += this->header.deserialize(inbuffer + offset);
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
      uint32_t * val_velocity = (uint32_t*) &(this->velocity);
      offset += 3;
      *val_velocity = ((uint32_t)(*(inbuffer + offset++))>>5 & 0x07);
      *val_velocity |= ((uint32_t)(*(inbuffer + offset++)) & 0xff)<<3;
      *val_velocity |= ((uint32_t)(*(inbuffer + offset++)) & 0xff)<<11;
      *val_velocity |= ((uint32_t)(*(inbuffer + offset)) & 0x0f)<<19;
      uint32_t exp_velocity = ((uint32_t)(*(inbuffer + offset++))&0xf0)>>4;
      exp_velocity |= ((uint32_t)(*(inbuffer + offset)) & 0x7f)<<4;
      if(exp_velocity !=0)
        *val_velocity |= ((exp_velocity)-1023+127)<<23;
      if( ((*(inbuffer+offset++)) & 0x80) > 0) this->velocity = -this->velocity;
      uint32_t * val_error = (uint32_t*) &(this->error);
      offset += 3;
      *val_error = ((uint32_t)(*(inbuffer + offset++))>>5 & 0x07);
      *val_error |= ((uint32_t)(*(inbuffer + offset++)) & 0xff)<<3;
      *val_error |= ((uint32_t)(*(inbuffer + offset++)) & 0xff)<<11;
      *val_error |= ((uint32_t)(*(inbuffer + offset)) & 0x0f)<<19;
      uint32_t exp_error = ((uint32_t)(*(inbuffer + offset++))&0xf0)>>4;
      exp_error |= ((uint32_t)(*(inbuffer + offset)) & 0x7f)<<4;
      if(exp_error !=0)
        *val_error |= ((exp_error)-1023+127)<<23;
      if( ((*(inbuffer+offset++)) & 0x80) > 0) this->error = -this->error;
     return offset;
    }

    const char * getType(){ return "control_msgs/SingleJointPositionFeedback"; };
    const char * getMD5(){ return "8cee65610a3d08e0a1bded82f146f1fd"; };

  };

}
#endif