#ifndef _ROS_SERVICE_QueryTrajectoryState_h
#define _ROS_SERVICE_QueryTrajectoryState_h
#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"
#include "ros/time.h"

namespace control_msgs
{

static const char QUERYTRAJECTORYSTATE[] = "control_msgs/QueryTrajectoryState";

  class QueryTrajectoryStateRequest : public ros::Msg
  {
    public:
      ros::Time time;

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      *(outbuffer + offset + 0) = (this->time.sec >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (this->time.sec >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (this->time.sec >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (this->time.sec >> (8 * 3)) & 0xFF;
      offset += sizeof(this->time.sec);
      *(outbuffer + offset + 0) = (this->time.nsec >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (this->time.nsec >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (this->time.nsec >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (this->time.nsec >> (8 * 3)) & 0xFF;
      offset += sizeof(this->time.nsec);
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer)
    {
      int offset = 0;
      this->time.sec =  ((uint32_t) (*(inbuffer + offset)));
      this->time.sec |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      this->time.sec |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      this->time.sec |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      offset += sizeof(this->time.sec);
      this->time.nsec =  ((uint32_t) (*(inbuffer + offset)));
      this->time.nsec |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      this->time.nsec |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      this->time.nsec |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      offset += sizeof(this->time.nsec);
     return offset;
    }

    const char * getType(){ return QUERYTRAJECTORYSTATE; };
    const char * getMD5(){ return "556a4fb76023a469987922359d08a844"; };

  };

  class QueryTrajectoryStateResponse : public ros::Msg
  {
    public:
      uint8_t name_length;
      char* st_name;
      char* * name;
      uint8_t position_length;
      float st_position;
      float * position;
      uint8_t velocity_length;
      float st_velocity;
      float * velocity;
      uint8_t acceleration_length;
      float st_acceleration;
      float * acceleration;

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      *(outbuffer + offset++) = name_length;
      *(outbuffer + offset++) = 0;
      *(outbuffer + offset++) = 0;
      *(outbuffer + offset++) = 0;
      for( uint8_t i = 0; i < name_length; i++){
      uint32_t length_namei = strlen(this->name[i]);
      memcpy(outbuffer + offset, &length_namei, sizeof(uint32_t));
      offset += 4;
      memcpy(outbuffer + offset, this->name[i], length_namei);
      offset += length_namei;
      }
      *(outbuffer + offset++) = position_length;
      *(outbuffer + offset++) = 0;
      *(outbuffer + offset++) = 0;
      *(outbuffer + offset++) = 0;
      for( uint8_t i = 0; i < position_length; i++){
      int32_t * val_positioni = (int32_t *) &(this->position[i]);
      int32_t exp_positioni = (((*val_positioni)>>23)&255);
      if(exp_positioni != 0)
        exp_positioni += 1023-127;
      int32_t sig_positioni = *val_positioni;
      *(outbuffer + offset++) = 0;
      *(outbuffer + offset++) = 0;
      *(outbuffer + offset++) = 0;
      *(outbuffer + offset++) = (sig_positioni<<5) & 0xff;
      *(outbuffer + offset++) = (sig_positioni>>3) & 0xff;
      *(outbuffer + offset++) = (sig_positioni>>11) & 0xff;
      *(outbuffer + offset++) = ((exp_positioni<<4) & 0xF0) | ((sig_positioni>>19)&0x0F);
      *(outbuffer + offset++) = (exp_positioni>>4) & 0x7F;
      if(this->position[i] < 0) *(outbuffer + offset -1) |= 0x80;
      }
      *(outbuffer + offset++) = velocity_length;
      *(outbuffer + offset++) = 0;
      *(outbuffer + offset++) = 0;
      *(outbuffer + offset++) = 0;
      for( uint8_t i = 0; i < velocity_length; i++){
      int32_t * val_velocityi = (int32_t *) &(this->velocity[i]);
      int32_t exp_velocityi = (((*val_velocityi)>>23)&255);
      if(exp_velocityi != 0)
        exp_velocityi += 1023-127;
      int32_t sig_velocityi = *val_velocityi;
      *(outbuffer + offset++) = 0;
      *(outbuffer + offset++) = 0;
      *(outbuffer + offset++) = 0;
      *(outbuffer + offset++) = (sig_velocityi<<5) & 0xff;
      *(outbuffer + offset++) = (sig_velocityi>>3) & 0xff;
      *(outbuffer + offset++) = (sig_velocityi>>11) & 0xff;
      *(outbuffer + offset++) = ((exp_velocityi<<4) & 0xF0) | ((sig_velocityi>>19)&0x0F);
      *(outbuffer + offset++) = (exp_velocityi>>4) & 0x7F;
      if(this->velocity[i] < 0) *(outbuffer + offset -1) |= 0x80;
      }
      *(outbuffer + offset++) = acceleration_length;
      *(outbuffer + offset++) = 0;
      *(outbuffer + offset++) = 0;
      *(outbuffer + offset++) = 0;
      for( uint8_t i = 0; i < acceleration_length; i++){
      int32_t * val_accelerationi = (int32_t *) &(this->acceleration[i]);
      int32_t exp_accelerationi = (((*val_accelerationi)>>23)&255);
      if(exp_accelerationi != 0)
        exp_accelerationi += 1023-127;
      int32_t sig_accelerationi = *val_accelerationi;
      *(outbuffer + offset++) = 0;
      *(outbuffer + offset++) = 0;
      *(outbuffer + offset++) = 0;
      *(outbuffer + offset++) = (sig_accelerationi<<5) & 0xff;
      *(outbuffer + offset++) = (sig_accelerationi>>3) & 0xff;
      *(outbuffer + offset++) = (sig_accelerationi>>11) & 0xff;
      *(outbuffer + offset++) = ((exp_accelerationi<<4) & 0xF0) | ((sig_accelerationi>>19)&0x0F);
      *(outbuffer + offset++) = (exp_accelerationi>>4) & 0x7F;
      if(this->acceleration[i] < 0) *(outbuffer + offset -1) |= 0x80;
      }
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer)
    {
      int offset = 0;
      uint8_t name_lengthT = *(inbuffer + offset++);
      if(name_lengthT > name_length)
        this->name = (char**)realloc(this->name, name_lengthT * sizeof(char*));
      offset += 3;
      name_length = name_lengthT;
      for( uint8_t i = 0; i < name_length; i++){
      uint32_t length_st_name;
      memcpy(&length_st_name, (inbuffer + offset), sizeof(uint32_t));
      offset += 4;
      for(unsigned int k= offset; k< offset+length_st_name; ++k){
          inbuffer[k-1]=inbuffer[k];
      }
      inbuffer[offset+length_st_name-1]=0;
      this->st_name = (char *)(inbuffer + offset-1);
      offset += length_st_name;
        memcpy( &(this->name[i]), &(this->st_name), sizeof(char*));
      }
      uint8_t position_lengthT = *(inbuffer + offset++);
      if(position_lengthT > position_length)
        this->position = (float*)realloc(this->position, position_lengthT * sizeof(float));
      offset += 3;
      position_length = position_lengthT;
      for( uint8_t i = 0; i < position_length; i++){
      uint32_t * val_st_position = (uint32_t*) &(this->st_position);
      offset += 3;
      *val_st_position = ((uint32_t)(*(inbuffer + offset++))>>5 & 0x07);
      *val_st_position |= ((uint32_t)(*(inbuffer + offset++)) & 0xff)<<3;
      *val_st_position |= ((uint32_t)(*(inbuffer + offset++)) & 0xff)<<11;
      *val_st_position |= ((uint32_t)(*(inbuffer + offset)) & 0x0f)<<19;
      uint32_t exp_st_position = ((uint32_t)(*(inbuffer + offset++))&0xf0)>>4;
      exp_st_position |= ((uint32_t)(*(inbuffer + offset)) & 0x7f)<<4;
      if(exp_st_position !=0)
        *val_st_position |= ((exp_st_position)-1023+127)<<23;
      if( ((*(inbuffer+offset++)) & 0x80) > 0) this->st_position = -this->st_position;
        memcpy( &(this->position[i]), &(this->st_position), sizeof(float));
      }
      uint8_t velocity_lengthT = *(inbuffer + offset++);
      if(velocity_lengthT > velocity_length)
        this->velocity = (float*)realloc(this->velocity, velocity_lengthT * sizeof(float));
      offset += 3;
      velocity_length = velocity_lengthT;
      for( uint8_t i = 0; i < velocity_length; i++){
      uint32_t * val_st_velocity = (uint32_t*) &(this->st_velocity);
      offset += 3;
      *val_st_velocity = ((uint32_t)(*(inbuffer + offset++))>>5 & 0x07);
      *val_st_velocity |= ((uint32_t)(*(inbuffer + offset++)) & 0xff)<<3;
      *val_st_velocity |= ((uint32_t)(*(inbuffer + offset++)) & 0xff)<<11;
      *val_st_velocity |= ((uint32_t)(*(inbuffer + offset)) & 0x0f)<<19;
      uint32_t exp_st_velocity = ((uint32_t)(*(inbuffer + offset++))&0xf0)>>4;
      exp_st_velocity |= ((uint32_t)(*(inbuffer + offset)) & 0x7f)<<4;
      if(exp_st_velocity !=0)
        *val_st_velocity |= ((exp_st_velocity)-1023+127)<<23;
      if( ((*(inbuffer+offset++)) & 0x80) > 0) this->st_velocity = -this->st_velocity;
        memcpy( &(this->velocity[i]), &(this->st_velocity), sizeof(float));
      }
      uint8_t acceleration_lengthT = *(inbuffer + offset++);
      if(acceleration_lengthT > acceleration_length)
        this->acceleration = (float*)realloc(this->acceleration, acceleration_lengthT * sizeof(float));
      offset += 3;
      acceleration_length = acceleration_lengthT;
      for( uint8_t i = 0; i < acceleration_length; i++){
      uint32_t * val_st_acceleration = (uint32_t*) &(this->st_acceleration);
      offset += 3;
      *val_st_acceleration = ((uint32_t)(*(inbuffer + offset++))>>5 & 0x07);
      *val_st_acceleration |= ((uint32_t)(*(inbuffer + offset++)) & 0xff)<<3;
      *val_st_acceleration |= ((uint32_t)(*(inbuffer + offset++)) & 0xff)<<11;
      *val_st_acceleration |= ((uint32_t)(*(inbuffer + offset)) & 0x0f)<<19;
      uint32_t exp_st_acceleration = ((uint32_t)(*(inbuffer + offset++))&0xf0)>>4;
      exp_st_acceleration |= ((uint32_t)(*(inbuffer + offset)) & 0x7f)<<4;
      if(exp_st_acceleration !=0)
        *val_st_acceleration |= ((exp_st_acceleration)-1023+127)<<23;
      if( ((*(inbuffer+offset++)) & 0x80) > 0) this->st_acceleration = -this->st_acceleration;
        memcpy( &(this->acceleration[i]), &(this->st_acceleration), sizeof(float));
      }
     return offset;
    }

    const char * getType(){ return QUERYTRAJECTORYSTATE; };
    const char * getMD5(){ return "1f1a6554ad060f44d013e71868403c1a"; };

  };

  class QueryTrajectoryState {
    public:
    typedef QueryTrajectoryStateRequest Request;
    typedef QueryTrajectoryStateResponse Response;
  };

}
#endif
