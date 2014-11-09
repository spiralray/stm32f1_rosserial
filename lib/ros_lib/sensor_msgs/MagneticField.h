#ifndef _ROS_sensor_msgs_MagneticField_h
#define _ROS_sensor_msgs_MagneticField_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"
#include "std_msgs/Header.h"
#include "geometry_msgs/Vector3.h"

namespace sensor_msgs
{

  class MagneticField : public ros::Msg
  {
    public:
      std_msgs::Header header;
      geometry_msgs::Vector3 magnetic_field;
      float magnetic_field_covariance[9];

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      offset += this->header.serialize(outbuffer + offset);
      offset += this->magnetic_field.serialize(outbuffer + offset);
      for( uint8_t i = 0; i < 9; i++){
      int32_t * val_magnetic_field_covariancei = (int32_t *) &(this->magnetic_field_covariance[i]);
      int32_t exp_magnetic_field_covariancei = (((*val_magnetic_field_covariancei)>>23)&255);
      if(exp_magnetic_field_covariancei != 0)
        exp_magnetic_field_covariancei += 1023-127;
      int32_t sig_magnetic_field_covariancei = *val_magnetic_field_covariancei;
      *(outbuffer + offset++) = 0;
      *(outbuffer + offset++) = 0;
      *(outbuffer + offset++) = 0;
      *(outbuffer + offset++) = (sig_magnetic_field_covariancei<<5) & 0xff;
      *(outbuffer + offset++) = (sig_magnetic_field_covariancei>>3) & 0xff;
      *(outbuffer + offset++) = (sig_magnetic_field_covariancei>>11) & 0xff;
      *(outbuffer + offset++) = ((exp_magnetic_field_covariancei<<4) & 0xF0) | ((sig_magnetic_field_covariancei>>19)&0x0F);
      *(outbuffer + offset++) = (exp_magnetic_field_covariancei>>4) & 0x7F;
      if(this->magnetic_field_covariance[i] < 0) *(outbuffer + offset -1) |= 0x80;
      }
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer)
    {
      int offset = 0;
      offset += this->header.deserialize(inbuffer + offset);
      offset += this->magnetic_field.deserialize(inbuffer + offset);
      for( uint8_t i = 0; i < 9; i++){
      uint32_t * val_magnetic_field_covariancei = (uint32_t*) &(this->magnetic_field_covariance[i]);
      offset += 3;
      *val_magnetic_field_covariancei = ((uint32_t)(*(inbuffer + offset++))>>5 & 0x07);
      *val_magnetic_field_covariancei |= ((uint32_t)(*(inbuffer + offset++)) & 0xff)<<3;
      *val_magnetic_field_covariancei |= ((uint32_t)(*(inbuffer + offset++)) & 0xff)<<11;
      *val_magnetic_field_covariancei |= ((uint32_t)(*(inbuffer + offset)) & 0x0f)<<19;
      uint32_t exp_magnetic_field_covariancei = ((uint32_t)(*(inbuffer + offset++))&0xf0)>>4;
      exp_magnetic_field_covariancei |= ((uint32_t)(*(inbuffer + offset)) & 0x7f)<<4;
      if(exp_magnetic_field_covariancei !=0)
        *val_magnetic_field_covariancei |= ((exp_magnetic_field_covariancei)-1023+127)<<23;
      if( ((*(inbuffer+offset++)) & 0x80) > 0) this->magnetic_field_covariance[i] = -this->magnetic_field_covariance[i];
      }
     return offset;
    }

    const char * getType(){ return "sensor_msgs/MagneticField"; };
    const char * getMD5(){ return "2f3b0b43eed0c9501de0fa3ff89a45aa"; };

  };

}
#endif