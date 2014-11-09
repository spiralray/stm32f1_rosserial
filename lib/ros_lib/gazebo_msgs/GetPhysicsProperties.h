#ifndef _ROS_SERVICE_GetPhysicsProperties_h
#define _ROS_SERVICE_GetPhysicsProperties_h
#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"
#include "geometry_msgs/Vector3.h"
#include "gazebo_msgs/ODEPhysics.h"

namespace gazebo_msgs
{

static const char GETPHYSICSPROPERTIES[] = "gazebo_msgs/GetPhysicsProperties";

  class GetPhysicsPropertiesRequest : public ros::Msg
  {
    public:

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer)
    {
      int offset = 0;
     return offset;
    }

    const char * getType(){ return GETPHYSICSPROPERTIES; };
    const char * getMD5(){ return "d41d8cd98f00b204e9800998ecf8427e"; };

  };

  class GetPhysicsPropertiesResponse : public ros::Msg
  {
    public:
      float time_step;
      bool pause;
      float max_update_rate;
      geometry_msgs::Vector3 gravity;
      gazebo_msgs::ODEPhysics ode_config;
      bool success;
      const char* status_message;

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
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
      union {
        bool real;
        uint8_t base;
      } u_pause;
      u_pause.real = this->pause;
      *(outbuffer + offset + 0) = (u_pause.base >> (8 * 0)) & 0xFF;
      offset += sizeof(this->pause);
      int32_t * val_max_update_rate = (int32_t *) &(this->max_update_rate);
      int32_t exp_max_update_rate = (((*val_max_update_rate)>>23)&255);
      if(exp_max_update_rate != 0)
        exp_max_update_rate += 1023-127;
      int32_t sig_max_update_rate = *val_max_update_rate;
      *(outbuffer + offset++) = 0;
      *(outbuffer + offset++) = 0;
      *(outbuffer + offset++) = 0;
      *(outbuffer + offset++) = (sig_max_update_rate<<5) & 0xff;
      *(outbuffer + offset++) = (sig_max_update_rate>>3) & 0xff;
      *(outbuffer + offset++) = (sig_max_update_rate>>11) & 0xff;
      *(outbuffer + offset++) = ((exp_max_update_rate<<4) & 0xF0) | ((sig_max_update_rate>>19)&0x0F);
      *(outbuffer + offset++) = (exp_max_update_rate>>4) & 0x7F;
      if(this->max_update_rate < 0) *(outbuffer + offset -1) |= 0x80;
      offset += this->gravity.serialize(outbuffer + offset);
      offset += this->ode_config.serialize(outbuffer + offset);
      union {
        bool real;
        uint8_t base;
      } u_success;
      u_success.real = this->success;
      *(outbuffer + offset + 0) = (u_success.base >> (8 * 0)) & 0xFF;
      offset += sizeof(this->success);
      uint32_t length_status_message = strlen(this->status_message);
      memcpy(outbuffer + offset, &length_status_message, sizeof(uint32_t));
      offset += 4;
      memcpy(outbuffer + offset, this->status_message, length_status_message);
      offset += length_status_message;
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer)
    {
      int offset = 0;
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
      union {
        bool real;
        uint8_t base;
      } u_pause;
      u_pause.base = 0;
      u_pause.base |= ((uint8_t) (*(inbuffer + offset + 0))) << (8 * 0);
      this->pause = u_pause.real;
      offset += sizeof(this->pause);
      uint32_t * val_max_update_rate = (uint32_t*) &(this->max_update_rate);
      offset += 3;
      *val_max_update_rate = ((uint32_t)(*(inbuffer + offset++))>>5 & 0x07);
      *val_max_update_rate |= ((uint32_t)(*(inbuffer + offset++)) & 0xff)<<3;
      *val_max_update_rate |= ((uint32_t)(*(inbuffer + offset++)) & 0xff)<<11;
      *val_max_update_rate |= ((uint32_t)(*(inbuffer + offset)) & 0x0f)<<19;
      uint32_t exp_max_update_rate = ((uint32_t)(*(inbuffer + offset++))&0xf0)>>4;
      exp_max_update_rate |= ((uint32_t)(*(inbuffer + offset)) & 0x7f)<<4;
      if(exp_max_update_rate !=0)
        *val_max_update_rate |= ((exp_max_update_rate)-1023+127)<<23;
      if( ((*(inbuffer+offset++)) & 0x80) > 0) this->max_update_rate = -this->max_update_rate;
      offset += this->gravity.deserialize(inbuffer + offset);
      offset += this->ode_config.deserialize(inbuffer + offset);
      union {
        bool real;
        uint8_t base;
      } u_success;
      u_success.base = 0;
      u_success.base |= ((uint8_t) (*(inbuffer + offset + 0))) << (8 * 0);
      this->success = u_success.real;
      offset += sizeof(this->success);
      uint32_t length_status_message;
      memcpy(&length_status_message, (inbuffer + offset), sizeof(uint32_t));
      offset += 4;
      for(unsigned int k= offset; k< offset+length_status_message; ++k){
          inbuffer[k-1]=inbuffer[k];
      }
      inbuffer[offset+length_status_message-1]=0;
      this->status_message = (char *)(inbuffer + offset-1);
      offset += length_status_message;
     return offset;
    }

    const char * getType(){ return GETPHYSICSPROPERTIES; };
    const char * getMD5(){ return "575a5e74786981b7df2e3afc567693a6"; };

  };

  class GetPhysicsProperties {
    public:
    typedef GetPhysicsPropertiesRequest Request;
    typedef GetPhysicsPropertiesResponse Response;
  };

}
#endif
