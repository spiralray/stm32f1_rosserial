#ifndef _ROS_control_msgs_JointControllerState_h
#define _ROS_control_msgs_JointControllerState_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"
#include "std_msgs/Header.h"

namespace control_msgs
{

  class JointControllerState : public ros::Msg
  {
    public:
      std_msgs::Header header;
      float set_point;
      float process_value;
      float process_value_dot;
      float error;
      float time_step;
      float command;
      float p;
      float i;
      float d;
      float i_clamp;

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      offset += this->header.serialize(outbuffer + offset);
      int32_t * val_set_point = (int32_t *) &(this->set_point);
      int32_t exp_set_point = (((*val_set_point)>>23)&255);
      if(exp_set_point != 0)
        exp_set_point += 1023-127;
      int32_t sig_set_point = *val_set_point;
      *(outbuffer + offset++) = 0;
      *(outbuffer + offset++) = 0;
      *(outbuffer + offset++) = 0;
      *(outbuffer + offset++) = (sig_set_point<<5) & 0xff;
      *(outbuffer + offset++) = (sig_set_point>>3) & 0xff;
      *(outbuffer + offset++) = (sig_set_point>>11) & 0xff;
      *(outbuffer + offset++) = ((exp_set_point<<4) & 0xF0) | ((sig_set_point>>19)&0x0F);
      *(outbuffer + offset++) = (exp_set_point>>4) & 0x7F;
      if(this->set_point < 0) *(outbuffer + offset -1) |= 0x80;
      int32_t * val_process_value = (int32_t *) &(this->process_value);
      int32_t exp_process_value = (((*val_process_value)>>23)&255);
      if(exp_process_value != 0)
        exp_process_value += 1023-127;
      int32_t sig_process_value = *val_process_value;
      *(outbuffer + offset++) = 0;
      *(outbuffer + offset++) = 0;
      *(outbuffer + offset++) = 0;
      *(outbuffer + offset++) = (sig_process_value<<5) & 0xff;
      *(outbuffer + offset++) = (sig_process_value>>3) & 0xff;
      *(outbuffer + offset++) = (sig_process_value>>11) & 0xff;
      *(outbuffer + offset++) = ((exp_process_value<<4) & 0xF0) | ((sig_process_value>>19)&0x0F);
      *(outbuffer + offset++) = (exp_process_value>>4) & 0x7F;
      if(this->process_value < 0) *(outbuffer + offset -1) |= 0x80;
      int32_t * val_process_value_dot = (int32_t *) &(this->process_value_dot);
      int32_t exp_process_value_dot = (((*val_process_value_dot)>>23)&255);
      if(exp_process_value_dot != 0)
        exp_process_value_dot += 1023-127;
      int32_t sig_process_value_dot = *val_process_value_dot;
      *(outbuffer + offset++) = 0;
      *(outbuffer + offset++) = 0;
      *(outbuffer + offset++) = 0;
      *(outbuffer + offset++) = (sig_process_value_dot<<5) & 0xff;
      *(outbuffer + offset++) = (sig_process_value_dot>>3) & 0xff;
      *(outbuffer + offset++) = (sig_process_value_dot>>11) & 0xff;
      *(outbuffer + offset++) = ((exp_process_value_dot<<4) & 0xF0) | ((sig_process_value_dot>>19)&0x0F);
      *(outbuffer + offset++) = (exp_process_value_dot>>4) & 0x7F;
      if(this->process_value_dot < 0) *(outbuffer + offset -1) |= 0x80;
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
      int32_t * val_time_step = (int32_t *) &(this->time_step);
      int32_t exp_time_step = (((*val_time_step)>>23)&255);
      if(exp_time_step != 0)
        exp_time_step += 1023-127;
      int32_t sig_time_step = *val_time_step;
      *(outbuffer + offset++) = 0;
      *(outbuffer + offset++) = 0;
      *(outbuffer + offset++) = 0;
      *(outbuffer + offset++) = (sig_time_step<<5) & 0xff;
      *(outbuffer + offset++) = (sig_time_step>>3) & 0xff;
      *(outbuffer + offset++) = (sig_time_step>>11) & 0xff;
      *(outbuffer + offset++) = ((exp_time_step<<4) & 0xF0) | ((sig_time_step>>19)&0x0F);
      *(outbuffer + offset++) = (exp_time_step>>4) & 0x7F;
      if(this->time_step < 0) *(outbuffer + offset -1) |= 0x80;
      int32_t * val_command = (int32_t *) &(this->command);
      int32_t exp_command = (((*val_command)>>23)&255);
      if(exp_command != 0)
        exp_command += 1023-127;
      int32_t sig_command = *val_command;
      *(outbuffer + offset++) = 0;
      *(outbuffer + offset++) = 0;
      *(outbuffer + offset++) = 0;
      *(outbuffer + offset++) = (sig_command<<5) & 0xff;
      *(outbuffer + offset++) = (sig_command>>3) & 0xff;
      *(outbuffer + offset++) = (sig_command>>11) & 0xff;
      *(outbuffer + offset++) = ((exp_command<<4) & 0xF0) | ((sig_command>>19)&0x0F);
      *(outbuffer + offset++) = (exp_command>>4) & 0x7F;
      if(this->command < 0) *(outbuffer + offset -1) |= 0x80;
      int32_t * val_p = (int32_t *) &(this->p);
      int32_t exp_p = (((*val_p)>>23)&255);
      if(exp_p != 0)
        exp_p += 1023-127;
      int32_t sig_p = *val_p;
      *(outbuffer + offset++) = 0;
      *(outbuffer + offset++) = 0;
      *(outbuffer + offset++) = 0;
      *(outbuffer + offset++) = (sig_p<<5) & 0xff;
      *(outbuffer + offset++) = (sig_p>>3) & 0xff;
      *(outbuffer + offset++) = (sig_p>>11) & 0xff;
      *(outbuffer + offset++) = ((exp_p<<4) & 0xF0) | ((sig_p>>19)&0x0F);
      *(outbuffer + offset++) = (exp_p>>4) & 0x7F;
      if(this->p < 0) *(outbuffer + offset -1) |= 0x80;
      int32_t * val_i = (int32_t *) &(this->i);
      int32_t exp_i = (((*val_i)>>23)&255);
      if(exp_i != 0)
        exp_i += 1023-127;
      int32_t sig_i = *val_i;
      *(outbuffer + offset++) = 0;
      *(outbuffer + offset++) = 0;
      *(outbuffer + offset++) = 0;
      *(outbuffer + offset++) = (sig_i<<5) & 0xff;
      *(outbuffer + offset++) = (sig_i>>3) & 0xff;
      *(outbuffer + offset++) = (sig_i>>11) & 0xff;
      *(outbuffer + offset++) = ((exp_i<<4) & 0xF0) | ((sig_i>>19)&0x0F);
      *(outbuffer + offset++) = (exp_i>>4) & 0x7F;
      if(this->i < 0) *(outbuffer + offset -1) |= 0x80;
      int32_t * val_d = (int32_t *) &(this->d);
      int32_t exp_d = (((*val_d)>>23)&255);
      if(exp_d != 0)
        exp_d += 1023-127;
      int32_t sig_d = *val_d;
      *(outbuffer + offset++) = 0;
      *(outbuffer + offset++) = 0;
      *(outbuffer + offset++) = 0;
      *(outbuffer + offset++) = (sig_d<<5) & 0xff;
      *(outbuffer + offset++) = (sig_d>>3) & 0xff;
      *(outbuffer + offset++) = (sig_d>>11) & 0xff;
      *(outbuffer + offset++) = ((exp_d<<4) & 0xF0) | ((sig_d>>19)&0x0F);
      *(outbuffer + offset++) = (exp_d>>4) & 0x7F;
      if(this->d < 0) *(outbuffer + offset -1) |= 0x80;
      int32_t * val_i_clamp = (int32_t *) &(this->i_clamp);
      int32_t exp_i_clamp = (((*val_i_clamp)>>23)&255);
      if(exp_i_clamp != 0)
        exp_i_clamp += 1023-127;
      int32_t sig_i_clamp = *val_i_clamp;
      *(outbuffer + offset++) = 0;
      *(outbuffer + offset++) = 0;
      *(outbuffer + offset++) = 0;
      *(outbuffer + offset++) = (sig_i_clamp<<5) & 0xff;
      *(outbuffer + offset++) = (sig_i_clamp>>3) & 0xff;
      *(outbuffer + offset++) = (sig_i_clamp>>11) & 0xff;
      *(outbuffer + offset++) = ((exp_i_clamp<<4) & 0xF0) | ((sig_i_clamp>>19)&0x0F);
      *(outbuffer + offset++) = (exp_i_clamp>>4) & 0x7F;
      if(this->i_clamp < 0) *(outbuffer + offset -1) |= 0x80;
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer)
    {
      int offset = 0;
      offset += this->header.deserialize(inbuffer + offset);
      uint32_t * val_set_point = (uint32_t*) &(this->set_point);
      offset += 3;
      *val_set_point = ((uint32_t)(*(inbuffer + offset++))>>5 & 0x07);
      *val_set_point |= ((uint32_t)(*(inbuffer + offset++)) & 0xff)<<3;
      *val_set_point |= ((uint32_t)(*(inbuffer + offset++)) & 0xff)<<11;
      *val_set_point |= ((uint32_t)(*(inbuffer + offset)) & 0x0f)<<19;
      uint32_t exp_set_point = ((uint32_t)(*(inbuffer + offset++))&0xf0)>>4;
      exp_set_point |= ((uint32_t)(*(inbuffer + offset)) & 0x7f)<<4;
      if(exp_set_point !=0)
        *val_set_point |= ((exp_set_point)-1023+127)<<23;
      if( ((*(inbuffer+offset++)) & 0x80) > 0) this->set_point = -this->set_point;
      uint32_t * val_process_value = (uint32_t*) &(this->process_value);
      offset += 3;
      *val_process_value = ((uint32_t)(*(inbuffer + offset++))>>5 & 0x07);
      *val_process_value |= ((uint32_t)(*(inbuffer + offset++)) & 0xff)<<3;
      *val_process_value |= ((uint32_t)(*(inbuffer + offset++)) & 0xff)<<11;
      *val_process_value |= ((uint32_t)(*(inbuffer + offset)) & 0x0f)<<19;
      uint32_t exp_process_value = ((uint32_t)(*(inbuffer + offset++))&0xf0)>>4;
      exp_process_value |= ((uint32_t)(*(inbuffer + offset)) & 0x7f)<<4;
      if(exp_process_value !=0)
        *val_process_value |= ((exp_process_value)-1023+127)<<23;
      if( ((*(inbuffer+offset++)) & 0x80) > 0) this->process_value = -this->process_value;
      uint32_t * val_process_value_dot = (uint32_t*) &(this->process_value_dot);
      offset += 3;
      *val_process_value_dot = ((uint32_t)(*(inbuffer + offset++))>>5 & 0x07);
      *val_process_value_dot |= ((uint32_t)(*(inbuffer + offset++)) & 0xff)<<3;
      *val_process_value_dot |= ((uint32_t)(*(inbuffer + offset++)) & 0xff)<<11;
      *val_process_value_dot |= ((uint32_t)(*(inbuffer + offset)) & 0x0f)<<19;
      uint32_t exp_process_value_dot = ((uint32_t)(*(inbuffer + offset++))&0xf0)>>4;
      exp_process_value_dot |= ((uint32_t)(*(inbuffer + offset)) & 0x7f)<<4;
      if(exp_process_value_dot !=0)
        *val_process_value_dot |= ((exp_process_value_dot)-1023+127)<<23;
      if( ((*(inbuffer+offset++)) & 0x80) > 0) this->process_value_dot = -this->process_value_dot;
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
      uint32_t * val_time_step = (uint32_t*) &(this->time_step);
      offset += 3;
      *val_time_step = ((uint32_t)(*(inbuffer + offset++))>>5 & 0x07);
      *val_time_step |= ((uint32_t)(*(inbuffer + offset++)) & 0xff)<<3;
      *val_time_step |= ((uint32_t)(*(inbuffer + offset++)) & 0xff)<<11;
      *val_time_step |= ((uint32_t)(*(inbuffer + offset)) & 0x0f)<<19;
      uint32_t exp_time_step = ((uint32_t)(*(inbuffer + offset++))&0xf0)>>4;
      exp_time_step |= ((uint32_t)(*(inbuffer + offset)) & 0x7f)<<4;
      if(exp_time_step !=0)
        *val_time_step |= ((exp_time_step)-1023+127)<<23;
      if( ((*(inbuffer+offset++)) & 0x80) > 0) this->time_step = -this->time_step;
      uint32_t * val_command = (uint32_t*) &(this->command);
      offset += 3;
      *val_command = ((uint32_t)(*(inbuffer + offset++))>>5 & 0x07);
      *val_command |= ((uint32_t)(*(inbuffer + offset++)) & 0xff)<<3;
      *val_command |= ((uint32_t)(*(inbuffer + offset++)) & 0xff)<<11;
      *val_command |= ((uint32_t)(*(inbuffer + offset)) & 0x0f)<<19;
      uint32_t exp_command = ((uint32_t)(*(inbuffer + offset++))&0xf0)>>4;
      exp_command |= ((uint32_t)(*(inbuffer + offset)) & 0x7f)<<4;
      if(exp_command !=0)
        *val_command |= ((exp_command)-1023+127)<<23;
      if( ((*(inbuffer+offset++)) & 0x80) > 0) this->command = -this->command;
      uint32_t * val_p = (uint32_t*) &(this->p);
      offset += 3;
      *val_p = ((uint32_t)(*(inbuffer + offset++))>>5 & 0x07);
      *val_p |= ((uint32_t)(*(inbuffer + offset++)) & 0xff)<<3;
      *val_p |= ((uint32_t)(*(inbuffer + offset++)) & 0xff)<<11;
      *val_p |= ((uint32_t)(*(inbuffer + offset)) & 0x0f)<<19;
      uint32_t exp_p = ((uint32_t)(*(inbuffer + offset++))&0xf0)>>4;
      exp_p |= ((uint32_t)(*(inbuffer + offset)) & 0x7f)<<4;
      if(exp_p !=0)
        *val_p |= ((exp_p)-1023+127)<<23;
      if( ((*(inbuffer+offset++)) & 0x80) > 0) this->p = -this->p;
      uint32_t * val_i = (uint32_t*) &(this->i);
      offset += 3;
      *val_i = ((uint32_t)(*(inbuffer + offset++))>>5 & 0x07);
      *val_i |= ((uint32_t)(*(inbuffer + offset++)) & 0xff)<<3;
      *val_i |= ((uint32_t)(*(inbuffer + offset++)) & 0xff)<<11;
      *val_i |= ((uint32_t)(*(inbuffer + offset)) & 0x0f)<<19;
      uint32_t exp_i = ((uint32_t)(*(inbuffer + offset++))&0xf0)>>4;
      exp_i |= ((uint32_t)(*(inbuffer + offset)) & 0x7f)<<4;
      if(exp_i !=0)
        *val_i |= ((exp_i)-1023+127)<<23;
      if( ((*(inbuffer+offset++)) & 0x80) > 0) this->i = -this->i;
      uint32_t * val_d = (uint32_t*) &(this->d);
      offset += 3;
      *val_d = ((uint32_t)(*(inbuffer + offset++))>>5 & 0x07);
      *val_d |= ((uint32_t)(*(inbuffer + offset++)) & 0xff)<<3;
      *val_d |= ((uint32_t)(*(inbuffer + offset++)) & 0xff)<<11;
      *val_d |= ((uint32_t)(*(inbuffer + offset)) & 0x0f)<<19;
      uint32_t exp_d = ((uint32_t)(*(inbuffer + offset++))&0xf0)>>4;
      exp_d |= ((uint32_t)(*(inbuffer + offset)) & 0x7f)<<4;
      if(exp_d !=0)
        *val_d |= ((exp_d)-1023+127)<<23;
      if( ((*(inbuffer+offset++)) & 0x80) > 0) this->d = -this->d;
      uint32_t * val_i_clamp = (uint32_t*) &(this->i_clamp);
      offset += 3;
      *val_i_clamp = ((uint32_t)(*(inbuffer + offset++))>>5 & 0x07);
      *val_i_clamp |= ((uint32_t)(*(inbuffer + offset++)) & 0xff)<<3;
      *val_i_clamp |= ((uint32_t)(*(inbuffer + offset++)) & 0xff)<<11;
      *val_i_clamp |= ((uint32_t)(*(inbuffer + offset)) & 0x0f)<<19;
      uint32_t exp_i_clamp = ((uint32_t)(*(inbuffer + offset++))&0xf0)>>4;
      exp_i_clamp |= ((uint32_t)(*(inbuffer + offset)) & 0x7f)<<4;
      if(exp_i_clamp !=0)
        *val_i_clamp |= ((exp_i_clamp)-1023+127)<<23;
      if( ((*(inbuffer+offset++)) & 0x80) > 0) this->i_clamp = -this->i_clamp;
     return offset;
    }

    const char * getType(){ return "control_msgs/JointControllerState"; };
    const char * getMD5(){ return "c0d034a7bf20aeb1c37f3eccb7992b69"; };

  };

}
#endif