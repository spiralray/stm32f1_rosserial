#ifndef _ROS_control_msgs_SingleJointPositionGoal_h
#define _ROS_control_msgs_SingleJointPositionGoal_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"
#include "ros/duration.h"

namespace control_msgs
{

  class SingleJointPositionGoal : public ros::Msg
  {
    public:
      float position;
      ros::Duration min_duration;
      float max_velocity;

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
      *(outbuffer + offset + 0) = (this->min_duration.sec >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (this->min_duration.sec >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (this->min_duration.sec >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (this->min_duration.sec >> (8 * 3)) & 0xFF;
      offset += sizeof(this->min_duration.sec);
      *(outbuffer + offset + 0) = (this->min_duration.nsec >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (this->min_duration.nsec >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (this->min_duration.nsec >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (this->min_duration.nsec >> (8 * 3)) & 0xFF;
      offset += sizeof(this->min_duration.nsec);
      int32_t * val_max_velocity = (int32_t *) &(this->max_velocity);
      int32_t exp_max_velocity = (((*val_max_velocity)>>23)&255);
      if(exp_max_velocity != 0)
        exp_max_velocity += 1023-127;
      int32_t sig_max_velocity = *val_max_velocity;
      *(outbuffer + offset++) = 0;
      *(outbuffer + offset++) = 0;
      *(outbuffer + offset++) = 0;
      *(outbuffer + offset++) = (sig_max_velocity<<5) & 0xff;
      *(outbuffer + offset++) = (sig_max_velocity>>3) & 0xff;
      *(outbuffer + offset++) = (sig_max_velocity>>11) & 0xff;
      *(outbuffer + offset++) = ((exp_max_velocity<<4) & 0xF0) | ((sig_max_velocity>>19)&0x0F);
      *(outbuffer + offset++) = (exp_max_velocity>>4) & 0x7F;
      if(this->max_velocity < 0) *(outbuffer + offset -1) |= 0x80;
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
      this->min_duration.sec =  ((uint32_t) (*(inbuffer + offset)));
      this->min_duration.sec |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      this->min_duration.sec |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      this->min_duration.sec |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      offset += sizeof(this->min_duration.sec);
      this->min_duration.nsec =  ((uint32_t) (*(inbuffer + offset)));
      this->min_duration.nsec |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      this->min_duration.nsec |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      this->min_duration.nsec |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      offset += sizeof(this->min_duration.nsec);
      uint32_t * val_max_velocity = (uint32_t*) &(this->max_velocity);
      offset += 3;
      *val_max_velocity = ((uint32_t)(*(inbuffer + offset++))>>5 & 0x07);
      *val_max_velocity |= ((uint32_t)(*(inbuffer + offset++)) & 0xff)<<3;
      *val_max_velocity |= ((uint32_t)(*(inbuffer + offset++)) & 0xff)<<11;
      *val_max_velocity |= ((uint32_t)(*(inbuffer + offset)) & 0x0f)<<19;
      uint32_t exp_max_velocity = ((uint32_t)(*(inbuffer + offset++))&0xf0)>>4;
      exp_max_velocity |= ((uint32_t)(*(inbuffer + offset)) & 0x7f)<<4;
      if(exp_max_velocity !=0)
        *val_max_velocity |= ((exp_max_velocity)-1023+127)<<23;
      if( ((*(inbuffer+offset++)) & 0x80) > 0) this->max_velocity = -this->max_velocity;
     return offset;
    }

    const char * getType(){ return "control_msgs/SingleJointPositionGoal"; };
    const char * getMD5(){ return "fbaaa562a23a013fd5053e5f72cbb35c"; };

  };

}
#endif