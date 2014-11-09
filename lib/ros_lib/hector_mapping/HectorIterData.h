#ifndef _ROS_hector_mapping_HectorIterData_h
#define _ROS_hector_mapping_HectorIterData_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"

namespace hector_mapping
{

  class HectorIterData : public ros::Msg
  {
    public:
      float hessian[9];
      float conditionNum;
      float determinant;
      float conditionNum2d;
      float determinant2d;

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      for( uint8_t i = 0; i < 9; i++){
      int32_t * val_hessiani = (int32_t *) &(this->hessian[i]);
      int32_t exp_hessiani = (((*val_hessiani)>>23)&255);
      if(exp_hessiani != 0)
        exp_hessiani += 1023-127;
      int32_t sig_hessiani = *val_hessiani;
      *(outbuffer + offset++) = 0;
      *(outbuffer + offset++) = 0;
      *(outbuffer + offset++) = 0;
      *(outbuffer + offset++) = (sig_hessiani<<5) & 0xff;
      *(outbuffer + offset++) = (sig_hessiani>>3) & 0xff;
      *(outbuffer + offset++) = (sig_hessiani>>11) & 0xff;
      *(outbuffer + offset++) = ((exp_hessiani<<4) & 0xF0) | ((sig_hessiani>>19)&0x0F);
      *(outbuffer + offset++) = (exp_hessiani>>4) & 0x7F;
      if(this->hessian[i] < 0) *(outbuffer + offset -1) |= 0x80;
      }
      int32_t * val_conditionNum = (int32_t *) &(this->conditionNum);
      int32_t exp_conditionNum = (((*val_conditionNum)>>23)&255);
      if(exp_conditionNum != 0)
        exp_conditionNum += 1023-127;
      int32_t sig_conditionNum = *val_conditionNum;
      *(outbuffer + offset++) = 0;
      *(outbuffer + offset++) = 0;
      *(outbuffer + offset++) = 0;
      *(outbuffer + offset++) = (sig_conditionNum<<5) & 0xff;
      *(outbuffer + offset++) = (sig_conditionNum>>3) & 0xff;
      *(outbuffer + offset++) = (sig_conditionNum>>11) & 0xff;
      *(outbuffer + offset++) = ((exp_conditionNum<<4) & 0xF0) | ((sig_conditionNum>>19)&0x0F);
      *(outbuffer + offset++) = (exp_conditionNum>>4) & 0x7F;
      if(this->conditionNum < 0) *(outbuffer + offset -1) |= 0x80;
      int32_t * val_determinant = (int32_t *) &(this->determinant);
      int32_t exp_determinant = (((*val_determinant)>>23)&255);
      if(exp_determinant != 0)
        exp_determinant += 1023-127;
      int32_t sig_determinant = *val_determinant;
      *(outbuffer + offset++) = 0;
      *(outbuffer + offset++) = 0;
      *(outbuffer + offset++) = 0;
      *(outbuffer + offset++) = (sig_determinant<<5) & 0xff;
      *(outbuffer + offset++) = (sig_determinant>>3) & 0xff;
      *(outbuffer + offset++) = (sig_determinant>>11) & 0xff;
      *(outbuffer + offset++) = ((exp_determinant<<4) & 0xF0) | ((sig_determinant>>19)&0x0F);
      *(outbuffer + offset++) = (exp_determinant>>4) & 0x7F;
      if(this->determinant < 0) *(outbuffer + offset -1) |= 0x80;
      int32_t * val_conditionNum2d = (int32_t *) &(this->conditionNum2d);
      int32_t exp_conditionNum2d = (((*val_conditionNum2d)>>23)&255);
      if(exp_conditionNum2d != 0)
        exp_conditionNum2d += 1023-127;
      int32_t sig_conditionNum2d = *val_conditionNum2d;
      *(outbuffer + offset++) = 0;
      *(outbuffer + offset++) = 0;
      *(outbuffer + offset++) = 0;
      *(outbuffer + offset++) = (sig_conditionNum2d<<5) & 0xff;
      *(outbuffer + offset++) = (sig_conditionNum2d>>3) & 0xff;
      *(outbuffer + offset++) = (sig_conditionNum2d>>11) & 0xff;
      *(outbuffer + offset++) = ((exp_conditionNum2d<<4) & 0xF0) | ((sig_conditionNum2d>>19)&0x0F);
      *(outbuffer + offset++) = (exp_conditionNum2d>>4) & 0x7F;
      if(this->conditionNum2d < 0) *(outbuffer + offset -1) |= 0x80;
      int32_t * val_determinant2d = (int32_t *) &(this->determinant2d);
      int32_t exp_determinant2d = (((*val_determinant2d)>>23)&255);
      if(exp_determinant2d != 0)
        exp_determinant2d += 1023-127;
      int32_t sig_determinant2d = *val_determinant2d;
      *(outbuffer + offset++) = 0;
      *(outbuffer + offset++) = 0;
      *(outbuffer + offset++) = 0;
      *(outbuffer + offset++) = (sig_determinant2d<<5) & 0xff;
      *(outbuffer + offset++) = (sig_determinant2d>>3) & 0xff;
      *(outbuffer + offset++) = (sig_determinant2d>>11) & 0xff;
      *(outbuffer + offset++) = ((exp_determinant2d<<4) & 0xF0) | ((sig_determinant2d>>19)&0x0F);
      *(outbuffer + offset++) = (exp_determinant2d>>4) & 0x7F;
      if(this->determinant2d < 0) *(outbuffer + offset -1) |= 0x80;
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer)
    {
      int offset = 0;
      for( uint8_t i = 0; i < 9; i++){
      uint32_t * val_hessiani = (uint32_t*) &(this->hessian[i]);
      offset += 3;
      *val_hessiani = ((uint32_t)(*(inbuffer + offset++))>>5 & 0x07);
      *val_hessiani |= ((uint32_t)(*(inbuffer + offset++)) & 0xff)<<3;
      *val_hessiani |= ((uint32_t)(*(inbuffer + offset++)) & 0xff)<<11;
      *val_hessiani |= ((uint32_t)(*(inbuffer + offset)) & 0x0f)<<19;
      uint32_t exp_hessiani = ((uint32_t)(*(inbuffer + offset++))&0xf0)>>4;
      exp_hessiani |= ((uint32_t)(*(inbuffer + offset)) & 0x7f)<<4;
      if(exp_hessiani !=0)
        *val_hessiani |= ((exp_hessiani)-1023+127)<<23;
      if( ((*(inbuffer+offset++)) & 0x80) > 0) this->hessian[i] = -this->hessian[i];
      }
      uint32_t * val_conditionNum = (uint32_t*) &(this->conditionNum);
      offset += 3;
      *val_conditionNum = ((uint32_t)(*(inbuffer + offset++))>>5 & 0x07);
      *val_conditionNum |= ((uint32_t)(*(inbuffer + offset++)) & 0xff)<<3;
      *val_conditionNum |= ((uint32_t)(*(inbuffer + offset++)) & 0xff)<<11;
      *val_conditionNum |= ((uint32_t)(*(inbuffer + offset)) & 0x0f)<<19;
      uint32_t exp_conditionNum = ((uint32_t)(*(inbuffer + offset++))&0xf0)>>4;
      exp_conditionNum |= ((uint32_t)(*(inbuffer + offset)) & 0x7f)<<4;
      if(exp_conditionNum !=0)
        *val_conditionNum |= ((exp_conditionNum)-1023+127)<<23;
      if( ((*(inbuffer+offset++)) & 0x80) > 0) this->conditionNum = -this->conditionNum;
      uint32_t * val_determinant = (uint32_t*) &(this->determinant);
      offset += 3;
      *val_determinant = ((uint32_t)(*(inbuffer + offset++))>>5 & 0x07);
      *val_determinant |= ((uint32_t)(*(inbuffer + offset++)) & 0xff)<<3;
      *val_determinant |= ((uint32_t)(*(inbuffer + offset++)) & 0xff)<<11;
      *val_determinant |= ((uint32_t)(*(inbuffer + offset)) & 0x0f)<<19;
      uint32_t exp_determinant = ((uint32_t)(*(inbuffer + offset++))&0xf0)>>4;
      exp_determinant |= ((uint32_t)(*(inbuffer + offset)) & 0x7f)<<4;
      if(exp_determinant !=0)
        *val_determinant |= ((exp_determinant)-1023+127)<<23;
      if( ((*(inbuffer+offset++)) & 0x80) > 0) this->determinant = -this->determinant;
      uint32_t * val_conditionNum2d = (uint32_t*) &(this->conditionNum2d);
      offset += 3;
      *val_conditionNum2d = ((uint32_t)(*(inbuffer + offset++))>>5 & 0x07);
      *val_conditionNum2d |= ((uint32_t)(*(inbuffer + offset++)) & 0xff)<<3;
      *val_conditionNum2d |= ((uint32_t)(*(inbuffer + offset++)) & 0xff)<<11;
      *val_conditionNum2d |= ((uint32_t)(*(inbuffer + offset)) & 0x0f)<<19;
      uint32_t exp_conditionNum2d = ((uint32_t)(*(inbuffer + offset++))&0xf0)>>4;
      exp_conditionNum2d |= ((uint32_t)(*(inbuffer + offset)) & 0x7f)<<4;
      if(exp_conditionNum2d !=0)
        *val_conditionNum2d |= ((exp_conditionNum2d)-1023+127)<<23;
      if( ((*(inbuffer+offset++)) & 0x80) > 0) this->conditionNum2d = -this->conditionNum2d;
      uint32_t * val_determinant2d = (uint32_t*) &(this->determinant2d);
      offset += 3;
      *val_determinant2d = ((uint32_t)(*(inbuffer + offset++))>>5 & 0x07);
      *val_determinant2d |= ((uint32_t)(*(inbuffer + offset++)) & 0xff)<<3;
      *val_determinant2d |= ((uint32_t)(*(inbuffer + offset++)) & 0xff)<<11;
      *val_determinant2d |= ((uint32_t)(*(inbuffer + offset)) & 0x0f)<<19;
      uint32_t exp_determinant2d = ((uint32_t)(*(inbuffer + offset++))&0xf0)>>4;
      exp_determinant2d |= ((uint32_t)(*(inbuffer + offset)) & 0x7f)<<4;
      if(exp_determinant2d !=0)
        *val_determinant2d |= ((exp_determinant2d)-1023+127)<<23;
      if( ((*(inbuffer+offset++)) & 0x80) > 0) this->determinant2d = -this->determinant2d;
     return offset;
    }

    const char * getType(){ return "hector_mapping/HectorIterData"; };
    const char * getMD5(){ return "ecedaa7e26b5fc817a1add44c17fec5f"; };

  };

}
#endif