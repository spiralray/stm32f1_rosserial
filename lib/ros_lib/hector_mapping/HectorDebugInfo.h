#ifndef _ROS_hector_mapping_HectorDebugInfo_h
#define _ROS_hector_mapping_HectorDebugInfo_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"
#include "hector_mapping/HectorIterData.h"

namespace hector_mapping
{

  class HectorDebugInfo : public ros::Msg
  {
    public:
      uint8_t iterData_length;
      hector_mapping::HectorIterData st_iterData;
      hector_mapping::HectorIterData * iterData;

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      *(outbuffer + offset++) = iterData_length;
      *(outbuffer + offset++) = 0;
      *(outbuffer + offset++) = 0;
      *(outbuffer + offset++) = 0;
      for( uint8_t i = 0; i < iterData_length; i++){
      offset += this->iterData[i].serialize(outbuffer + offset);
      }
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer)
    {
      int offset = 0;
      uint8_t iterData_lengthT = *(inbuffer + offset++);
      if(iterData_lengthT > iterData_length)
        this->iterData = (hector_mapping::HectorIterData*)realloc(this->iterData, iterData_lengthT * sizeof(hector_mapping::HectorIterData));
      offset += 3;
      iterData_length = iterData_lengthT;
      for( uint8_t i = 0; i < iterData_length; i++){
      offset += this->st_iterData.deserialize(inbuffer + offset);
        memcpy( &(this->iterData[i]), &(this->st_iterData), sizeof(hector_mapping::HectorIterData));
      }
     return offset;
    }

    const char * getType(){ return "hector_mapping/HectorDebugInfo"; };
    const char * getMD5(){ return "4d33c0696c0c536f5c1447c260756674"; };

  };

}
#endif