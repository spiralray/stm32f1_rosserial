#ifndef _ROS_SERVICE_GetJointProperties_h
#define _ROS_SERVICE_GetJointProperties_h
#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"

namespace gazebo_msgs
{

static const char GETJOINTPROPERTIES[] = "gazebo_msgs/GetJointProperties";

  class GetJointPropertiesRequest : public ros::Msg
  {
    public:
      const char* joint_name;

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      uint32_t length_joint_name = strlen(this->joint_name);
      memcpy(outbuffer + offset, &length_joint_name, sizeof(uint32_t));
      offset += 4;
      memcpy(outbuffer + offset, this->joint_name, length_joint_name);
      offset += length_joint_name;
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer)
    {
      int offset = 0;
      uint32_t length_joint_name;
      memcpy(&length_joint_name, (inbuffer + offset), sizeof(uint32_t));
      offset += 4;
      for(unsigned int k= offset; k< offset+length_joint_name; ++k){
          inbuffer[k-1]=inbuffer[k];
      }
      inbuffer[offset+length_joint_name-1]=0;
      this->joint_name = (char *)(inbuffer + offset-1);
      offset += length_joint_name;
     return offset;
    }

    const char * getType(){ return GETJOINTPROPERTIES; };
    const char * getMD5(){ return "0be1351618e1dc030eb7959d9a4902de"; };

  };

  class GetJointPropertiesResponse : public ros::Msg
  {
    public:
      uint8_t type;
      uint8_t damping_length;
      float st_damping;
      float * damping;
      uint8_t position_length;
      float st_position;
      float * position;
      uint8_t rate_length;
      float st_rate;
      float * rate;
      bool success;
      const char* status_message;
      enum { REVOLUTE =  0                 };
      enum { CONTINUOUS =  1                 };
      enum { PRISMATIC =  2                 };
      enum { FIXED =  3                 };
      enum { BALL =  4                 };
      enum { UNIVERSAL =  5                 };

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      *(outbuffer + offset + 0) = (this->type >> (8 * 0)) & 0xFF;
      offset += sizeof(this->type);
      *(outbuffer + offset++) = damping_length;
      *(outbuffer + offset++) = 0;
      *(outbuffer + offset++) = 0;
      *(outbuffer + offset++) = 0;
      for( uint8_t i = 0; i < damping_length; i++){
      int32_t * val_dampingi = (int32_t *) &(this->damping[i]);
      int32_t exp_dampingi = (((*val_dampingi)>>23)&255);
      if(exp_dampingi != 0)
        exp_dampingi += 1023-127;
      int32_t sig_dampingi = *val_dampingi;
      *(outbuffer + offset++) = 0;
      *(outbuffer + offset++) = 0;
      *(outbuffer + offset++) = 0;
      *(outbuffer + offset++) = (sig_dampingi<<5) & 0xff;
      *(outbuffer + offset++) = (sig_dampingi>>3) & 0xff;
      *(outbuffer + offset++) = (sig_dampingi>>11) & 0xff;
      *(outbuffer + offset++) = ((exp_dampingi<<4) & 0xF0) | ((sig_dampingi>>19)&0x0F);
      *(outbuffer + offset++) = (exp_dampingi>>4) & 0x7F;
      if(this->damping[i] < 0) *(outbuffer + offset -1) |= 0x80;
      }
      *(outbuffer + offset++) = position_length;
      *(outbuffer + offset++) = 0;
      *(outbuffer + offset++) = 0;
      *(outbuffer + offset++) = 0;
      for( uint8_t i = 0; i < position_length; i++){
      int32_t * val_positioni = (int32_t *) &(this->position[i]);
      int32_t exp_positioni = (((*val_positioni)>>23)&255);
      if(exp_positioni != 0)
        exp_positioni += 1023-127;
      int32_t sig_positioni = *val_positioni;
      *(outbuffer + offset++) = 0;
      *(outbuffer + offset++) = 0;
      *(outbuffer + offset++) = 0;
      *(outbuffer + offset++) = (sig_positioni<<5) & 0xff;
      *(outbuffer + offset++) = (sig_positioni>>3) & 0xff;
      *(outbuffer + offset++) = (sig_positioni>>11) & 0xff;
      *(outbuffer + offset++) = ((exp_positioni<<4) & 0xF0) | ((sig_positioni>>19)&0x0F);
      *(outbuffer + offset++) = (exp_positioni>>4) & 0x7F;
      if(this->position[i] < 0) *(outbuffer + offset -1) |= 0x80;
      }
      *(outbuffer + offset++) = rate_length;
      *(outbuffer + offset++) = 0;
      *(outbuffer + offset++) = 0;
      *(outbuffer + offset++) = 0;
      for( uint8_t i = 0; i < rate_length; i++){
      int32_t * val_ratei = (int32_t *) &(this->rate[i]);
      int32_t exp_ratei = (((*val_ratei)>>23)&255);
      if(exp_ratei != 0)
        exp_ratei += 1023-127;
      int32_t sig_ratei = *val_ratei;
      *(outbuffer + offset++) = 0;
      *(outbuffer + offset++) = 0;
      *(outbuffer + offset++) = 0;
      *(outbuffer + offset++) = (sig_ratei<<5) & 0xff;
      *(outbuffer + offset++) = (sig_ratei>>3) & 0xff;
      *(outbuffer + offset++) = (sig_ratei>>11) & 0xff;
      *(outbuffer + offset++) = ((exp_ratei<<4) & 0xF0) | ((sig_ratei>>19)&0x0F);
      *(outbuffer + offset++) = (exp_ratei>>4) & 0x7F;
      if(this->rate[i] < 0) *(outbuffer + offset -1) |= 0x80;
      }
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
      this->type =  ((uint8_t) (*(inbuffer + offset)));
      offset += sizeof(this->type);
      uint8_t damping_lengthT = *(inbuffer + offset++);
      if(damping_lengthT > damping_length)
        this->damping = (float*)realloc(this->damping, damping_lengthT * sizeof(float));
      offset += 3;
      damping_length = damping_lengthT;
      for( uint8_t i = 0; i < damping_length; i++){
      uint32_t * val_st_damping = (uint32_t*) &(this->st_damping);
      offset += 3;
      *val_st_damping = ((uint32_t)(*(inbuffer + offset++))>>5 & 0x07);
      *val_st_damping |= ((uint32_t)(*(inbuffer + offset++)) & 0xff)<<3;
      *val_st_damping |= ((uint32_t)(*(inbuffer + offset++)) & 0xff)<<11;
      *val_st_damping |= ((uint32_t)(*(inbuffer + offset)) & 0x0f)<<19;
      uint32_t exp_st_damping = ((uint32_t)(*(inbuffer + offset++))&0xf0)>>4;
      exp_st_damping |= ((uint32_t)(*(inbuffer + offset)) & 0x7f)<<4;
      if(exp_st_damping !=0)
        *val_st_damping |= ((exp_st_damping)-1023+127)<<23;
      if( ((*(inbuffer+offset++)) & 0x80) > 0) this->st_damping = -this->st_damping;
        memcpy( &(this->damping[i]), &(this->st_damping), sizeof(float));
      }
      uint8_t position_lengthT = *(inbuffer + offset++);
      if(position_lengthT > position_length)
        this->position = (float*)realloc(this->position, position_lengthT * sizeof(float));
      offset += 3;
      position_length = position_lengthT;
      for( uint8_t i = 0; i < position_length; i++){
      uint32_t * val_st_position = (uint32_t*) &(this->st_position);
      offset += 3;
      *val_st_position = ((uint32_t)(*(inbuffer + offset++))>>5 & 0x07);
      *val_st_position |= ((uint32_t)(*(inbuffer + offset++)) & 0xff)<<3;
      *val_st_position |= ((uint32_t)(*(inbuffer + offset++)) & 0xff)<<11;
      *val_st_position |= ((uint32_t)(*(inbuffer + offset)) & 0x0f)<<19;
      uint32_t exp_st_position = ((uint32_t)(*(inbuffer + offset++))&0xf0)>>4;
      exp_st_position |= ((uint32_t)(*(inbuffer + offset)) & 0x7f)<<4;
      if(exp_st_position !=0)
        *val_st_position |= ((exp_st_position)-1023+127)<<23;
      if( ((*(inbuffer+offset++)) & 0x80) > 0) this->st_position = -this->st_position;
        memcpy( &(this->position[i]), &(this->st_position), sizeof(float));
      }
      uint8_t rate_lengthT = *(inbuffer + offset++);
      if(rate_lengthT > rate_length)
        this->rate = (float*)realloc(this->rate, rate_lengthT * sizeof(float));
      offset += 3;
      rate_length = rate_lengthT;
      for( uint8_t i = 0; i < rate_length; i++){
      uint32_t * val_st_rate = (uint32_t*) &(this->st_rate);
      offset += 3;
      *val_st_rate = ((uint32_t)(*(inbuffer + offset++))>>5 & 0x07);
      *val_st_rate |= ((uint32_t)(*(inbuffer + offset++)) & 0xff)<<3;
      *val_st_rate |= ((uint32_t)(*(inbuffer + offset++)) & 0xff)<<11;
      *val_st_rate |= ((uint32_t)(*(inbuffer + offset)) & 0x0f)<<19;
      uint32_t exp_st_rate = ((uint32_t)(*(inbuffer + offset++))&0xf0)>>4;
      exp_st_rate |= ((uint32_t)(*(inbuffer + offset)) & 0x7f)<<4;
      if(exp_st_rate !=0)
        *val_st_rate |= ((exp_st_rate)-1023+127)<<23;
      if( ((*(inbuffer+offset++)) & 0x80) > 0) this->st_rate = -this->st_rate;
        memcpy( &(this->rate[i]), &(this->st_rate), sizeof(float));
      }
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

    const char * getType(){ return GETJOINTPROPERTIES; };
    const char * getMD5(){ return "cd7b30a39faa372283dc94c5f6457f82"; };

  };

  class GetJointProperties {
    public:
    typedef GetJointPropertiesRequest Request;
    typedef GetJointPropertiesResponse Response;
  };

}
#endif
