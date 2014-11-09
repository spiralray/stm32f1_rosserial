#ifndef _ROS_sensor_msgs_RelativeHumidity_h
#define _ROS_sensor_msgs_RelativeHumidity_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"
#include "std_msgs/Header.h"

namespace sensor_msgs
{

  class RelativeHumidity : public ros::Msg
  {
    public:
      std_msgs::Header header;
      float relative_humidity;
      float variance;

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      offset += this->header.serialize(outbuffer + offset);
      int32_t * val_relative_humidity = (int32_t *) &(this->relative_humidity);
      int32_t exp_relative_humidity = (((*val_relative_humidity)>>23)&255);
      if(exp_relative_humidity != 0)
        exp_relative_humidity += 1023-127;
      int32_t sig_relative_humidity = *val_relative_humidity;
      *(outbuffer + offset++) = 0;
      *(outbuffer + offset++) = 0;
      *(outbuffer + offset++) = 0;
      *(outbuffer + offset++) = (sig_relative_humidity<<5) & 0xff;
      *(outbuffer + offset++) = (sig_relative_humidity>>3) & 0xff;
      *(outbuffer + offset++) = (sig_relative_humidity>>11) & 0xff;
      *(outbuffer + offset++) = ((exp_relative_humidity<<4) & 0xF0) | ((sig_relative_humidity>>19)&0x0F);
      *(outbuffer + offset++) = (exp_relative_humidity>>4) & 0x7F;
      if(this->relative_humidity < 0) *(outbuffer + offset -1) |= 0x80;
      int32_t * val_variance = (int32_t *) &(this->variance);
      int32_t exp_variance = (((*val_variance)>>23)&255);
      if(exp_variance != 0)
        exp_variance += 1023-127;
      int32_t sig_variance = *val_variance;
      *(outbuffer + offset++) = 0;
      *(outbuffer + offset++) = 0;
      *(outbuffer + offset++) = 0;
      *(outbuffer + offset++) = (sig_variance<<5) & 0xff;
      *(outbuffer + offset++) = (sig_variance>>3) & 0xff;
      *(outbuffer + offset++) = (sig_variance>>11) & 0xff;
      *(outbuffer + offset++) = ((exp_variance<<4) & 0xF0) | ((sig_variance>>19)&0x0F);
      *(outbuffer + offset++) = (exp_variance>>4) & 0x7F;
      if(this->variance < 0) *(outbuffer + offset -1) |= 0x80;
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer)
    {
      int offset = 0;
      offset += this->header.deserialize(inbuffer + offset);
      uint32_t * val_relative_humidity = (uint32_t*) &(this->relative_humidity);
      offset += 3;
      *val_relative_humidity = ((uint32_t)(*(inbuffer + offset++))>>5 & 0x07);
      *val_relative_humidity |= ((uint32_t)(*(inbuffer + offset++)) & 0xff)<<3;
      *val_relative_humidity |= ((uint32_t)(*(inbuffer + offset++)) & 0xff)<<11;
      *val_relative_humidity |= ((uint32_t)(*(inbuffer + offset)) & 0x0f)<<19;
      uint32_t exp_relative_humidity = ((uint32_t)(*(inbuffer + offset++))&0xf0)>>4;
      exp_relative_humidity |= ((uint32_t)(*(inbuffer + offset)) & 0x7f)<<4;
      if(exp_relative_humidity !=0)
        *val_relative_humidity |= ((exp_relative_humidity)-1023+127)<<23;
      if( ((*(inbuffer+offset++)) & 0x80) > 0) this->relative_humidity = -this->relative_humidity;
      uint32_t * val_variance = (uint32_t*) &(this->variance);
      offset += 3;
      *val_variance = ((uint32_t)(*(inbuffer + offset++))>>5 & 0x07);
      *val_variance |= ((uint32_t)(*(inbuffer + offset++)) & 0xff)<<3;
      *val_variance |= ((uint32_t)(*(inbuffer + offset++)) & 0xff)<<11;
      *val_variance |= ((uint32_t)(*(inbuffer + offset)) & 0x0f)<<19;
      uint32_t exp_variance = ((uint32_t)(*(inbuffer + offset++))&0xf0)>>4;
      exp_variance |= ((uint32_t)(*(inbuffer + offset)) & 0x7f)<<4;
      if(exp_variance !=0)
        *val_variance |= ((exp_variance)-1023+127)<<23;
      if( ((*(inbuffer+offset++)) & 0x80) > 0) this->variance = -this->variance;
     return offset;
    }

    const char * getType(){ return "sensor_msgs/RelativeHumidity"; };
    const char * getMD5(){ return "8730015b05955b7e992ce29a2678d90f"; };

  };

}
#endif