#ifndef _ROS_shape_msgs_Plane_h
#define _ROS_shape_msgs_Plane_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"

namespace shape_msgs
{

  class Plane : public ros::Msg
  {
    public:
      float coef[4];

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      for( uint8_t i = 0; i < 4; i++){
      int32_t * val_coefi = (int32_t *) &(this->coef[i]);
      int32_t exp_coefi = (((*val_coefi)>>23)&255);
      if(exp_coefi != 0)
        exp_coefi += 1023-127;
      int32_t sig_coefi = *val_coefi;
      *(outbuffer + offset++) = 0;
      *(outbuffer + offset++) = 0;
      *(outbuffer + offset++) = 0;
      *(outbuffer + offset++) = (sig_coefi<<5) & 0xff;
      *(outbuffer + offset++) = (sig_coefi>>3) & 0xff;
      *(outbuffer + offset++) = (sig_coefi>>11) & 0xff;
      *(outbuffer + offset++) = ((exp_coefi<<4) & 0xF0) | ((sig_coefi>>19)&0x0F);
      *(outbuffer + offset++) = (exp_coefi>>4) & 0x7F;
      if(this->coef[i] < 0) *(outbuffer + offset -1) |= 0x80;
      }
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer)
    {
      int offset = 0;
      for( uint8_t i = 0; i < 4; i++){
      uint32_t * val_coefi = (uint32_t*) &(this->coef[i]);
      offset += 3;
      *val_coefi = ((uint32_t)(*(inbuffer + offset++))>>5 & 0x07);
      *val_coefi |= ((uint32_t)(*(inbuffer + offset++)) & 0xff)<<3;
      *val_coefi |= ((uint32_t)(*(inbuffer + offset++)) & 0xff)<<11;
      *val_coefi |= ((uint32_t)(*(inbuffer + offset)) & 0x0f)<<19;
      uint32_t exp_coefi = ((uint32_t)(*(inbuffer + offset++))&0xf0)>>4;
      exp_coefi |= ((uint32_t)(*(inbuffer + offset)) & 0x7f)<<4;
      if(exp_coefi !=0)
        *val_coefi |= ((exp_coefi)-1023+127)<<23;
      if( ((*(inbuffer+offset++)) & 0x80) > 0) this->coef[i] = -this->coef[i];
      }
     return offset;
    }

    const char * getType(){ return "shape_msgs/Plane"; };
    const char * getMD5(){ return "2c1b92ed8f31492f8e73f6a4a44ca796"; };

  };

}
#endif