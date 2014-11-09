#ifndef _ROS_geometry_msgs_Point_h
#define _ROS_geometry_msgs_Point_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"

namespace geometry_msgs
{

  class Point : public ros::Msg
  {
    public:
      float x;
      float y;
      float z;

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      int32_t * val_x = (int32_t *) &(this->x);
      int32_t exp_x = (((*val_x)>>23)&255);
      if(exp_x != 0)
        exp_x += 1023-127;
      int32_t sig_x = *val_x;
      *(outbuffer + offset++) = 0;
      *(outbuffer + offset++) = 0;
      *(outbuffer + offset++) = 0;
      *(outbuffer + offset++) = (sig_x<<5) & 0xff;
      *(outbuffer + offset++) = (sig_x>>3) & 0xff;
      *(outbuffer + offset++) = (sig_x>>11) & 0xff;
      *(outbuffer + offset++) = ((exp_x<<4) & 0xF0) | ((sig_x>>19)&0x0F);
      *(outbuffer + offset++) = (exp_x>>4) & 0x7F;
      if(this->x < 0) *(outbuffer + offset -1) |= 0x80;
      int32_t * val_y = (int32_t *) &(this->y);
      int32_t exp_y = (((*val_y)>>23)&255);
      if(exp_y != 0)
        exp_y += 1023-127;
      int32_t sig_y = *val_y;
      *(outbuffer + offset++) = 0;
      *(outbuffer + offset++) = 0;
      *(outbuffer + offset++) = 0;
      *(outbuffer + offset++) = (sig_y<<5) & 0xff;
      *(outbuffer + offset++) = (sig_y>>3) & 0xff;
      *(outbuffer + offset++) = (sig_y>>11) & 0xff;
      *(outbuffer + offset++) = ((exp_y<<4) & 0xF0) | ((sig_y>>19)&0x0F);
      *(outbuffer + offset++) = (exp_y>>4) & 0x7F;
      if(this->y < 0) *(outbuffer + offset -1) |= 0x80;
      int32_t * val_z = (int32_t *) &(this->z);
      int32_t exp_z = (((*val_z)>>23)&255);
      if(exp_z != 0)
        exp_z += 1023-127;
      int32_t sig_z = *val_z;
      *(outbuffer + offset++) = 0;
      *(outbuffer + offset++) = 0;
      *(outbuffer + offset++) = 0;
      *(outbuffer + offset++) = (sig_z<<5) & 0xff;
      *(outbuffer + offset++) = (sig_z>>3) & 0xff;
      *(outbuffer + offset++) = (sig_z>>11) & 0xff;
      *(outbuffer + offset++) = ((exp_z<<4) & 0xF0) | ((sig_z>>19)&0x0F);
      *(outbuffer + offset++) = (exp_z>>4) & 0x7F;
      if(this->z < 0) *(outbuffer + offset -1) |= 0x80;
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer)
    {
      int offset = 0;
      uint32_t * val_x = (uint32_t*) &(this->x);
      offset += 3;
      *val_x = ((uint32_t)(*(inbuffer + offset++))>>5 & 0x07);
      *val_x |= ((uint32_t)(*(inbuffer + offset++)) & 0xff)<<3;
      *val_x |= ((uint32_t)(*(inbuffer + offset++)) & 0xff)<<11;
      *val_x |= ((uint32_t)(*(inbuffer + offset)) & 0x0f)<<19;
      uint32_t exp_x = ((uint32_t)(*(inbuffer + offset++))&0xf0)>>4;
      exp_x |= ((uint32_t)(*(inbuffer + offset)) & 0x7f)<<4;
      if(exp_x !=0)
        *val_x |= ((exp_x)-1023+127)<<23;
      if( ((*(inbuffer+offset++)) & 0x80) > 0) this->x = -this->x;
      uint32_t * val_y = (uint32_t*) &(this->y);
      offset += 3;
      *val_y = ((uint32_t)(*(inbuffer + offset++))>>5 & 0x07);
      *val_y |= ((uint32_t)(*(inbuffer + offset++)) & 0xff)<<3;
      *val_y |= ((uint32_t)(*(inbuffer + offset++)) & 0xff)<<11;
      *val_y |= ((uint32_t)(*(inbuffer + offset)) & 0x0f)<<19;
      uint32_t exp_y = ((uint32_t)(*(inbuffer + offset++))&0xf0)>>4;
      exp_y |= ((uint32_t)(*(inbuffer + offset)) & 0x7f)<<4;
      if(exp_y !=0)
        *val_y |= ((exp_y)-1023+127)<<23;
      if( ((*(inbuffer+offset++)) & 0x80) > 0) this->y = -this->y;
      uint32_t * val_z = (uint32_t*) &(this->z);
      offset += 3;
      *val_z = ((uint32_t)(*(inbuffer + offset++))>>5 & 0x07);
      *val_z |= ((uint32_t)(*(inbuffer + offset++)) & 0xff)<<3;
      *val_z |= ((uint32_t)(*(inbuffer + offset++)) & 0xff)<<11;
      *val_z |= ((uint32_t)(*(inbuffer + offset)) & 0x0f)<<19;
      uint32_t exp_z = ((uint32_t)(*(inbuffer + offset++))&0xf0)>>4;
      exp_z |= ((uint32_t)(*(inbuffer + offset)) & 0x7f)<<4;
      if(exp_z !=0)
        *val_z |= ((exp_z)-1023+127)<<23;
      if( ((*(inbuffer+offset++)) & 0x80) > 0) this->z = -this->z;
     return offset;
    }

    const char * getType(){ return "geometry_msgs/Point"; };
    const char * getMD5(){ return "4a842b65f413084dc2b10fb484ea7f17"; };

  };

}
#endif