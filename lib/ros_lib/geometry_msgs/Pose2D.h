#ifndef _ROS_geometry_msgs_Pose2D_h
#define _ROS_geometry_msgs_Pose2D_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"

namespace geometry_msgs
{

  class Pose2D : public ros::Msg
  {
    public:
      float x;
      float y;
      float theta;

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
      int32_t * val_theta = (int32_t *) &(this->theta);
      int32_t exp_theta = (((*val_theta)>>23)&255);
      if(exp_theta != 0)
        exp_theta += 1023-127;
      int32_t sig_theta = *val_theta;
      *(outbuffer + offset++) = 0;
      *(outbuffer + offset++) = 0;
      *(outbuffer + offset++) = 0;
      *(outbuffer + offset++) = (sig_theta<<5) & 0xff;
      *(outbuffer + offset++) = (sig_theta>>3) & 0xff;
      *(outbuffer + offset++) = (sig_theta>>11) & 0xff;
      *(outbuffer + offset++) = ((exp_theta<<4) & 0xF0) | ((sig_theta>>19)&0x0F);
      *(outbuffer + offset++) = (exp_theta>>4) & 0x7F;
      if(this->theta < 0) *(outbuffer + offset -1) |= 0x80;
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
      uint32_t * val_theta = (uint32_t*) &(this->theta);
      offset += 3;
      *val_theta = ((uint32_t)(*(inbuffer + offset++))>>5 & 0x07);
      *val_theta |= ((uint32_t)(*(inbuffer + offset++)) & 0xff)<<3;
      *val_theta |= ((uint32_t)(*(inbuffer + offset++)) & 0xff)<<11;
      *val_theta |= ((uint32_t)(*(inbuffer + offset)) & 0x0f)<<19;
      uint32_t exp_theta = ((uint32_t)(*(inbuffer + offset++))&0xf0)>>4;
      exp_theta |= ((uint32_t)(*(inbuffer + offset)) & 0x7f)<<4;
      if(exp_theta !=0)
        *val_theta |= ((exp_theta)-1023+127)<<23;
      if( ((*(inbuffer+offset++)) & 0x80) > 0) this->theta = -this->theta;
     return offset;
    }

    const char * getType(){ return "geometry_msgs/Pose2D"; };
    const char * getMD5(){ return "938fa65709584ad8e77d238529be13b8"; };

  };

}
#endif