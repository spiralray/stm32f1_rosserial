#ifndef _ROS_SERVICE_GetNormal_h
#define _ROS_SERVICE_GetNormal_h
#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"
#include "geometry_msgs/PointStamped.h"
#include "geometry_msgs/Vector3.h"

namespace hector_nav_msgs
{

static const char GETNORMAL[] = "hector_nav_msgs/GetNormal";

  class GetNormalRequest : public ros::Msg
  {
    public:
      geometry_msgs::PointStamped point;

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      offset += this->point.serialize(outbuffer + offset);
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer)
    {
      int offset = 0;
      offset += this->point.deserialize(inbuffer + offset);
     return offset;
    }

    const char * getType(){ return GETNORMAL; };
    const char * getMD5(){ return "47dfdbd810b48d0a47b7ad67e4191bcc"; };

  };

  class GetNormalResponse : public ros::Msg
  {
    public:
      geometry_msgs::Vector3 normal;
      float yaw;

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      offset += this->normal.serialize(outbuffer + offset);
      union {
        float real;
        uint32_t base;
      } u_yaw;
      u_yaw.real = this->yaw;
      *(outbuffer + offset + 0) = (u_yaw.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_yaw.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_yaw.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_yaw.base >> (8 * 3)) & 0xFF;
      offset += sizeof(this->yaw);
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer)
    {
      int offset = 0;
      offset += this->normal.deserialize(inbuffer + offset);
      union {
        float real;
        uint32_t base;
      } u_yaw;
      u_yaw.base = 0;
      u_yaw.base |= ((uint32_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_yaw.base |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_yaw.base |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_yaw.base |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      this->yaw = u_yaw.real;
      offset += sizeof(this->yaw);
     return offset;
    }

    const char * getType(){ return GETNORMAL; };
    const char * getMD5(){ return "8ea5d051594753307ebd995c02db60a3"; };

  };

  class GetNormal {
    public:
    typedef GetNormalRequest Request;
    typedef GetNormalResponse Response;
  };

}
#endif
