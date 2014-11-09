#ifndef _ROS_geometry_msgs_PoseWithCovariance_h
#define _ROS_geometry_msgs_PoseWithCovariance_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"
#include "geometry_msgs/Pose.h"

namespace geometry_msgs
{

  class PoseWithCovariance : public ros::Msg
  {
    public:
      geometry_msgs::Pose pose;
      float covariance[36];

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      offset += this->pose.serialize(outbuffer + offset);
      for( uint8_t i = 0; i < 36; i++){
      int32_t * val_covariancei = (int32_t *) &(this->covariance[i]);
      int32_t exp_covariancei = (((*val_covariancei)>>23)&255);
      if(exp_covariancei != 0)
        exp_covariancei += 1023-127;
      int32_t sig_covariancei = *val_covariancei;
      *(outbuffer + offset++) = 0;
      *(outbuffer + offset++) = 0;
      *(outbuffer + offset++) = 0;
      *(outbuffer + offset++) = (sig_covariancei<<5) & 0xff;
      *(outbuffer + offset++) = (sig_covariancei>>3) & 0xff;
      *(outbuffer + offset++) = (sig_covariancei>>11) & 0xff;
      *(outbuffer + offset++) = ((exp_covariancei<<4) & 0xF0) | ((sig_covariancei>>19)&0x0F);
      *(outbuffer + offset++) = (exp_covariancei>>4) & 0x7F;
      if(this->covariance[i] < 0) *(outbuffer + offset -1) |= 0x80;
      }
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer)
    {
      int offset = 0;
      offset += this->pose.deserialize(inbuffer + offset);
      for( uint8_t i = 0; i < 36; i++){
      uint32_t * val_covariancei = (uint32_t*) &(this->covariance[i]);
      offset += 3;
      *val_covariancei = ((uint32_t)(*(inbuffer + offset++))>>5 & 0x07);
      *val_covariancei |= ((uint32_t)(*(inbuffer + offset++)) & 0xff)<<3;
      *val_covariancei |= ((uint32_t)(*(inbuffer + offset++)) & 0xff)<<11;
      *val_covariancei |= ((uint32_t)(*(inbuffer + offset)) & 0x0f)<<19;
      uint32_t exp_covariancei = ((uint32_t)(*(inbuffer + offset++))&0xf0)>>4;
      exp_covariancei |= ((uint32_t)(*(inbuffer + offset)) & 0x7f)<<4;
      if(exp_covariancei !=0)
        *val_covariancei |= ((exp_covariancei)-1023+127)<<23;
      if( ((*(inbuffer+offset++)) & 0x80) > 0) this->covariance[i] = -this->covariance[i];
      }
     return offset;
    }

    const char * getType(){ return "geometry_msgs/PoseWithCovariance"; };
    const char * getMD5(){ return "c23e848cf1b7533a8d7c259073a97e6f"; };

  };

}
#endif