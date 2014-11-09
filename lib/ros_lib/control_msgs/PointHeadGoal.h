#ifndef _ROS_control_msgs_PointHeadGoal_h
#define _ROS_control_msgs_PointHeadGoal_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"
#include "geometry_msgs/PointStamped.h"
#include "geometry_msgs/Vector3.h"
#include "ros/duration.h"

namespace control_msgs
{

  class PointHeadGoal : public ros::Msg
  {
    public:
      geometry_msgs::PointStamped target;
      geometry_msgs::Vector3 pointing_axis;
      const char* pointing_frame;
      ros::Duration min_duration;
      float max_velocity;

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      offset += this->target.serialize(outbuffer + offset);
      offset += this->pointing_axis.serialize(outbuffer + offset);
      uint32_t length_pointing_frame = strlen(this->pointing_frame);
      memcpy(outbuffer + offset, &length_pointing_frame, sizeof(uint32_t));
      offset += 4;
      memcpy(outbuffer + offset, this->pointing_frame, length_pointing_frame);
      offset += length_pointing_frame;
      *(outbuffer + offset + 0) = (this->min_duration.sec >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (this->min_duration.sec >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (this->min_duration.sec >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (this->min_duration.sec >> (8 * 3)) & 0xFF;
      offset += sizeof(this->min_duration.sec);
      *(outbuffer + offset + 0) = (this->min_duration.nsec >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (this->min_duration.nsec >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (this->min_duration.nsec >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (this->min_duration.nsec >> (8 * 3)) & 0xFF;
      offset += sizeof(this->min_duration.nsec);
      int32_t * val_max_velocity = (int32_t *) &(this->max_velocity);
      int32_t exp_max_velocity = (((*val_max_velocity)>>23)&255);
      if(exp_max_velocity != 0)
        exp_max_velocity += 1023-127;
      int32_t sig_max_velocity = *val_max_velocity;
      *(outbuffer + offset++) = 0;
      *(outbuffer + offset++) = 0;
      *(outbuffer + offset++) = 0;
      *(outbuffer + offset++) = (sig_max_velocity<<5) & 0xff;
      *(outbuffer + offset++) = (sig_max_velocity>>3) & 0xff;
      *(outbuffer + offset++) = (sig_max_velocity>>11) & 0xff;
      *(outbuffer + offset++) = ((exp_max_velocity<<4) & 0xF0) | ((sig_max_velocity>>19)&0x0F);
      *(outbuffer + offset++) = (exp_max_velocity>>4) & 0x7F;
      if(this->max_velocity < 0) *(outbuffer + offset -1) |= 0x80;
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer)
    {
      int offset = 0;
      offset += this->target.deserialize(inbuffer + offset);
      offset += this->pointing_axis.deserialize(inbuffer + offset);
      uint32_t length_pointing_frame;
      memcpy(&length_pointing_frame, (inbuffer + offset), sizeof(uint32_t));
      offset += 4;
      for(unsigned int k= offset; k< offset+length_pointing_frame; ++k){
          inbuffer[k-1]=inbuffer[k];
      }
      inbuffer[offset+length_pointing_frame-1]=0;
      this->pointing_frame = (char *)(inbuffer + offset-1);
      offset += length_pointing_frame;
      this->min_duration.sec =  ((uint32_t) (*(inbuffer + offset)));
      this->min_duration.sec |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      this->min_duration.sec |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      this->min_duration.sec |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      offset += sizeof(this->min_duration.sec);
      this->min_duration.nsec =  ((uint32_t) (*(inbuffer + offset)));
      this->min_duration.nsec |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      this->min_duration.nsec |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      this->min_duration.nsec |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      offset += sizeof(this->min_duration.nsec);
      uint32_t * val_max_velocity = (uint32_t*) &(this->max_velocity);
      offset += 3;
      *val_max_velocity = ((uint32_t)(*(inbuffer + offset++))>>5 & 0x07);
      *val_max_velocity |= ((uint32_t)(*(inbuffer + offset++)) & 0xff)<<3;
      *val_max_velocity |= ((uint32_t)(*(inbuffer + offset++)) & 0xff)<<11;
      *val_max_velocity |= ((uint32_t)(*(inbuffer + offset)) & 0x0f)<<19;
      uint32_t exp_max_velocity = ((uint32_t)(*(inbuffer + offset++))&0xf0)>>4;
      exp_max_velocity |= ((uint32_t)(*(inbuffer + offset)) & 0x7f)<<4;
      if(exp_max_velocity !=0)
        *val_max_velocity |= ((exp_max_velocity)-1023+127)<<23;
      if( ((*(inbuffer+offset++)) & 0x80) > 0) this->max_velocity = -this->max_velocity;
     return offset;
    }

    const char * getType(){ return "control_msgs/PointHeadGoal"; };
    const char * getMD5(){ return "8b92b1cd5e06c8a94c917dc3209a4c1d"; };

  };

}
#endif