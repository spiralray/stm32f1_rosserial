#ifndef _ROS_SERVICE_GetRecoveryInfo_h
#define _ROS_SERVICE_GetRecoveryInfo_h
#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"
#include "geometry_msgs/PoseStamped.h"
#include "ros/time.h"
#include "nav_msgs/Path.h"

namespace hector_nav_msgs
{

static const char GETRECOVERYINFO[] = "hector_nav_msgs/GetRecoveryInfo";

  class GetRecoveryInfoRequest : public ros::Msg
  {
    public:
      ros::Time request_time;
      float request_radius;

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      *(outbuffer + offset + 0) = (this->request_time.sec >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (this->request_time.sec >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (this->request_time.sec >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (this->request_time.sec >> (8 * 3)) & 0xFF;
      offset += sizeof(this->request_time.sec);
      *(outbuffer + offset + 0) = (this->request_time.nsec >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (this->request_time.nsec >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (this->request_time.nsec >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (this->request_time.nsec >> (8 * 3)) & 0xFF;
      offset += sizeof(this->request_time.nsec);
      int32_t * val_request_radius = (int32_t *) &(this->request_radius);
      int32_t exp_request_radius = (((*val_request_radius)>>23)&255);
      if(exp_request_radius != 0)
        exp_request_radius += 1023-127;
      int32_t sig_request_radius = *val_request_radius;
      *(outbuffer + offset++) = 0;
      *(outbuffer + offset++) = 0;
      *(outbuffer + offset++) = 0;
      *(outbuffer + offset++) = (sig_request_radius<<5) & 0xff;
      *(outbuffer + offset++) = (sig_request_radius>>3) & 0xff;
      *(outbuffer + offset++) = (sig_request_radius>>11) & 0xff;
      *(outbuffer + offset++) = ((exp_request_radius<<4) & 0xF0) | ((sig_request_radius>>19)&0x0F);
      *(outbuffer + offset++) = (exp_request_radius>>4) & 0x7F;
      if(this->request_radius < 0) *(outbuffer + offset -1) |= 0x80;
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer)
    {
      int offset = 0;
      this->request_time.sec =  ((uint32_t) (*(inbuffer + offset)));
      this->request_time.sec |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      this->request_time.sec |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      this->request_time.sec |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      offset += sizeof(this->request_time.sec);
      this->request_time.nsec =  ((uint32_t) (*(inbuffer + offset)));
      this->request_time.nsec |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      this->request_time.nsec |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      this->request_time.nsec |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      offset += sizeof(this->request_time.nsec);
      uint32_t * val_request_radius = (uint32_t*) &(this->request_radius);
      offset += 3;
      *val_request_radius = ((uint32_t)(*(inbuffer + offset++))>>5 & 0x07);
      *val_request_radius |= ((uint32_t)(*(inbuffer + offset++)) & 0xff)<<3;
      *val_request_radius |= ((uint32_t)(*(inbuffer + offset++)) & 0xff)<<11;
      *val_request_radius |= ((uint32_t)(*(inbuffer + offset)) & 0x0f)<<19;
      uint32_t exp_request_radius = ((uint32_t)(*(inbuffer + offset++))&0xf0)>>4;
      exp_request_radius |= ((uint32_t)(*(inbuffer + offset)) & 0x7f)<<4;
      if(exp_request_radius !=0)
        *val_request_radius |= ((exp_request_radius)-1023+127)<<23;
      if( ((*(inbuffer+offset++)) & 0x80) > 0) this->request_radius = -this->request_radius;
     return offset;
    }

    const char * getType(){ return GETRECOVERYINFO; };
    const char * getMD5(){ return "3916a0c55958d5dd43204cd2fe5608f6"; };

  };

  class GetRecoveryInfoResponse : public ros::Msg
  {
    public:
      nav_msgs::Path trajectory_radius_entry_pose_to_req_pose;
      geometry_msgs::PoseStamped radius_entry_pose;
      geometry_msgs::PoseStamped req_pose;

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      offset += this->trajectory_radius_entry_pose_to_req_pose.serialize(outbuffer + offset);
      offset += this->radius_entry_pose.serialize(outbuffer + offset);
      offset += this->req_pose.serialize(outbuffer + offset);
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer)
    {
      int offset = 0;
      offset += this->trajectory_radius_entry_pose_to_req_pose.deserialize(inbuffer + offset);
      offset += this->radius_entry_pose.deserialize(inbuffer + offset);
      offset += this->req_pose.deserialize(inbuffer + offset);
     return offset;
    }

    const char * getType(){ return GETRECOVERYINFO; };
    const char * getMD5(){ return "a93581be8e34e3c09aeafc6b9b990ad5"; };

  };

  class GetRecoveryInfo {
    public:
    typedef GetRecoveryInfoRequest Request;
    typedef GetRecoveryInfoResponse Response;
  };

}
#endif
