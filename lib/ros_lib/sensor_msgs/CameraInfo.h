#ifndef _ROS_sensor_msgs_CameraInfo_h
#define _ROS_sensor_msgs_CameraInfo_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"
#include "std_msgs/Header.h"
#include "sensor_msgs/RegionOfInterest.h"

namespace sensor_msgs
{

  class CameraInfo : public ros::Msg
  {
    public:
      std_msgs::Header header;
      uint32_t height;
      uint32_t width;
      const char* distortion_model;
      uint8_t D_length;
      float st_D;
      float * D;
      float K[9];
      float R[9];
      float P[12];
      uint32_t binning_x;
      uint32_t binning_y;
      sensor_msgs::RegionOfInterest roi;

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      offset += this->header.serialize(outbuffer + offset);
      *(outbuffer + offset + 0) = (this->height >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (this->height >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (this->height >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (this->height >> (8 * 3)) & 0xFF;
      offset += sizeof(this->height);
      *(outbuffer + offset + 0) = (this->width >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (this->width >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (this->width >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (this->width >> (8 * 3)) & 0xFF;
      offset += sizeof(this->width);
      uint32_t length_distortion_model = strlen(this->distortion_model);
      memcpy(outbuffer + offset, &length_distortion_model, sizeof(uint32_t));
      offset += 4;
      memcpy(outbuffer + offset, this->distortion_model, length_distortion_model);
      offset += length_distortion_model;
      *(outbuffer + offset++) = D_length;
      *(outbuffer + offset++) = 0;
      *(outbuffer + offset++) = 0;
      *(outbuffer + offset++) = 0;
      for( uint8_t i = 0; i < D_length; i++){
      int32_t * val_Di = (int32_t *) &(this->D[i]);
      int32_t exp_Di = (((*val_Di)>>23)&255);
      if(exp_Di != 0)
        exp_Di += 1023-127;
      int32_t sig_Di = *val_Di;
      *(outbuffer + offset++) = 0;
      *(outbuffer + offset++) = 0;
      *(outbuffer + offset++) = 0;
      *(outbuffer + offset++) = (sig_Di<<5) & 0xff;
      *(outbuffer + offset++) = (sig_Di>>3) & 0xff;
      *(outbuffer + offset++) = (sig_Di>>11) & 0xff;
      *(outbuffer + offset++) = ((exp_Di<<4) & 0xF0) | ((sig_Di>>19)&0x0F);
      *(outbuffer + offset++) = (exp_Di>>4) & 0x7F;
      if(this->D[i] < 0) *(outbuffer + offset -1) |= 0x80;
      }
      for( uint8_t i = 0; i < 9; i++){
      int32_t * val_Ki = (int32_t *) &(this->K[i]);
      int32_t exp_Ki = (((*val_Ki)>>23)&255);
      if(exp_Ki != 0)
        exp_Ki += 1023-127;
      int32_t sig_Ki = *val_Ki;
      *(outbuffer + offset++) = 0;
      *(outbuffer + offset++) = 0;
      *(outbuffer + offset++) = 0;
      *(outbuffer + offset++) = (sig_Ki<<5) & 0xff;
      *(outbuffer + offset++) = (sig_Ki>>3) & 0xff;
      *(outbuffer + offset++) = (sig_Ki>>11) & 0xff;
      *(outbuffer + offset++) = ((exp_Ki<<4) & 0xF0) | ((sig_Ki>>19)&0x0F);
      *(outbuffer + offset++) = (exp_Ki>>4) & 0x7F;
      if(this->K[i] < 0) *(outbuffer + offset -1) |= 0x80;
      }
      for( uint8_t i = 0; i < 9; i++){
      int32_t * val_Ri = (int32_t *) &(this->R[i]);
      int32_t exp_Ri = (((*val_Ri)>>23)&255);
      if(exp_Ri != 0)
        exp_Ri += 1023-127;
      int32_t sig_Ri = *val_Ri;
      *(outbuffer + offset++) = 0;
      *(outbuffer + offset++) = 0;
      *(outbuffer + offset++) = 0;
      *(outbuffer + offset++) = (sig_Ri<<5) & 0xff;
      *(outbuffer + offset++) = (sig_Ri>>3) & 0xff;
      *(outbuffer + offset++) = (sig_Ri>>11) & 0xff;
      *(outbuffer + offset++) = ((exp_Ri<<4) & 0xF0) | ((sig_Ri>>19)&0x0F);
      *(outbuffer + offset++) = (exp_Ri>>4) & 0x7F;
      if(this->R[i] < 0) *(outbuffer + offset -1) |= 0x80;
      }
      for( uint8_t i = 0; i < 12; i++){
      int32_t * val_Pi = (int32_t *) &(this->P[i]);
      int32_t exp_Pi = (((*val_Pi)>>23)&255);
      if(exp_Pi != 0)
        exp_Pi += 1023-127;
      int32_t sig_Pi = *val_Pi;
      *(outbuffer + offset++) = 0;
      *(outbuffer + offset++) = 0;
      *(outbuffer + offset++) = 0;
      *(outbuffer + offset++) = (sig_Pi<<5) & 0xff;
      *(outbuffer + offset++) = (sig_Pi>>3) & 0xff;
      *(outbuffer + offset++) = (sig_Pi>>11) & 0xff;
      *(outbuffer + offset++) = ((exp_Pi<<4) & 0xF0) | ((sig_Pi>>19)&0x0F);
      *(outbuffer + offset++) = (exp_Pi>>4) & 0x7F;
      if(this->P[i] < 0) *(outbuffer + offset -1) |= 0x80;
      }
      *(outbuffer + offset + 0) = (this->binning_x >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (this->binning_x >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (this->binning_x >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (this->binning_x >> (8 * 3)) & 0xFF;
      offset += sizeof(this->binning_x);
      *(outbuffer + offset + 0) = (this->binning_y >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (this->binning_y >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (this->binning_y >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (this->binning_y >> (8 * 3)) & 0xFF;
      offset += sizeof(this->binning_y);
      offset += this->roi.serialize(outbuffer + offset);
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer)
    {
      int offset = 0;
      offset += this->header.deserialize(inbuffer + offset);
      this->height =  ((uint32_t) (*(inbuffer + offset)));
      this->height |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      this->height |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      this->height |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      offset += sizeof(this->height);
      this->width =  ((uint32_t) (*(inbuffer + offset)));
      this->width |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      this->width |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      this->width |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      offset += sizeof(this->width);
      uint32_t length_distortion_model;
      memcpy(&length_distortion_model, (inbuffer + offset), sizeof(uint32_t));
      offset += 4;
      for(unsigned int k= offset; k< offset+length_distortion_model; ++k){
          inbuffer[k-1]=inbuffer[k];
      }
      inbuffer[offset+length_distortion_model-1]=0;
      this->distortion_model = (char *)(inbuffer + offset-1);
      offset += length_distortion_model;
      uint8_t D_lengthT = *(inbuffer + offset++);
      if(D_lengthT > D_length)
        this->D = (float*)realloc(this->D, D_lengthT * sizeof(float));
      offset += 3;
      D_length = D_lengthT;
      for( uint8_t i = 0; i < D_length; i++){
      uint32_t * val_st_D = (uint32_t*) &(this->st_D);
      offset += 3;
      *val_st_D = ((uint32_t)(*(inbuffer + offset++))>>5 & 0x07);
      *val_st_D |= ((uint32_t)(*(inbuffer + offset++)) & 0xff)<<3;
      *val_st_D |= ((uint32_t)(*(inbuffer + offset++)) & 0xff)<<11;
      *val_st_D |= ((uint32_t)(*(inbuffer + offset)) & 0x0f)<<19;
      uint32_t exp_st_D = ((uint32_t)(*(inbuffer + offset++))&0xf0)>>4;
      exp_st_D |= ((uint32_t)(*(inbuffer + offset)) & 0x7f)<<4;
      if(exp_st_D !=0)
        *val_st_D |= ((exp_st_D)-1023+127)<<23;
      if( ((*(inbuffer+offset++)) & 0x80) > 0) this->st_D = -this->st_D;
        memcpy( &(this->D[i]), &(this->st_D), sizeof(float));
      }
      for( uint8_t i = 0; i < 9; i++){
      uint32_t * val_Ki = (uint32_t*) &(this->K[i]);
      offset += 3;
      *val_Ki = ((uint32_t)(*(inbuffer + offset++))>>5 & 0x07);
      *val_Ki |= ((uint32_t)(*(inbuffer + offset++)) & 0xff)<<3;
      *val_Ki |= ((uint32_t)(*(inbuffer + offset++)) & 0xff)<<11;
      *val_Ki |= ((uint32_t)(*(inbuffer + offset)) & 0x0f)<<19;
      uint32_t exp_Ki = ((uint32_t)(*(inbuffer + offset++))&0xf0)>>4;
      exp_Ki |= ((uint32_t)(*(inbuffer + offset)) & 0x7f)<<4;
      if(exp_Ki !=0)
        *val_Ki |= ((exp_Ki)-1023+127)<<23;
      if( ((*(inbuffer+offset++)) & 0x80) > 0) this->K[i] = -this->K[i];
      }
      for( uint8_t i = 0; i < 9; i++){
      uint32_t * val_Ri = (uint32_t*) &(this->R[i]);
      offset += 3;
      *val_Ri = ((uint32_t)(*(inbuffer + offset++))>>5 & 0x07);
      *val_Ri |= ((uint32_t)(*(inbuffer + offset++)) & 0xff)<<3;
      *val_Ri |= ((uint32_t)(*(inbuffer + offset++)) & 0xff)<<11;
      *val_Ri |= ((uint32_t)(*(inbuffer + offset)) & 0x0f)<<19;
      uint32_t exp_Ri = ((uint32_t)(*(inbuffer + offset++))&0xf0)>>4;
      exp_Ri |= ((uint32_t)(*(inbuffer + offset)) & 0x7f)<<4;
      if(exp_Ri !=0)
        *val_Ri |= ((exp_Ri)-1023+127)<<23;
      if( ((*(inbuffer+offset++)) & 0x80) > 0) this->R[i] = -this->R[i];
      }
      for( uint8_t i = 0; i < 12; i++){
      uint32_t * val_Pi = (uint32_t*) &(this->P[i]);
      offset += 3;
      *val_Pi = ((uint32_t)(*(inbuffer + offset++))>>5 & 0x07);
      *val_Pi |= ((uint32_t)(*(inbuffer + offset++)) & 0xff)<<3;
      *val_Pi |= ((uint32_t)(*(inbuffer + offset++)) & 0xff)<<11;
      *val_Pi |= ((uint32_t)(*(inbuffer + offset)) & 0x0f)<<19;
      uint32_t exp_Pi = ((uint32_t)(*(inbuffer + offset++))&0xf0)>>4;
      exp_Pi |= ((uint32_t)(*(inbuffer + offset)) & 0x7f)<<4;
      if(exp_Pi !=0)
        *val_Pi |= ((exp_Pi)-1023+127)<<23;
      if( ((*(inbuffer+offset++)) & 0x80) > 0) this->P[i] = -this->P[i];
      }
      this->binning_x =  ((uint32_t) (*(inbuffer + offset)));
      this->binning_x |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      this->binning_x |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      this->binning_x |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      offset += sizeof(this->binning_x);
      this->binning_y =  ((uint32_t) (*(inbuffer + offset)));
      this->binning_y |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      this->binning_y |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      this->binning_y |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      offset += sizeof(this->binning_y);
      offset += this->roi.deserialize(inbuffer + offset);
     return offset;
    }

    const char * getType(){ return "sensor_msgs/CameraInfo"; };
    const char * getMD5(){ return "c9a58c1b0b154e0e6da7578cb991d214"; };

  };

}
#endif