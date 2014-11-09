#ifndef _ROS_control_msgs_JointTolerance_h
#define _ROS_control_msgs_JointTolerance_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"

namespace control_msgs
{

  class JointTolerance : public ros::Msg
  {
    public:
      const char* name;
      float position;
      float velocity;
      float acceleration;

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      uint32_t length_name = strlen(this->name);
      memcpy(outbuffer + offset, &length_name, sizeof(uint32_t));
      offset += 4;
      memcpy(outbuffer + offset, this->name, length_name);
      offset += length_name;
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
      int32_t * val_acceleration = (int32_t *) &(this->acceleration);
      int32_t exp_acceleration = (((*val_acceleration)>>23)&255);
      if(exp_acceleration != 0)
        exp_acceleration += 1023-127;
      int32_t sig_acceleration = *val_acceleration;
      *(outbuffer + offset++) = 0;
      *(outbuffer + offset++) = 0;
      *(outbuffer + offset++) = 0;
      *(outbuffer + offset++) = (sig_acceleration<<5) & 0xff;
      *(outbuffer + offset++) = (sig_acceleration>>3) & 0xff;
      *(outbuffer + offset++) = (sig_acceleration>>11) & 0xff;
      *(outbuffer + offset++) = ((exp_acceleration<<4) & 0xF0) | ((sig_acceleration>>19)&0x0F);
      *(outbuffer + offset++) = (exp_acceleration>>4) & 0x7F;
      if(this->acceleration < 0) *(outbuffer + offset -1) |= 0x80;
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer)
    {
      int offset = 0;
      uint32_t length_name;
      memcpy(&length_name, (inbuffer + offset), sizeof(uint32_t));
      offset += 4;
      for(unsigned int k= offset; k< offset+length_name; ++k){
          inbuffer[k-1]=inbuffer[k];
      }
      inbuffer[offset+length_name-1]=0;
      this->name = (char *)(inbuffer + offset-1);
      offset += length_name;
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
      uint32_t * val_acceleration = (uint32_t*) &(this->acceleration);
      offset += 3;
      *val_acceleration = ((uint32_t)(*(inbuffer + offset++))>>5 & 0x07);
      *val_acceleration |= ((uint32_t)(*(inbuffer + offset++)) & 0xff)<<3;
      *val_acceleration |= ((uint32_t)(*(inbuffer + offset++)) & 0xff)<<11;
      *val_acceleration |= ((uint32_t)(*(inbuffer + offset)) & 0x0f)<<19;
      uint32_t exp_acceleration = ((uint32_t)(*(inbuffer + offset++))&0xf0)>>4;
      exp_acceleration |= ((uint32_t)(*(inbuffer + offset)) & 0x7f)<<4;
      if(exp_acceleration !=0)
        *val_acceleration |= ((exp_acceleration)-1023+127)<<23;
      if( ((*(inbuffer+offset++)) & 0x80) > 0) this->acceleration = -this->acceleration;
     return offset;
    }

    const char * getType(){ return "control_msgs/JointTolerance"; };
    const char * getMD5(){ return "f544fe9c16cf04547e135dd6063ff5be"; };

  };

}
#endif