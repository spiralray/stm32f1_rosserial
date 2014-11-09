#ifndef _ROS_gazebo_msgs_ODEJointProperties_h
#define _ROS_gazebo_msgs_ODEJointProperties_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"

namespace gazebo_msgs
{

  class ODEJointProperties : public ros::Msg
  {
    public:
      uint8_t damping_length;
      float st_damping;
      float * damping;
      uint8_t hiStop_length;
      float st_hiStop;
      float * hiStop;
      uint8_t loStop_length;
      float st_loStop;
      float * loStop;
      uint8_t erp_length;
      float st_erp;
      float * erp;
      uint8_t cfm_length;
      float st_cfm;
      float * cfm;
      uint8_t stop_erp_length;
      float st_stop_erp;
      float * stop_erp;
      uint8_t stop_cfm_length;
      float st_stop_cfm;
      float * stop_cfm;
      uint8_t fudge_factor_length;
      float st_fudge_factor;
      float * fudge_factor;
      uint8_t fmax_length;
      float st_fmax;
      float * fmax;
      uint8_t vel_length;
      float st_vel;
      float * vel;

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
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
      *(outbuffer + offset++) = hiStop_length;
      *(outbuffer + offset++) = 0;
      *(outbuffer + offset++) = 0;
      *(outbuffer + offset++) = 0;
      for( uint8_t i = 0; i < hiStop_length; i++){
      int32_t * val_hiStopi = (int32_t *) &(this->hiStop[i]);
      int32_t exp_hiStopi = (((*val_hiStopi)>>23)&255);
      if(exp_hiStopi != 0)
        exp_hiStopi += 1023-127;
      int32_t sig_hiStopi = *val_hiStopi;
      *(outbuffer + offset++) = 0;
      *(outbuffer + offset++) = 0;
      *(outbuffer + offset++) = 0;
      *(outbuffer + offset++) = (sig_hiStopi<<5) & 0xff;
      *(outbuffer + offset++) = (sig_hiStopi>>3) & 0xff;
      *(outbuffer + offset++) = (sig_hiStopi>>11) & 0xff;
      *(outbuffer + offset++) = ((exp_hiStopi<<4) & 0xF0) | ((sig_hiStopi>>19)&0x0F);
      *(outbuffer + offset++) = (exp_hiStopi>>4) & 0x7F;
      if(this->hiStop[i] < 0) *(outbuffer + offset -1) |= 0x80;
      }
      *(outbuffer + offset++) = loStop_length;
      *(outbuffer + offset++) = 0;
      *(outbuffer + offset++) = 0;
      *(outbuffer + offset++) = 0;
      for( uint8_t i = 0; i < loStop_length; i++){
      int32_t * val_loStopi = (int32_t *) &(this->loStop[i]);
      int32_t exp_loStopi = (((*val_loStopi)>>23)&255);
      if(exp_loStopi != 0)
        exp_loStopi += 1023-127;
      int32_t sig_loStopi = *val_loStopi;
      *(outbuffer + offset++) = 0;
      *(outbuffer + offset++) = 0;
      *(outbuffer + offset++) = 0;
      *(outbuffer + offset++) = (sig_loStopi<<5) & 0xff;
      *(outbuffer + offset++) = (sig_loStopi>>3) & 0xff;
      *(outbuffer + offset++) = (sig_loStopi>>11) & 0xff;
      *(outbuffer + offset++) = ((exp_loStopi<<4) & 0xF0) | ((sig_loStopi>>19)&0x0F);
      *(outbuffer + offset++) = (exp_loStopi>>4) & 0x7F;
      if(this->loStop[i] < 0) *(outbuffer + offset -1) |= 0x80;
      }
      *(outbuffer + offset++) = erp_length;
      *(outbuffer + offset++) = 0;
      *(outbuffer + offset++) = 0;
      *(outbuffer + offset++) = 0;
      for( uint8_t i = 0; i < erp_length; i++){
      int32_t * val_erpi = (int32_t *) &(this->erp[i]);
      int32_t exp_erpi = (((*val_erpi)>>23)&255);
      if(exp_erpi != 0)
        exp_erpi += 1023-127;
      int32_t sig_erpi = *val_erpi;
      *(outbuffer + offset++) = 0;
      *(outbuffer + offset++) = 0;
      *(outbuffer + offset++) = 0;
      *(outbuffer + offset++) = (sig_erpi<<5) & 0xff;
      *(outbuffer + offset++) = (sig_erpi>>3) & 0xff;
      *(outbuffer + offset++) = (sig_erpi>>11) & 0xff;
      *(outbuffer + offset++) = ((exp_erpi<<4) & 0xF0) | ((sig_erpi>>19)&0x0F);
      *(outbuffer + offset++) = (exp_erpi>>4) & 0x7F;
      if(this->erp[i] < 0) *(outbuffer + offset -1) |= 0x80;
      }
      *(outbuffer + offset++) = cfm_length;
      *(outbuffer + offset++) = 0;
      *(outbuffer + offset++) = 0;
      *(outbuffer + offset++) = 0;
      for( uint8_t i = 0; i < cfm_length; i++){
      int32_t * val_cfmi = (int32_t *) &(this->cfm[i]);
      int32_t exp_cfmi = (((*val_cfmi)>>23)&255);
      if(exp_cfmi != 0)
        exp_cfmi += 1023-127;
      int32_t sig_cfmi = *val_cfmi;
      *(outbuffer + offset++) = 0;
      *(outbuffer + offset++) = 0;
      *(outbuffer + offset++) = 0;
      *(outbuffer + offset++) = (sig_cfmi<<5) & 0xff;
      *(outbuffer + offset++) = (sig_cfmi>>3) & 0xff;
      *(outbuffer + offset++) = (sig_cfmi>>11) & 0xff;
      *(outbuffer + offset++) = ((exp_cfmi<<4) & 0xF0) | ((sig_cfmi>>19)&0x0F);
      *(outbuffer + offset++) = (exp_cfmi>>4) & 0x7F;
      if(this->cfm[i] < 0) *(outbuffer + offset -1) |= 0x80;
      }
      *(outbuffer + offset++) = stop_erp_length;
      *(outbuffer + offset++) = 0;
      *(outbuffer + offset++) = 0;
      *(outbuffer + offset++) = 0;
      for( uint8_t i = 0; i < stop_erp_length; i++){
      int32_t * val_stop_erpi = (int32_t *) &(this->stop_erp[i]);
      int32_t exp_stop_erpi = (((*val_stop_erpi)>>23)&255);
      if(exp_stop_erpi != 0)
        exp_stop_erpi += 1023-127;
      int32_t sig_stop_erpi = *val_stop_erpi;
      *(outbuffer + offset++) = 0;
      *(outbuffer + offset++) = 0;
      *(outbuffer + offset++) = 0;
      *(outbuffer + offset++) = (sig_stop_erpi<<5) & 0xff;
      *(outbuffer + offset++) = (sig_stop_erpi>>3) & 0xff;
      *(outbuffer + offset++) = (sig_stop_erpi>>11) & 0xff;
      *(outbuffer + offset++) = ((exp_stop_erpi<<4) & 0xF0) | ((sig_stop_erpi>>19)&0x0F);
      *(outbuffer + offset++) = (exp_stop_erpi>>4) & 0x7F;
      if(this->stop_erp[i] < 0) *(outbuffer + offset -1) |= 0x80;
      }
      *(outbuffer + offset++) = stop_cfm_length;
      *(outbuffer + offset++) = 0;
      *(outbuffer + offset++) = 0;
      *(outbuffer + offset++) = 0;
      for( uint8_t i = 0; i < stop_cfm_length; i++){
      int32_t * val_stop_cfmi = (int32_t *) &(this->stop_cfm[i]);
      int32_t exp_stop_cfmi = (((*val_stop_cfmi)>>23)&255);
      if(exp_stop_cfmi != 0)
        exp_stop_cfmi += 1023-127;
      int32_t sig_stop_cfmi = *val_stop_cfmi;
      *(outbuffer + offset++) = 0;
      *(outbuffer + offset++) = 0;
      *(outbuffer + offset++) = 0;
      *(outbuffer + offset++) = (sig_stop_cfmi<<5) & 0xff;
      *(outbuffer + offset++) = (sig_stop_cfmi>>3) & 0xff;
      *(outbuffer + offset++) = (sig_stop_cfmi>>11) & 0xff;
      *(outbuffer + offset++) = ((exp_stop_cfmi<<4) & 0xF0) | ((sig_stop_cfmi>>19)&0x0F);
      *(outbuffer + offset++) = (exp_stop_cfmi>>4) & 0x7F;
      if(this->stop_cfm[i] < 0) *(outbuffer + offset -1) |= 0x80;
      }
      *(outbuffer + offset++) = fudge_factor_length;
      *(outbuffer + offset++) = 0;
      *(outbuffer + offset++) = 0;
      *(outbuffer + offset++) = 0;
      for( uint8_t i = 0; i < fudge_factor_length; i++){
      int32_t * val_fudge_factori = (int32_t *) &(this->fudge_factor[i]);
      int32_t exp_fudge_factori = (((*val_fudge_factori)>>23)&255);
      if(exp_fudge_factori != 0)
        exp_fudge_factori += 1023-127;
      int32_t sig_fudge_factori = *val_fudge_factori;
      *(outbuffer + offset++) = 0;
      *(outbuffer + offset++) = 0;
      *(outbuffer + offset++) = 0;
      *(outbuffer + offset++) = (sig_fudge_factori<<5) & 0xff;
      *(outbuffer + offset++) = (sig_fudge_factori>>3) & 0xff;
      *(outbuffer + offset++) = (sig_fudge_factori>>11) & 0xff;
      *(outbuffer + offset++) = ((exp_fudge_factori<<4) & 0xF0) | ((sig_fudge_factori>>19)&0x0F);
      *(outbuffer + offset++) = (exp_fudge_factori>>4) & 0x7F;
      if(this->fudge_factor[i] < 0) *(outbuffer + offset -1) |= 0x80;
      }
      *(outbuffer + offset++) = fmax_length;
      *(outbuffer + offset++) = 0;
      *(outbuffer + offset++) = 0;
      *(outbuffer + offset++) = 0;
      for( uint8_t i = 0; i < fmax_length; i++){
      int32_t * val_fmaxi = (int32_t *) &(this->fmax[i]);
      int32_t exp_fmaxi = (((*val_fmaxi)>>23)&255);
      if(exp_fmaxi != 0)
        exp_fmaxi += 1023-127;
      int32_t sig_fmaxi = *val_fmaxi;
      *(outbuffer + offset++) = 0;
      *(outbuffer + offset++) = 0;
      *(outbuffer + offset++) = 0;
      *(outbuffer + offset++) = (sig_fmaxi<<5) & 0xff;
      *(outbuffer + offset++) = (sig_fmaxi>>3) & 0xff;
      *(outbuffer + offset++) = (sig_fmaxi>>11) & 0xff;
      *(outbuffer + offset++) = ((exp_fmaxi<<4) & 0xF0) | ((sig_fmaxi>>19)&0x0F);
      *(outbuffer + offset++) = (exp_fmaxi>>4) & 0x7F;
      if(this->fmax[i] < 0) *(outbuffer + offset -1) |= 0x80;
      }
      *(outbuffer + offset++) = vel_length;
      *(outbuffer + offset++) = 0;
      *(outbuffer + offset++) = 0;
      *(outbuffer + offset++) = 0;
      for( uint8_t i = 0; i < vel_length; i++){
      int32_t * val_veli = (int32_t *) &(this->vel[i]);
      int32_t exp_veli = (((*val_veli)>>23)&255);
      if(exp_veli != 0)
        exp_veli += 1023-127;
      int32_t sig_veli = *val_veli;
      *(outbuffer + offset++) = 0;
      *(outbuffer + offset++) = 0;
      *(outbuffer + offset++) = 0;
      *(outbuffer + offset++) = (sig_veli<<5) & 0xff;
      *(outbuffer + offset++) = (sig_veli>>3) & 0xff;
      *(outbuffer + offset++) = (sig_veli>>11) & 0xff;
      *(outbuffer + offset++) = ((exp_veli<<4) & 0xF0) | ((sig_veli>>19)&0x0F);
      *(outbuffer + offset++) = (exp_veli>>4) & 0x7F;
      if(this->vel[i] < 0) *(outbuffer + offset -1) |= 0x80;
      }
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer)
    {
      int offset = 0;
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
      uint8_t hiStop_lengthT = *(inbuffer + offset++);
      if(hiStop_lengthT > hiStop_length)
        this->hiStop = (float*)realloc(this->hiStop, hiStop_lengthT * sizeof(float));
      offset += 3;
      hiStop_length = hiStop_lengthT;
      for( uint8_t i = 0; i < hiStop_length; i++){
      uint32_t * val_st_hiStop = (uint32_t*) &(this->st_hiStop);
      offset += 3;
      *val_st_hiStop = ((uint32_t)(*(inbuffer + offset++))>>5 & 0x07);
      *val_st_hiStop |= ((uint32_t)(*(inbuffer + offset++)) & 0xff)<<3;
      *val_st_hiStop |= ((uint32_t)(*(inbuffer + offset++)) & 0xff)<<11;
      *val_st_hiStop |= ((uint32_t)(*(inbuffer + offset)) & 0x0f)<<19;
      uint32_t exp_st_hiStop = ((uint32_t)(*(inbuffer + offset++))&0xf0)>>4;
      exp_st_hiStop |= ((uint32_t)(*(inbuffer + offset)) & 0x7f)<<4;
      if(exp_st_hiStop !=0)
        *val_st_hiStop |= ((exp_st_hiStop)-1023+127)<<23;
      if( ((*(inbuffer+offset++)) & 0x80) > 0) this->st_hiStop = -this->st_hiStop;
        memcpy( &(this->hiStop[i]), &(this->st_hiStop), sizeof(float));
      }
      uint8_t loStop_lengthT = *(inbuffer + offset++);
      if(loStop_lengthT > loStop_length)
        this->loStop = (float*)realloc(this->loStop, loStop_lengthT * sizeof(float));
      offset += 3;
      loStop_length = loStop_lengthT;
      for( uint8_t i = 0; i < loStop_length; i++){
      uint32_t * val_st_loStop = (uint32_t*) &(this->st_loStop);
      offset += 3;
      *val_st_loStop = ((uint32_t)(*(inbuffer + offset++))>>5 & 0x07);
      *val_st_loStop |= ((uint32_t)(*(inbuffer + offset++)) & 0xff)<<3;
      *val_st_loStop |= ((uint32_t)(*(inbuffer + offset++)) & 0xff)<<11;
      *val_st_loStop |= ((uint32_t)(*(inbuffer + offset)) & 0x0f)<<19;
      uint32_t exp_st_loStop = ((uint32_t)(*(inbuffer + offset++))&0xf0)>>4;
      exp_st_loStop |= ((uint32_t)(*(inbuffer + offset)) & 0x7f)<<4;
      if(exp_st_loStop !=0)
        *val_st_loStop |= ((exp_st_loStop)-1023+127)<<23;
      if( ((*(inbuffer+offset++)) & 0x80) > 0) this->st_loStop = -this->st_loStop;
        memcpy( &(this->loStop[i]), &(this->st_loStop), sizeof(float));
      }
      uint8_t erp_lengthT = *(inbuffer + offset++);
      if(erp_lengthT > erp_length)
        this->erp = (float*)realloc(this->erp, erp_lengthT * sizeof(float));
      offset += 3;
      erp_length = erp_lengthT;
      for( uint8_t i = 0; i < erp_length; i++){
      uint32_t * val_st_erp = (uint32_t*) &(this->st_erp);
      offset += 3;
      *val_st_erp = ((uint32_t)(*(inbuffer + offset++))>>5 & 0x07);
      *val_st_erp |= ((uint32_t)(*(inbuffer + offset++)) & 0xff)<<3;
      *val_st_erp |= ((uint32_t)(*(inbuffer + offset++)) & 0xff)<<11;
      *val_st_erp |= ((uint32_t)(*(inbuffer + offset)) & 0x0f)<<19;
      uint32_t exp_st_erp = ((uint32_t)(*(inbuffer + offset++))&0xf0)>>4;
      exp_st_erp |= ((uint32_t)(*(inbuffer + offset)) & 0x7f)<<4;
      if(exp_st_erp !=0)
        *val_st_erp |= ((exp_st_erp)-1023+127)<<23;
      if( ((*(inbuffer+offset++)) & 0x80) > 0) this->st_erp = -this->st_erp;
        memcpy( &(this->erp[i]), &(this->st_erp), sizeof(float));
      }
      uint8_t cfm_lengthT = *(inbuffer + offset++);
      if(cfm_lengthT > cfm_length)
        this->cfm = (float*)realloc(this->cfm, cfm_lengthT * sizeof(float));
      offset += 3;
      cfm_length = cfm_lengthT;
      for( uint8_t i = 0; i < cfm_length; i++){
      uint32_t * val_st_cfm = (uint32_t*) &(this->st_cfm);
      offset += 3;
      *val_st_cfm = ((uint32_t)(*(inbuffer + offset++))>>5 & 0x07);
      *val_st_cfm |= ((uint32_t)(*(inbuffer + offset++)) & 0xff)<<3;
      *val_st_cfm |= ((uint32_t)(*(inbuffer + offset++)) & 0xff)<<11;
      *val_st_cfm |= ((uint32_t)(*(inbuffer + offset)) & 0x0f)<<19;
      uint32_t exp_st_cfm = ((uint32_t)(*(inbuffer + offset++))&0xf0)>>4;
      exp_st_cfm |= ((uint32_t)(*(inbuffer + offset)) & 0x7f)<<4;
      if(exp_st_cfm !=0)
        *val_st_cfm |= ((exp_st_cfm)-1023+127)<<23;
      if( ((*(inbuffer+offset++)) & 0x80) > 0) this->st_cfm = -this->st_cfm;
        memcpy( &(this->cfm[i]), &(this->st_cfm), sizeof(float));
      }
      uint8_t stop_erp_lengthT = *(inbuffer + offset++);
      if(stop_erp_lengthT > stop_erp_length)
        this->stop_erp = (float*)realloc(this->stop_erp, stop_erp_lengthT * sizeof(float));
      offset += 3;
      stop_erp_length = stop_erp_lengthT;
      for( uint8_t i = 0; i < stop_erp_length; i++){
      uint32_t * val_st_stop_erp = (uint32_t*) &(this->st_stop_erp);
      offset += 3;
      *val_st_stop_erp = ((uint32_t)(*(inbuffer + offset++))>>5 & 0x07);
      *val_st_stop_erp |= ((uint32_t)(*(inbuffer + offset++)) & 0xff)<<3;
      *val_st_stop_erp |= ((uint32_t)(*(inbuffer + offset++)) & 0xff)<<11;
      *val_st_stop_erp |= ((uint32_t)(*(inbuffer + offset)) & 0x0f)<<19;
      uint32_t exp_st_stop_erp = ((uint32_t)(*(inbuffer + offset++))&0xf0)>>4;
      exp_st_stop_erp |= ((uint32_t)(*(inbuffer + offset)) & 0x7f)<<4;
      if(exp_st_stop_erp !=0)
        *val_st_stop_erp |= ((exp_st_stop_erp)-1023+127)<<23;
      if( ((*(inbuffer+offset++)) & 0x80) > 0) this->st_stop_erp = -this->st_stop_erp;
        memcpy( &(this->stop_erp[i]), &(this->st_stop_erp), sizeof(float));
      }
      uint8_t stop_cfm_lengthT = *(inbuffer + offset++);
      if(stop_cfm_lengthT > stop_cfm_length)
        this->stop_cfm = (float*)realloc(this->stop_cfm, stop_cfm_lengthT * sizeof(float));
      offset += 3;
      stop_cfm_length = stop_cfm_lengthT;
      for( uint8_t i = 0; i < stop_cfm_length; i++){
      uint32_t * val_st_stop_cfm = (uint32_t*) &(this->st_stop_cfm);
      offset += 3;
      *val_st_stop_cfm = ((uint32_t)(*(inbuffer + offset++))>>5 & 0x07);
      *val_st_stop_cfm |= ((uint32_t)(*(inbuffer + offset++)) & 0xff)<<3;
      *val_st_stop_cfm |= ((uint32_t)(*(inbuffer + offset++)) & 0xff)<<11;
      *val_st_stop_cfm |= ((uint32_t)(*(inbuffer + offset)) & 0x0f)<<19;
      uint32_t exp_st_stop_cfm = ((uint32_t)(*(inbuffer + offset++))&0xf0)>>4;
      exp_st_stop_cfm |= ((uint32_t)(*(inbuffer + offset)) & 0x7f)<<4;
      if(exp_st_stop_cfm !=0)
        *val_st_stop_cfm |= ((exp_st_stop_cfm)-1023+127)<<23;
      if( ((*(inbuffer+offset++)) & 0x80) > 0) this->st_stop_cfm = -this->st_stop_cfm;
        memcpy( &(this->stop_cfm[i]), &(this->st_stop_cfm), sizeof(float));
      }
      uint8_t fudge_factor_lengthT = *(inbuffer + offset++);
      if(fudge_factor_lengthT > fudge_factor_length)
        this->fudge_factor = (float*)realloc(this->fudge_factor, fudge_factor_lengthT * sizeof(float));
      offset += 3;
      fudge_factor_length = fudge_factor_lengthT;
      for( uint8_t i = 0; i < fudge_factor_length; i++){
      uint32_t * val_st_fudge_factor = (uint32_t*) &(this->st_fudge_factor);
      offset += 3;
      *val_st_fudge_factor = ((uint32_t)(*(inbuffer + offset++))>>5 & 0x07);
      *val_st_fudge_factor |= ((uint32_t)(*(inbuffer + offset++)) & 0xff)<<3;
      *val_st_fudge_factor |= ((uint32_t)(*(inbuffer + offset++)) & 0xff)<<11;
      *val_st_fudge_factor |= ((uint32_t)(*(inbuffer + offset)) & 0x0f)<<19;
      uint32_t exp_st_fudge_factor = ((uint32_t)(*(inbuffer + offset++))&0xf0)>>4;
      exp_st_fudge_factor |= ((uint32_t)(*(inbuffer + offset)) & 0x7f)<<4;
      if(exp_st_fudge_factor !=0)
        *val_st_fudge_factor |= ((exp_st_fudge_factor)-1023+127)<<23;
      if( ((*(inbuffer+offset++)) & 0x80) > 0) this->st_fudge_factor = -this->st_fudge_factor;
        memcpy( &(this->fudge_factor[i]), &(this->st_fudge_factor), sizeof(float));
      }
      uint8_t fmax_lengthT = *(inbuffer + offset++);
      if(fmax_lengthT > fmax_length)
        this->fmax = (float*)realloc(this->fmax, fmax_lengthT * sizeof(float));
      offset += 3;
      fmax_length = fmax_lengthT;
      for( uint8_t i = 0; i < fmax_length; i++){
      uint32_t * val_st_fmax = (uint32_t*) &(this->st_fmax);
      offset += 3;
      *val_st_fmax = ((uint32_t)(*(inbuffer + offset++))>>5 & 0x07);
      *val_st_fmax |= ((uint32_t)(*(inbuffer + offset++)) & 0xff)<<3;
      *val_st_fmax |= ((uint32_t)(*(inbuffer + offset++)) & 0xff)<<11;
      *val_st_fmax |= ((uint32_t)(*(inbuffer + offset)) & 0x0f)<<19;
      uint32_t exp_st_fmax = ((uint32_t)(*(inbuffer + offset++))&0xf0)>>4;
      exp_st_fmax |= ((uint32_t)(*(inbuffer + offset)) & 0x7f)<<4;
      if(exp_st_fmax !=0)
        *val_st_fmax |= ((exp_st_fmax)-1023+127)<<23;
      if( ((*(inbuffer+offset++)) & 0x80) > 0) this->st_fmax = -this->st_fmax;
        memcpy( &(this->fmax[i]), &(this->st_fmax), sizeof(float));
      }
      uint8_t vel_lengthT = *(inbuffer + offset++);
      if(vel_lengthT > vel_length)
        this->vel = (float*)realloc(this->vel, vel_lengthT * sizeof(float));
      offset += 3;
      vel_length = vel_lengthT;
      for( uint8_t i = 0; i < vel_length; i++){
      uint32_t * val_st_vel = (uint32_t*) &(this->st_vel);
      offset += 3;
      *val_st_vel = ((uint32_t)(*(inbuffer + offset++))>>5 & 0x07);
      *val_st_vel |= ((uint32_t)(*(inbuffer + offset++)) & 0xff)<<3;
      *val_st_vel |= ((uint32_t)(*(inbuffer + offset++)) & 0xff)<<11;
      *val_st_vel |= ((uint32_t)(*(inbuffer + offset)) & 0x0f)<<19;
      uint32_t exp_st_vel = ((uint32_t)(*(inbuffer + offset++))&0xf0)>>4;
      exp_st_vel |= ((uint32_t)(*(inbuffer + offset)) & 0x7f)<<4;
      if(exp_st_vel !=0)
        *val_st_vel |= ((exp_st_vel)-1023+127)<<23;
      if( ((*(inbuffer+offset++)) & 0x80) > 0) this->st_vel = -this->st_vel;
        memcpy( &(this->vel[i]), &(this->st_vel), sizeof(float));
      }
     return offset;
    }

    const char * getType(){ return "gazebo_msgs/ODEJointProperties"; };
    const char * getMD5(){ return "1b744c32a920af979f53afe2f9c3511f"; };

  };

}
#endif