#ifndef _ROS_sensor_msgs_Illuminance_h
#define _ROS_sensor_msgs_Illuminance_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"
#include "std_msgs/Header.h"

namespace sensor_msgs
{

  class Illuminance : public ros::Msg
  {
    public:
      std_msgs::Header header;
      float illuminance;
      float variance;

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      offset += this->header.serialize(outbuffer + offset);
      int32_t * val_illuminance = (int32_t *) &(this->illuminance);
      int32_t exp_illuminance = (((*val_illuminance)>>23)&255);
      if(exp_illuminance != 0)
        exp_illuminance += 1023-127;
      int32_t sig_illuminance = *val_illuminance;
      *(outbuffer + offset++) = 0;
      *(outbuffer + offset++) = 0;
      *(outbuffer + offset++) = 0;
      *(outbuffer + offset++) = (sig_illuminance<<5) & 0xff;
      *(outbuffer + offset++) = (sig_illuminance>>3) & 0xff;
      *(outbuffer + offset++) = (sig_illuminance>>11) & 0xff;
      *(outbuffer + offset++) = ((exp_illuminance<<4) & 0xF0) | ((sig_illuminance>>19)&0x0F);
      *(outbuffer + offset++) = (exp_illuminance>>4) & 0x7F;
      if(this->illuminance < 0) *(outbuffer + offset -1) |= 0x80;
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
      uint32_t * val_illuminance = (uint32_t*) &(this->illuminance);
      offset += 3;
      *val_illuminance = ((uint32_t)(*(inbuffer + offset++))>>5 & 0x07);
      *val_illuminance |= ((uint32_t)(*(inbuffer + offset++)) & 0xff)<<3;
      *val_illuminance |= ((uint32_t)(*(inbuffer + offset++)) & 0xff)<<11;
      *val_illuminance |= ((uint32_t)(*(inbuffer + offset)) & 0x0f)<<19;
      uint32_t exp_illuminance = ((uint32_t)(*(inbuffer + offset++))&0xf0)>>4;
      exp_illuminance |= ((uint32_t)(*(inbuffer + offset)) & 0x7f)<<4;
      if(exp_illuminance !=0)
        *val_illuminance |= ((exp_illuminance)-1023+127)<<23;
      if( ((*(inbuffer+offset++)) & 0x80) > 0) this->illuminance = -this->illuminance;
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

    const char * getType(){ return "sensor_msgs/Illuminance"; };
    const char * getMD5(){ return "8cf5febb0952fca9d650c3d11a81a188"; };

  };

}
#endif