#ifndef _ROS_gazebo_msgs_ODEPhysics_h
#define _ROS_gazebo_msgs_ODEPhysics_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"

namespace gazebo_msgs
{

  class ODEPhysics : public ros::Msg
  {
    public:
      bool auto_disable_bodies;
      uint32_t sor_pgs_precon_iters;
      uint32_t sor_pgs_iters;
      float sor_pgs_w;
      float sor_pgs_rms_error_tol;
      float contact_surface_layer;
      float contact_max_correcting_vel;
      float cfm;
      float erp;
      uint32_t max_contacts;

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      union {
        bool real;
        uint8_t base;
      } u_auto_disable_bodies;
      u_auto_disable_bodies.real = this->auto_disable_bodies;
      *(outbuffer + offset + 0) = (u_auto_disable_bodies.base >> (8 * 0)) & 0xFF;
      offset += sizeof(this->auto_disable_bodies);
      *(outbuffer + offset + 0) = (this->sor_pgs_precon_iters >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (this->sor_pgs_precon_iters >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (this->sor_pgs_precon_iters >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (this->sor_pgs_precon_iters >> (8 * 3)) & 0xFF;
      offset += sizeof(this->sor_pgs_precon_iters);
      *(outbuffer + offset + 0) = (this->sor_pgs_iters >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (this->sor_pgs_iters >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (this->sor_pgs_iters >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (this->sor_pgs_iters >> (8 * 3)) & 0xFF;
      offset += sizeof(this->sor_pgs_iters);
      int32_t * val_sor_pgs_w = (int32_t *) &(this->sor_pgs_w);
      int32_t exp_sor_pgs_w = (((*val_sor_pgs_w)>>23)&255);
      if(exp_sor_pgs_w != 0)
        exp_sor_pgs_w += 1023-127;
      int32_t sig_sor_pgs_w = *val_sor_pgs_w;
      *(outbuffer + offset++) = 0;
      *(outbuffer + offset++) = 0;
      *(outbuffer + offset++) = 0;
      *(outbuffer + offset++) = (sig_sor_pgs_w<<5) & 0xff;
      *(outbuffer + offset++) = (sig_sor_pgs_w>>3) & 0xff;
      *(outbuffer + offset++) = (sig_sor_pgs_w>>11) & 0xff;
      *(outbuffer + offset++) = ((exp_sor_pgs_w<<4) & 0xF0) | ((sig_sor_pgs_w>>19)&0x0F);
      *(outbuffer + offset++) = (exp_sor_pgs_w>>4) & 0x7F;
      if(this->sor_pgs_w < 0) *(outbuffer + offset -1) |= 0x80;
      int32_t * val_sor_pgs_rms_error_tol = (int32_t *) &(this->sor_pgs_rms_error_tol);
      int32_t exp_sor_pgs_rms_error_tol = (((*val_sor_pgs_rms_error_tol)>>23)&255);
      if(exp_sor_pgs_rms_error_tol != 0)
        exp_sor_pgs_rms_error_tol += 1023-127;
      int32_t sig_sor_pgs_rms_error_tol = *val_sor_pgs_rms_error_tol;
      *(outbuffer + offset++) = 0;
      *(outbuffer + offset++) = 0;
      *(outbuffer + offset++) = 0;
      *(outbuffer + offset++) = (sig_sor_pgs_rms_error_tol<<5) & 0xff;
      *(outbuffer + offset++) = (sig_sor_pgs_rms_error_tol>>3) & 0xff;
      *(outbuffer + offset++) = (sig_sor_pgs_rms_error_tol>>11) & 0xff;
      *(outbuffer + offset++) = ((exp_sor_pgs_rms_error_tol<<4) & 0xF0) | ((sig_sor_pgs_rms_error_tol>>19)&0x0F);
      *(outbuffer + offset++) = (exp_sor_pgs_rms_error_tol>>4) & 0x7F;
      if(this->sor_pgs_rms_error_tol < 0) *(outbuffer + offset -1) |= 0x80;
      int32_t * val_contact_surface_layer = (int32_t *) &(this->contact_surface_layer);
      int32_t exp_contact_surface_layer = (((*val_contact_surface_layer)>>23)&255);
      if(exp_contact_surface_layer != 0)
        exp_contact_surface_layer += 1023-127;
      int32_t sig_contact_surface_layer = *val_contact_surface_layer;
      *(outbuffer + offset++) = 0;
      *(outbuffer + offset++) = 0;
      *(outbuffer + offset++) = 0;
      *(outbuffer + offset++) = (sig_contact_surface_layer<<5) & 0xff;
      *(outbuffer + offset++) = (sig_contact_surface_layer>>3) & 0xff;
      *(outbuffer + offset++) = (sig_contact_surface_layer>>11) & 0xff;
      *(outbuffer + offset++) = ((exp_contact_surface_layer<<4) & 0xF0) | ((sig_contact_surface_layer>>19)&0x0F);
      *(outbuffer + offset++) = (exp_contact_surface_layer>>4) & 0x7F;
      if(this->contact_surface_layer < 0) *(outbuffer + offset -1) |= 0x80;
      int32_t * val_contact_max_correcting_vel = (int32_t *) &(this->contact_max_correcting_vel);
      int32_t exp_contact_max_correcting_vel = (((*val_contact_max_correcting_vel)>>23)&255);
      if(exp_contact_max_correcting_vel != 0)
        exp_contact_max_correcting_vel += 1023-127;
      int32_t sig_contact_max_correcting_vel = *val_contact_max_correcting_vel;
      *(outbuffer + offset++) = 0;
      *(outbuffer + offset++) = 0;
      *(outbuffer + offset++) = 0;
      *(outbuffer + offset++) = (sig_contact_max_correcting_vel<<5) & 0xff;
      *(outbuffer + offset++) = (sig_contact_max_correcting_vel>>3) & 0xff;
      *(outbuffer + offset++) = (sig_contact_max_correcting_vel>>11) & 0xff;
      *(outbuffer + offset++) = ((exp_contact_max_correcting_vel<<4) & 0xF0) | ((sig_contact_max_correcting_vel>>19)&0x0F);
      *(outbuffer + offset++) = (exp_contact_max_correcting_vel>>4) & 0x7F;
      if(this->contact_max_correcting_vel < 0) *(outbuffer + offset -1) |= 0x80;
      int32_t * val_cfm = (int32_t *) &(this->cfm);
      int32_t exp_cfm = (((*val_cfm)>>23)&255);
      if(exp_cfm != 0)
        exp_cfm += 1023-127;
      int32_t sig_cfm = *val_cfm;
      *(outbuffer + offset++) = 0;
      *(outbuffer + offset++) = 0;
      *(outbuffer + offset++) = 0;
      *(outbuffer + offset++) = (sig_cfm<<5) & 0xff;
      *(outbuffer + offset++) = (sig_cfm>>3) & 0xff;
      *(outbuffer + offset++) = (sig_cfm>>11) & 0xff;
      *(outbuffer + offset++) = ((exp_cfm<<4) & 0xF0) | ((sig_cfm>>19)&0x0F);
      *(outbuffer + offset++) = (exp_cfm>>4) & 0x7F;
      if(this->cfm < 0) *(outbuffer + offset -1) |= 0x80;
      int32_t * val_erp = (int32_t *) &(this->erp);
      int32_t exp_erp = (((*val_erp)>>23)&255);
      if(exp_erp != 0)
        exp_erp += 1023-127;
      int32_t sig_erp = *val_erp;
      *(outbuffer + offset++) = 0;
      *(outbuffer + offset++) = 0;
      *(outbuffer + offset++) = 0;
      *(outbuffer + offset++) = (sig_erp<<5) & 0xff;
      *(outbuffer + offset++) = (sig_erp>>3) & 0xff;
      *(outbuffer + offset++) = (sig_erp>>11) & 0xff;
      *(outbuffer + offset++) = ((exp_erp<<4) & 0xF0) | ((sig_erp>>19)&0x0F);
      *(outbuffer + offset++) = (exp_erp>>4) & 0x7F;
      if(this->erp < 0) *(outbuffer + offset -1) |= 0x80;
      *(outbuffer + offset + 0) = (this->max_contacts >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (this->max_contacts >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (this->max_contacts >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (this->max_contacts >> (8 * 3)) & 0xFF;
      offset += sizeof(this->max_contacts);
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer)
    {
      int offset = 0;
      union {
        bool real;
        uint8_t base;
      } u_auto_disable_bodies;
      u_auto_disable_bodies.base = 0;
      u_auto_disable_bodies.base |= ((uint8_t) (*(inbuffer + offset + 0))) << (8 * 0);
      this->auto_disable_bodies = u_auto_disable_bodies.real;
      offset += sizeof(this->auto_disable_bodies);
      this->sor_pgs_precon_iters =  ((uint32_t) (*(inbuffer + offset)));
      this->sor_pgs_precon_iters |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      this->sor_pgs_precon_iters |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      this->sor_pgs_precon_iters |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      offset += sizeof(this->sor_pgs_precon_iters);
      this->sor_pgs_iters =  ((uint32_t) (*(inbuffer + offset)));
      this->sor_pgs_iters |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      this->sor_pgs_iters |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      this->sor_pgs_iters |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      offset += sizeof(this->sor_pgs_iters);
      uint32_t * val_sor_pgs_w = (uint32_t*) &(this->sor_pgs_w);
      offset += 3;
      *val_sor_pgs_w = ((uint32_t)(*(inbuffer + offset++))>>5 & 0x07);
      *val_sor_pgs_w |= ((uint32_t)(*(inbuffer + offset++)) & 0xff)<<3;
      *val_sor_pgs_w |= ((uint32_t)(*(inbuffer + offset++)) & 0xff)<<11;
      *val_sor_pgs_w |= ((uint32_t)(*(inbuffer + offset)) & 0x0f)<<19;
      uint32_t exp_sor_pgs_w = ((uint32_t)(*(inbuffer + offset++))&0xf0)>>4;
      exp_sor_pgs_w |= ((uint32_t)(*(inbuffer + offset)) & 0x7f)<<4;
      if(exp_sor_pgs_w !=0)
        *val_sor_pgs_w |= ((exp_sor_pgs_w)-1023+127)<<23;
      if( ((*(inbuffer+offset++)) & 0x80) > 0) this->sor_pgs_w = -this->sor_pgs_w;
      uint32_t * val_sor_pgs_rms_error_tol = (uint32_t*) &(this->sor_pgs_rms_error_tol);
      offset += 3;
      *val_sor_pgs_rms_error_tol = ((uint32_t)(*(inbuffer + offset++))>>5 & 0x07);
      *val_sor_pgs_rms_error_tol |= ((uint32_t)(*(inbuffer + offset++)) & 0xff)<<3;
      *val_sor_pgs_rms_error_tol |= ((uint32_t)(*(inbuffer + offset++)) & 0xff)<<11;
      *val_sor_pgs_rms_error_tol |= ((uint32_t)(*(inbuffer + offset)) & 0x0f)<<19;
      uint32_t exp_sor_pgs_rms_error_tol = ((uint32_t)(*(inbuffer + offset++))&0xf0)>>4;
      exp_sor_pgs_rms_error_tol |= ((uint32_t)(*(inbuffer + offset)) & 0x7f)<<4;
      if(exp_sor_pgs_rms_error_tol !=0)
        *val_sor_pgs_rms_error_tol |= ((exp_sor_pgs_rms_error_tol)-1023+127)<<23;
      if( ((*(inbuffer+offset++)) & 0x80) > 0) this->sor_pgs_rms_error_tol = -this->sor_pgs_rms_error_tol;
      uint32_t * val_contact_surface_layer = (uint32_t*) &(this->contact_surface_layer);
      offset += 3;
      *val_contact_surface_layer = ((uint32_t)(*(inbuffer + offset++))>>5 & 0x07);
      *val_contact_surface_layer |= ((uint32_t)(*(inbuffer + offset++)) & 0xff)<<3;
      *val_contact_surface_layer |= ((uint32_t)(*(inbuffer + offset++)) & 0xff)<<11;
      *val_contact_surface_layer |= ((uint32_t)(*(inbuffer + offset)) & 0x0f)<<19;
      uint32_t exp_contact_surface_layer = ((uint32_t)(*(inbuffer + offset++))&0xf0)>>4;
      exp_contact_surface_layer |= ((uint32_t)(*(inbuffer + offset)) & 0x7f)<<4;
      if(exp_contact_surface_layer !=0)
        *val_contact_surface_layer |= ((exp_contact_surface_layer)-1023+127)<<23;
      if( ((*(inbuffer+offset++)) & 0x80) > 0) this->contact_surface_layer = -this->contact_surface_layer;
      uint32_t * val_contact_max_correcting_vel = (uint32_t*) &(this->contact_max_correcting_vel);
      offset += 3;
      *val_contact_max_correcting_vel = ((uint32_t)(*(inbuffer + offset++))>>5 & 0x07);
      *val_contact_max_correcting_vel |= ((uint32_t)(*(inbuffer + offset++)) & 0xff)<<3;
      *val_contact_max_correcting_vel |= ((uint32_t)(*(inbuffer + offset++)) & 0xff)<<11;
      *val_contact_max_correcting_vel |= ((uint32_t)(*(inbuffer + offset)) & 0x0f)<<19;
      uint32_t exp_contact_max_correcting_vel = ((uint32_t)(*(inbuffer + offset++))&0xf0)>>4;
      exp_contact_max_correcting_vel |= ((uint32_t)(*(inbuffer + offset)) & 0x7f)<<4;
      if(exp_contact_max_correcting_vel !=0)
        *val_contact_max_correcting_vel |= ((exp_contact_max_correcting_vel)-1023+127)<<23;
      if( ((*(inbuffer+offset++)) & 0x80) > 0) this->contact_max_correcting_vel = -this->contact_max_correcting_vel;
      uint32_t * val_cfm = (uint32_t*) &(this->cfm);
      offset += 3;
      *val_cfm = ((uint32_t)(*(inbuffer + offset++))>>5 & 0x07);
      *val_cfm |= ((uint32_t)(*(inbuffer + offset++)) & 0xff)<<3;
      *val_cfm |= ((uint32_t)(*(inbuffer + offset++)) & 0xff)<<11;
      *val_cfm |= ((uint32_t)(*(inbuffer + offset)) & 0x0f)<<19;
      uint32_t exp_cfm = ((uint32_t)(*(inbuffer + offset++))&0xf0)>>4;
      exp_cfm |= ((uint32_t)(*(inbuffer + offset)) & 0x7f)<<4;
      if(exp_cfm !=0)
        *val_cfm |= ((exp_cfm)-1023+127)<<23;
      if( ((*(inbuffer+offset++)) & 0x80) > 0) this->cfm = -this->cfm;
      uint32_t * val_erp = (uint32_t*) &(this->erp);
      offset += 3;
      *val_erp = ((uint32_t)(*(inbuffer + offset++))>>5 & 0x07);
      *val_erp |= ((uint32_t)(*(inbuffer + offset++)) & 0xff)<<3;
      *val_erp |= ((uint32_t)(*(inbuffer + offset++)) & 0xff)<<11;
      *val_erp |= ((uint32_t)(*(inbuffer + offset)) & 0x0f)<<19;
      uint32_t exp_erp = ((uint32_t)(*(inbuffer + offset++))&0xf0)>>4;
      exp_erp |= ((uint32_t)(*(inbuffer + offset)) & 0x7f)<<4;
      if(exp_erp !=0)
        *val_erp |= ((exp_erp)-1023+127)<<23;
      if( ((*(inbuffer+offset++)) & 0x80) > 0) this->erp = -this->erp;
      this->max_contacts =  ((uint32_t) (*(inbuffer + offset)));
      this->max_contacts |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      this->max_contacts |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      this->max_contacts |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      offset += sizeof(this->max_contacts);
     return offset;
    }

    const char * getType(){ return "gazebo_msgs/ODEPhysics"; };
    const char * getMD5(){ return "667d56ddbd547918c32d1934503dc335"; };

  };

}
#endif