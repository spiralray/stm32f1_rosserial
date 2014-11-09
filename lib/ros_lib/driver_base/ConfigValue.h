#ifndef _ROS_driver_base_ConfigValue_h
#define _ROS_driver_base_ConfigValue_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"

namespace driver_base
{

  class ConfigValue : public ros::Msg
  {
    public:
      const char* name;
      float value;

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      uint32_t length_name = strlen(this->name);
      memcpy(outbuffer + offset, &length_name, sizeof(uint32_t));
      offset += 4;
      memcpy(outbuffer + offset, this->name, length_name);
      offset += length_name;
      int32_t * val_value = (int32_t *) &(this->value);
      int32_t exp_value = (((*val_value)>>23)&255);
      if(exp_value != 0)
        exp_value += 1023-127;
      int32_t sig_value = *val_value;
      *(outbuffer + offset++) = 0;
      *(outbuffer + offset++) = 0;
      *(outbuffer + offset++) = 0;
      *(outbuffer + offset++) = (sig_value<<5) & 0xff;
      *(outbuffer + offset++) = (sig_value>>3) & 0xff;
      *(outbuffer + offset++) = (sig_value>>11) & 0xff;
      *(outbuffer + offset++) = ((exp_value<<4) & 0xF0) | ((sig_value>>19)&0x0F);
      *(outbuffer + offset++) = (exp_value>>4) & 0x7F;
      if(this->value < 0) *(outbuffer + offset -1) |= 0x80;
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer)
    {
      int offset = 0;
      uint32_t length_name;
      memcpy(&length_name, (inbuffer + offset), sizeof(uint32_t));
      offset += 4;
      for(unsigned int k= offset; k< offset+length_name; ++k){
          inbuffer[k-1]=inbuffer[k];
      }
      inbuffer[offset+length_name-1]=0;
      this->name = (char *)(inbuffer + offset-1);
      offset += length_name;
      uint32_t * val_value = (uint32_t*) &(this->value);
      offset += 3;
      *val_value = ((uint32_t)(*(inbuffer + offset++))>>5 & 0x07);
      *val_value |= ((uint32_t)(*(inbuffer + offset++)) & 0xff)<<3;
      *val_value |= ((uint32_t)(*(inbuffer + offset++)) & 0xff)<<11;
      *val_value |= ((uint32_t)(*(inbuffer + offset)) & 0x0f)<<19;
      uint32_t exp_value = ((uint32_t)(*(inbuffer + offset++))&0xf0)>>4;
      exp_value |= ((uint32_t)(*(inbuffer + offset)) & 0x7f)<<4;
      if(exp_value !=0)
        *val_value |= ((exp_value)-1023+127)<<23;
      if( ((*(inbuffer+offset++)) & 0x80) > 0) this->value = -this->value;
     return offset;
    }

    const char * getType(){ return "driver_base/ConfigValue"; };
    const char * getMD5(){ return "d8512f27253c0f65f928a67c329cd658"; };

  };

}
#endif