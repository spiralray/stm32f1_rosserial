#ifndef _ROS_SERVICE_GetWorldProperties_h
#define _ROS_SERVICE_GetWorldProperties_h
#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"

namespace gazebo_msgs
{

static const char GETWORLDPROPERTIES[] = "gazebo_msgs/GetWorldProperties";

  class GetWorldPropertiesRequest : public ros::Msg
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

    const char * getType(){ return GETWORLDPROPERTIES; };
    const char * getMD5(){ return "d41d8cd98f00b204e9800998ecf8427e"; };

  };

  class GetWorldPropertiesResponse : public ros::Msg
  {
    public:
      float sim_time;
      uint8_t model_names_length;
      char* st_model_names;
      char* * model_names;
      bool rendering_enabled;
      bool success;
      const char* status_message;

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      int32_t * val_sim_time = (int32_t *) &(this->sim_time);
      int32_t exp_sim_time = (((*val_sim_time)>>23)&255);
      if(exp_sim_time != 0)
        exp_sim_time += 1023-127;
      int32_t sig_sim_time = *val_sim_time;
      *(outbuffer + offset++) = 0;
      *(outbuffer + offset++) = 0;
      *(outbuffer + offset++) = 0;
      *(outbuffer + offset++) = (sig_sim_time<<5) & 0xff;
      *(outbuffer + offset++) = (sig_sim_time>>3) & 0xff;
      *(outbuffer + offset++) = (sig_sim_time>>11) & 0xff;
      *(outbuffer + offset++) = ((exp_sim_time<<4) & 0xF0) | ((sig_sim_time>>19)&0x0F);
      *(outbuffer + offset++) = (exp_sim_time>>4) & 0x7F;
      if(this->sim_time < 0) *(outbuffer + offset -1) |= 0x80;
      *(outbuffer + offset++) = model_names_length;
      *(outbuffer + offset++) = 0;
      *(outbuffer + offset++) = 0;
      *(outbuffer + offset++) = 0;
      for( uint8_t i = 0; i < model_names_length; i++){
      uint32_t length_model_namesi = strlen(this->model_names[i]);
      memcpy(outbuffer + offset, &length_model_namesi, sizeof(uint32_t));
      offset += 4;
      memcpy(outbuffer + offset, this->model_names[i], length_model_namesi);
      offset += length_model_namesi;
      }
      union {
        bool real;
        uint8_t base;
      } u_rendering_enabled;
      u_rendering_enabled.real = this->rendering_enabled;
      *(outbuffer + offset + 0) = (u_rendering_enabled.base >> (8 * 0)) & 0xFF;
      offset += sizeof(this->rendering_enabled);
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
      uint32_t * val_sim_time = (uint32_t*) &(this->sim_time);
      offset += 3;
      *val_sim_time = ((uint32_t)(*(inbuffer + offset++))>>5 & 0x07);
      *val_sim_time |= ((uint32_t)(*(inbuffer + offset++)) & 0xff)<<3;
      *val_sim_time |= ((uint32_t)(*(inbuffer + offset++)) & 0xff)<<11;
      *val_sim_time |= ((uint32_t)(*(inbuffer + offset)) & 0x0f)<<19;
      uint32_t exp_sim_time = ((uint32_t)(*(inbuffer + offset++))&0xf0)>>4;
      exp_sim_time |= ((uint32_t)(*(inbuffer + offset)) & 0x7f)<<4;
      if(exp_sim_time !=0)
        *val_sim_time |= ((exp_sim_time)-1023+127)<<23;
      if( ((*(inbuffer+offset++)) & 0x80) > 0) this->sim_time = -this->sim_time;
      uint8_t model_names_lengthT = *(inbuffer + offset++);
      if(model_names_lengthT > model_names_length)
        this->model_names = (char**)realloc(this->model_names, model_names_lengthT * sizeof(char*));
      offset += 3;
      model_names_length = model_names_lengthT;
      for( uint8_t i = 0; i < model_names_length; i++){
      uint32_t length_st_model_names;
      memcpy(&length_st_model_names, (inbuffer + offset), sizeof(uint32_t));
      offset += 4;
      for(unsigned int k= offset; k< offset+length_st_model_names; ++k){
          inbuffer[k-1]=inbuffer[k];
      }
      inbuffer[offset+length_st_model_names-1]=0;
      this->st_model_names = (char *)(inbuffer + offset-1);
      offset += length_st_model_names;
        memcpy( &(this->model_names[i]), &(this->st_model_names), sizeof(char*));
      }
      union {
        bool real;
        uint8_t base;
      } u_rendering_enabled;
      u_rendering_enabled.base = 0;
      u_rendering_enabled.base |= ((uint8_t) (*(inbuffer + offset + 0))) << (8 * 0);
      this->rendering_enabled = u_rendering_enabled.real;
      offset += sizeof(this->rendering_enabled);
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

    const char * getType(){ return GETWORLDPROPERTIES; };
    const char * getMD5(){ return "36bb0f2eccf4d8be971410c22818ba3f"; };

  };

  class GetWorldProperties {
    public:
    typedef GetWorldPropertiesRequest Request;
    typedef GetWorldPropertiesResponse Response;
  };

}
#endif
