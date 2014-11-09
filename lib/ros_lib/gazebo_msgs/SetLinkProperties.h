#ifndef _ROS_SERVICE_SetLinkProperties_h
#define _ROS_SERVICE_SetLinkProperties_h
#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"
#include "geometry_msgs/Pose.h"

namespace gazebo_msgs
{

static const char SETLINKPROPERTIES[] = "gazebo_msgs/SetLinkProperties";

  class SetLinkPropertiesRequest : public ros::Msg
  {
    public:
      const char* link_name;
      geometry_msgs::Pose com;
      bool gravity_mode;
      float mass;
      float ixx;
      float ixy;
      float ixz;
      float iyy;
      float iyz;
      float izz;

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      uint32_t length_link_name = strlen(this->link_name);
      memcpy(outbuffer + offset, &length_link_name, sizeof(uint32_t));
      offset += 4;
      memcpy(outbuffer + offset, this->link_name, length_link_name);
      offset += length_link_name;
      offset += this->com.serialize(outbuffer + offset);
      union {
        bool real;
        uint8_t base;
      } u_gravity_mode;
      u_gravity_mode.real = this->gravity_mode;
      *(outbuffer + offset + 0) = (u_gravity_mode.base >> (8 * 0)) & 0xFF;
      offset += sizeof(this->gravity_mode);
      int32_t * val_mass = (int32_t *) &(this->mass);
      int32_t exp_mass = (((*val_mass)>>23)&255);
      if(exp_mass != 0)
        exp_mass += 1023-127;
      int32_t sig_mass = *val_mass;
      *(outbuffer + offset++) = 0;
      *(outbuffer + offset++) = 0;
      *(outbuffer + offset++) = 0;
      *(outbuffer + offset++) = (sig_mass<<5) & 0xff;
      *(outbuffer + offset++) = (sig_mass>>3) & 0xff;
      *(outbuffer + offset++) = (sig_mass>>11) & 0xff;
      *(outbuffer + offset++) = ((exp_mass<<4) & 0xF0) | ((sig_mass>>19)&0x0F);
      *(outbuffer + offset++) = (exp_mass>>4) & 0x7F;
      if(this->mass < 0) *(outbuffer + offset -1) |= 0x80;
      int32_t * val_ixx = (int32_t *) &(this->ixx);
      int32_t exp_ixx = (((*val_ixx)>>23)&255);
      if(exp_ixx != 0)
        exp_ixx += 1023-127;
      int32_t sig_ixx = *val_ixx;
      *(outbuffer + offset++) = 0;
      *(outbuffer + offset++) = 0;
      *(outbuffer + offset++) = 0;
      *(outbuffer + offset++) = (sig_ixx<<5) & 0xff;
      *(outbuffer + offset++) = (sig_ixx>>3) & 0xff;
      *(outbuffer + offset++) = (sig_ixx>>11) & 0xff;
      *(outbuffer + offset++) = ((exp_ixx<<4) & 0xF0) | ((sig_ixx>>19)&0x0F);
      *(outbuffer + offset++) = (exp_ixx>>4) & 0x7F;
      if(this->ixx < 0) *(outbuffer + offset -1) |= 0x80;
      int32_t * val_ixy = (int32_t *) &(this->ixy);
      int32_t exp_ixy = (((*val_ixy)>>23)&255);
      if(exp_ixy != 0)
        exp_ixy += 1023-127;
      int32_t sig_ixy = *val_ixy;
      *(outbuffer + offset++) = 0;
      *(outbuffer + offset++) = 0;
      *(outbuffer + offset++) = 0;
      *(outbuffer + offset++) = (sig_ixy<<5) & 0xff;
      *(outbuffer + offset++) = (sig_ixy>>3) & 0xff;
      *(outbuffer + offset++) = (sig_ixy>>11) & 0xff;
      *(outbuffer + offset++) = ((exp_ixy<<4) & 0xF0) | ((sig_ixy>>19)&0x0F);
      *(outbuffer + offset++) = (exp_ixy>>4) & 0x7F;
      if(this->ixy < 0) *(outbuffer + offset -1) |= 0x80;
      int32_t * val_ixz = (int32_t *) &(this->ixz);
      int32_t exp_ixz = (((*val_ixz)>>23)&255);
      if(exp_ixz != 0)
        exp_ixz += 1023-127;
      int32_t sig_ixz = *val_ixz;
      *(outbuffer + offset++) = 0;
      *(outbuffer + offset++) = 0;
      *(outbuffer + offset++) = 0;
      *(outbuffer + offset++) = (sig_ixz<<5) & 0xff;
      *(outbuffer + offset++) = (sig_ixz>>3) & 0xff;
      *(outbuffer + offset++) = (sig_ixz>>11) & 0xff;
      *(outbuffer + offset++) = ((exp_ixz<<4) & 0xF0) | ((sig_ixz>>19)&0x0F);
      *(outbuffer + offset++) = (exp_ixz>>4) & 0x7F;
      if(this->ixz < 0) *(outbuffer + offset -1) |= 0x80;
      int32_t * val_iyy = (int32_t *) &(this->iyy);
      int32_t exp_iyy = (((*val_iyy)>>23)&255);
      if(exp_iyy != 0)
        exp_iyy += 1023-127;
      int32_t sig_iyy = *val_iyy;
      *(outbuffer + offset++) = 0;
      *(outbuffer + offset++) = 0;
      *(outbuffer + offset++) = 0;
      *(outbuffer + offset++) = (sig_iyy<<5) & 0xff;
      *(outbuffer + offset++) = (sig_iyy>>3) & 0xff;
      *(outbuffer + offset++) = (sig_iyy>>11) & 0xff;
      *(outbuffer + offset++) = ((exp_iyy<<4) & 0xF0) | ((sig_iyy>>19)&0x0F);
      *(outbuffer + offset++) = (exp_iyy>>4) & 0x7F;
      if(this->iyy < 0) *(outbuffer + offset -1) |= 0x80;
      int32_t * val_iyz = (int32_t *) &(this->iyz);
      int32_t exp_iyz = (((*val_iyz)>>23)&255);
      if(exp_iyz != 0)
        exp_iyz += 1023-127;
      int32_t sig_iyz = *val_iyz;
      *(outbuffer + offset++) = 0;
      *(outbuffer + offset++) = 0;
      *(outbuffer + offset++) = 0;
      *(outbuffer + offset++) = (sig_iyz<<5) & 0xff;
      *(outbuffer + offset++) = (sig_iyz>>3) & 0xff;
      *(outbuffer + offset++) = (sig_iyz>>11) & 0xff;
      *(outbuffer + offset++) = ((exp_iyz<<4) & 0xF0) | ((sig_iyz>>19)&0x0F);
      *(outbuffer + offset++) = (exp_iyz>>4) & 0x7F;
      if(this->iyz < 0) *(outbuffer + offset -1) |= 0x80;
      int32_t * val_izz = (int32_t *) &(this->izz);
      int32_t exp_izz = (((*val_izz)>>23)&255);
      if(exp_izz != 0)
        exp_izz += 1023-127;
      int32_t sig_izz = *val_izz;
      *(outbuffer + offset++) = 0;
      *(outbuffer + offset++) = 0;
      *(outbuffer + offset++) = 0;
      *(outbuffer + offset++) = (sig_izz<<5) & 0xff;
      *(outbuffer + offset++) = (sig_izz>>3) & 0xff;
      *(outbuffer + offset++) = (sig_izz>>11) & 0xff;
      *(outbuffer + offset++) = ((exp_izz<<4) & 0xF0) | ((sig_izz>>19)&0x0F);
      *(outbuffer + offset++) = (exp_izz>>4) & 0x7F;
      if(this->izz < 0) *(outbuffer + offset -1) |= 0x80;
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer)
    {
      int offset = 0;
      uint32_t length_link_name;
      memcpy(&length_link_name, (inbuffer + offset), sizeof(uint32_t));
      offset += 4;
      for(unsigned int k= offset; k< offset+length_link_name; ++k){
          inbuffer[k-1]=inbuffer[k];
      }
      inbuffer[offset+length_link_name-1]=0;
      this->link_name = (char *)(inbuffer + offset-1);
      offset += length_link_name;
      offset += this->com.deserialize(inbuffer + offset);
      union {
        bool real;
        uint8_t base;
      } u_gravity_mode;
      u_gravity_mode.base = 0;
      u_gravity_mode.base |= ((uint8_t) (*(inbuffer + offset + 0))) << (8 * 0);
      this->gravity_mode = u_gravity_mode.real;
      offset += sizeof(this->gravity_mode);
      uint32_t * val_mass = (uint32_t*) &(this->mass);
      offset += 3;
      *val_mass = ((uint32_t)(*(inbuffer + offset++))>>5 & 0x07);
      *val_mass |= ((uint32_t)(*(inbuffer + offset++)) & 0xff)<<3;
      *val_mass |= ((uint32_t)(*(inbuffer + offset++)) & 0xff)<<11;
      *val_mass |= ((uint32_t)(*(inbuffer + offset)) & 0x0f)<<19;
      uint32_t exp_mass = ((uint32_t)(*(inbuffer + offset++))&0xf0)>>4;
      exp_mass |= ((uint32_t)(*(inbuffer + offset)) & 0x7f)<<4;
      if(exp_mass !=0)
        *val_mass |= ((exp_mass)-1023+127)<<23;
      if( ((*(inbuffer+offset++)) & 0x80) > 0) this->mass = -this->mass;
      uint32_t * val_ixx = (uint32_t*) &(this->ixx);
      offset += 3;
      *val_ixx = ((uint32_t)(*(inbuffer + offset++))>>5 & 0x07);
      *val_ixx |= ((uint32_t)(*(inbuffer + offset++)) & 0xff)<<3;
      *val_ixx |= ((uint32_t)(*(inbuffer + offset++)) & 0xff)<<11;
      *val_ixx |= ((uint32_t)(*(inbuffer + offset)) & 0x0f)<<19;
      uint32_t exp_ixx = ((uint32_t)(*(inbuffer + offset++))&0xf0)>>4;
      exp_ixx |= ((uint32_t)(*(inbuffer + offset)) & 0x7f)<<4;
      if(exp_ixx !=0)
        *val_ixx |= ((exp_ixx)-1023+127)<<23;
      if( ((*(inbuffer+offset++)) & 0x80) > 0) this->ixx = -this->ixx;
      uint32_t * val_ixy = (uint32_t*) &(this->ixy);
      offset += 3;
      *val_ixy = ((uint32_t)(*(inbuffer + offset++))>>5 & 0x07);
      *val_ixy |= ((uint32_t)(*(inbuffer + offset++)) & 0xff)<<3;
      *val_ixy |= ((uint32_t)(*(inbuffer + offset++)) & 0xff)<<11;
      *val_ixy |= ((uint32_t)(*(inbuffer + offset)) & 0x0f)<<19;
      uint32_t exp_ixy = ((uint32_t)(*(inbuffer + offset++))&0xf0)>>4;
      exp_ixy |= ((uint32_t)(*(inbuffer + offset)) & 0x7f)<<4;
      if(exp_ixy !=0)
        *val_ixy |= ((exp_ixy)-1023+127)<<23;
      if( ((*(inbuffer+offset++)) & 0x80) > 0) this->ixy = -this->ixy;
      uint32_t * val_ixz = (uint32_t*) &(this->ixz);
      offset += 3;
      *val_ixz = ((uint32_t)(*(inbuffer + offset++))>>5 & 0x07);
      *val_ixz |= ((uint32_t)(*(inbuffer + offset++)) & 0xff)<<3;
      *val_ixz |= ((uint32_t)(*(inbuffer + offset++)) & 0xff)<<11;
      *val_ixz |= ((uint32_t)(*(inbuffer + offset)) & 0x0f)<<19;
      uint32_t exp_ixz = ((uint32_t)(*(inbuffer + offset++))&0xf0)>>4;
      exp_ixz |= ((uint32_t)(*(inbuffer + offset)) & 0x7f)<<4;
      if(exp_ixz !=0)
        *val_ixz |= ((exp_ixz)-1023+127)<<23;
      if( ((*(inbuffer+offset++)) & 0x80) > 0) this->ixz = -this->ixz;
      uint32_t * val_iyy = (uint32_t*) &(this->iyy);
      offset += 3;
      *val_iyy = ((uint32_t)(*(inbuffer + offset++))>>5 & 0x07);
      *val_iyy |= ((uint32_t)(*(inbuffer + offset++)) & 0xff)<<3;
      *val_iyy |= ((uint32_t)(*(inbuffer + offset++)) & 0xff)<<11;
      *val_iyy |= ((uint32_t)(*(inbuffer + offset)) & 0x0f)<<19;
      uint32_t exp_iyy = ((uint32_t)(*(inbuffer + offset++))&0xf0)>>4;
      exp_iyy |= ((uint32_t)(*(inbuffer + offset)) & 0x7f)<<4;
      if(exp_iyy !=0)
        *val_iyy |= ((exp_iyy)-1023+127)<<23;
      if( ((*(inbuffer+offset++)) & 0x80) > 0) this->iyy = -this->iyy;
      uint32_t * val_iyz = (uint32_t*) &(this->iyz);
      offset += 3;
      *val_iyz = ((uint32_t)(*(inbuffer + offset++))>>5 & 0x07);
      *val_iyz |= ((uint32_t)(*(inbuffer + offset++)) & 0xff)<<3;
      *val_iyz |= ((uint32_t)(*(inbuffer + offset++)) & 0xff)<<11;
      *val_iyz |= ((uint32_t)(*(inbuffer + offset)) & 0x0f)<<19;
      uint32_t exp_iyz = ((uint32_t)(*(inbuffer + offset++))&0xf0)>>4;
      exp_iyz |= ((uint32_t)(*(inbuffer + offset)) & 0x7f)<<4;
      if(exp_iyz !=0)
        *val_iyz |= ((exp_iyz)-1023+127)<<23;
      if( ((*(inbuffer+offset++)) & 0x80) > 0) this->iyz = -this->iyz;
      uint32_t * val_izz = (uint32_t*) &(this->izz);
      offset += 3;
      *val_izz = ((uint32_t)(*(inbuffer + offset++))>>5 & 0x07);
      *val_izz |= ((uint32_t)(*(inbuffer + offset++)) & 0xff)<<3;
      *val_izz |= ((uint32_t)(*(inbuffer + offset++)) & 0xff)<<11;
      *val_izz |= ((uint32_t)(*(inbuffer + offset)) & 0x0f)<<19;
      uint32_t exp_izz = ((uint32_t)(*(inbuffer + offset++))&0xf0)>>4;
      exp_izz |= ((uint32_t)(*(inbuffer + offset)) & 0x7f)<<4;
      if(exp_izz !=0)
        *val_izz |= ((exp_izz)-1023+127)<<23;
      if( ((*(inbuffer+offset++)) & 0x80) > 0) this->izz = -this->izz;
     return offset;
    }

    const char * getType(){ return SETLINKPROPERTIES; };
    const char * getMD5(){ return "68ac74a4be01b165bc305b5ccdc45e91"; };

  };

  class SetLinkPropertiesResponse : public ros::Msg
  {
    public:
      bool success;
      const char* status_message;

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
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

    const char * getType(){ return SETLINKPROPERTIES; };
    const char * getMD5(){ return "2ec6f3eff0161f4257b808b12bc830c2"; };

  };

  class SetLinkProperties {
    public:
    typedef SetLinkPropertiesRequest Request;
    typedef SetLinkPropertiesResponse Response;
  };

}
#endif
