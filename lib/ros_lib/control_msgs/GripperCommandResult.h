#ifndef _ROS_control_msgs_GripperCommandResult_h
#define _ROS_control_msgs_GripperCommandResult_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"

namespace control_msgs
{

  class GripperCommandResult : public ros::Msg
  {
    public:
      float position;
      float effort;
      bool stalled;
      bool reached_goal;

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
      int32_t * val_effort = (int32_t *) &(this->effort);
      int32_t exp_effort = (((*val_effort)>>23)&255);
      if(exp_effort != 0)
        exp_effort += 1023-127;
      int32_t sig_effort = *val_effort;
      *(outbuffer + offset++) = 0;
      *(outbuffer + offset++) = 0;
      *(outbuffer + offset++) = 0;
      *(outbuffer + offset++) = (sig_effort<<5) & 0xff;
      *(outbuffer + offset++) = (sig_effort>>3) & 0xff;
      *(outbuffer + offset++) = (sig_effort>>11) & 0xff;
      *(outbuffer + offset++) = ((exp_effort<<4) & 0xF0) | ((sig_effort>>19)&0x0F);
      *(outbuffer + offset++) = (exp_effort>>4) & 0x7F;
      if(this->effort < 0) *(outbuffer + offset -1) |= 0x80;
      union {
        bool real;
        uint8_t base;
      } u_stalled;
      u_stalled.real = this->stalled;
      *(outbuffer + offset + 0) = (u_stalled.base >> (8 * 0)) & 0xFF;
      offset += sizeof(this->stalled);
      union {
        bool real;
        uint8_t base;
      } u_reached_goal;
      u_reached_goal.real = this->reached_goal;
      *(outbuffer + offset + 0) = (u_reached_goal.base >> (8 * 0)) & 0xFF;
      offset += sizeof(this->reached_goal);
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
      uint32_t * val_effort = (uint32_t*) &(this->effort);
      offset += 3;
      *val_effort = ((uint32_t)(*(inbuffer + offset++))>>5 & 0x07);
      *val_effort |= ((uint32_t)(*(inbuffer + offset++)) & 0xff)<<3;
      *val_effort |= ((uint32_t)(*(inbuffer + offset++)) & 0xff)<<11;
      *val_effort |= ((uint32_t)(*(inbuffer + offset)) & 0x0f)<<19;
      uint32_t exp_effort = ((uint32_t)(*(inbuffer + offset++))&0xf0)>>4;
      exp_effort |= ((uint32_t)(*(inbuffer + offset)) & 0x7f)<<4;
      if(exp_effort !=0)
        *val_effort |= ((exp_effort)-1023+127)<<23;
      if( ((*(inbuffer+offset++)) & 0x80) > 0) this->effort = -this->effort;
      union {
        bool real;
        uint8_t base;
      } u_stalled;
      u_stalled.base = 0;
      u_stalled.base |= ((uint8_t) (*(inbuffer + offset + 0))) << (8 * 0);
      this->stalled = u_stalled.real;
      offset += sizeof(this->stalled);
      union {
        bool real;
        uint8_t base;
      } u_reached_goal;
      u_reached_goal.base = 0;
      u_reached_goal.base |= ((uint8_t) (*(inbuffer + offset + 0))) << (8 * 0);
      this->reached_goal = u_reached_goal.real;
      offset += sizeof(this->reached_goal);
     return offset;
    }

    const char * getType(){ return "control_msgs/GripperCommandResult"; };
    const char * getMD5(){ return "e4cbff56d3562bcf113da5a5adeef91f"; };

  };

}
#endif