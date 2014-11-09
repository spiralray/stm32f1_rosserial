#ifndef _ROS_trajectory_msgs_JointTrajectoryPoint_h
#define _ROS_trajectory_msgs_JointTrajectoryPoint_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"
#include "ros/duration.h"

namespace trajectory_msgs
{

  class JointTrajectoryPoint : public ros::Msg
  {
    public:
      uint8_t positions_length;
      float st_positions;
      float * positions;
      uint8_t velocities_length;
      float st_velocities;
      float * velocities;
      uint8_t accelerations_length;
      float st_accelerations;
      float * accelerations;
      uint8_t effort_length;
      float st_effort;
      float * effort;
      ros::Duration time_from_start;

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      *(outbuffer + offset++) = positions_length;
      *(outbuffer + offset++) = 0;
      *(outbuffer + offset++) = 0;
      *(outbuffer + offset++) = 0;
      for( uint8_t i = 0; i < positions_length; i++){
      int32_t * val_positionsi = (int32_t *) &(this->positions[i]);
      int32_t exp_positionsi = (((*val_positionsi)>>23)&255);
      if(exp_positionsi != 0)
        exp_positionsi += 1023-127;
      int32_t sig_positionsi = *val_positionsi;
      *(outbuffer + offset++) = 0;
      *(outbuffer + offset++) = 0;
      *(outbuffer + offset++) = 0;
      *(outbuffer + offset++) = (sig_positionsi<<5) & 0xff;
      *(outbuffer + offset++) = (sig_positionsi>>3) & 0xff;
      *(outbuffer + offset++) = (sig_positionsi>>11) & 0xff;
      *(outbuffer + offset++) = ((exp_positionsi<<4) & 0xF0) | ((sig_positionsi>>19)&0x0F);
      *(outbuffer + offset++) = (exp_positionsi>>4) & 0x7F;
      if(this->positions[i] < 0) *(outbuffer + offset -1) |= 0x80;
      }
      *(outbuffer + offset++) = velocities_length;
      *(outbuffer + offset++) = 0;
      *(outbuffer + offset++) = 0;
      *(outbuffer + offset++) = 0;
      for( uint8_t i = 0; i < velocities_length; i++){
      int32_t * val_velocitiesi = (int32_t *) &(this->velocities[i]);
      int32_t exp_velocitiesi = (((*val_velocitiesi)>>23)&255);
      if(exp_velocitiesi != 0)
        exp_velocitiesi += 1023-127;
      int32_t sig_velocitiesi = *val_velocitiesi;
      *(outbuffer + offset++) = 0;
      *(outbuffer + offset++) = 0;
      *(outbuffer + offset++) = 0;
      *(outbuffer + offset++) = (sig_velocitiesi<<5) & 0xff;
      *(outbuffer + offset++) = (sig_velocitiesi>>3) & 0xff;
      *(outbuffer + offset++) = (sig_velocitiesi>>11) & 0xff;
      *(outbuffer + offset++) = ((exp_velocitiesi<<4) & 0xF0) | ((sig_velocitiesi>>19)&0x0F);
      *(outbuffer + offset++) = (exp_velocitiesi>>4) & 0x7F;
      if(this->velocities[i] < 0) *(outbuffer + offset -1) |= 0x80;
      }
      *(outbuffer + offset++) = accelerations_length;
      *(outbuffer + offset++) = 0;
      *(outbuffer + offset++) = 0;
      *(outbuffer + offset++) = 0;
      for( uint8_t i = 0; i < accelerations_length; i++){
      int32_t * val_accelerationsi = (int32_t *) &(this->accelerations[i]);
      int32_t exp_accelerationsi = (((*val_accelerationsi)>>23)&255);
      if(exp_accelerationsi != 0)
        exp_accelerationsi += 1023-127;
      int32_t sig_accelerationsi = *val_accelerationsi;
      *(outbuffer + offset++) = 0;
      *(outbuffer + offset++) = 0;
      *(outbuffer + offset++) = 0;
      *(outbuffer + offset++) = (sig_accelerationsi<<5) & 0xff;
      *(outbuffer + offset++) = (sig_accelerationsi>>3) & 0xff;
      *(outbuffer + offset++) = (sig_accelerationsi>>11) & 0xff;
      *(outbuffer + offset++) = ((exp_accelerationsi<<4) & 0xF0) | ((sig_accelerationsi>>19)&0x0F);
      *(outbuffer + offset++) = (exp_accelerationsi>>4) & 0x7F;
      if(this->accelerations[i] < 0) *(outbuffer + offset -1) |= 0x80;
      }
      *(outbuffer + offset++) = effort_length;
      *(outbuffer + offset++) = 0;
      *(outbuffer + offset++) = 0;
      *(outbuffer + offset++) = 0;
      for( uint8_t i = 0; i < effort_length; i++){
      int32_t * val_efforti = (int32_t *) &(this->effort[i]);
      int32_t exp_efforti = (((*val_efforti)>>23)&255);
      if(exp_efforti != 0)
        exp_efforti += 1023-127;
      int32_t sig_efforti = *val_efforti;
      *(outbuffer + offset++) = 0;
      *(outbuffer + offset++) = 0;
      *(outbuffer + offset++) = 0;
      *(outbuffer + offset++) = (sig_efforti<<5) & 0xff;
      *(outbuffer + offset++) = (sig_efforti>>3) & 0xff;
      *(outbuffer + offset++) = (sig_efforti>>11) & 0xff;
      *(outbuffer + offset++) = ((exp_efforti<<4) & 0xF0) | ((sig_efforti>>19)&0x0F);
      *(outbuffer + offset++) = (exp_efforti>>4) & 0x7F;
      if(this->effort[i] < 0) *(outbuffer + offset -1) |= 0x80;
      }
      *(outbuffer + offset + 0) = (this->time_from_start.sec >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (this->time_from_start.sec >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (this->time_from_start.sec >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (this->time_from_start.sec >> (8 * 3)) & 0xFF;
      offset += sizeof(this->time_from_start.sec);
      *(outbuffer + offset + 0) = (this->time_from_start.nsec >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (this->time_from_start.nsec >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (this->time_from_start.nsec >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (this->time_from_start.nsec >> (8 * 3)) & 0xFF;
      offset += sizeof(this->time_from_start.nsec);
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer)
    {
      int offset = 0;
      uint8_t positions_lengthT = *(inbuffer + offset++);
      if(positions_lengthT > positions_length)
        this->positions = (float*)realloc(this->positions, positions_lengthT * sizeof(float));
      offset += 3;
      positions_length = positions_lengthT;
      for( uint8_t i = 0; i < positions_length; i++){
      uint32_t * val_st_positions = (uint32_t*) &(this->st_positions);
      offset += 3;
      *val_st_positions = ((uint32_t)(*(inbuffer + offset++))>>5 & 0x07);
      *val_st_positions |= ((uint32_t)(*(inbuffer + offset++)) & 0xff)<<3;
      *val_st_positions |= ((uint32_t)(*(inbuffer + offset++)) & 0xff)<<11;
      *val_st_positions |= ((uint32_t)(*(inbuffer + offset)) & 0x0f)<<19;
      uint32_t exp_st_positions = ((uint32_t)(*(inbuffer + offset++))&0xf0)>>4;
      exp_st_positions |= ((uint32_t)(*(inbuffer + offset)) & 0x7f)<<4;
      if(exp_st_positions !=0)
        *val_st_positions |= ((exp_st_positions)-1023+127)<<23;
      if( ((*(inbuffer+offset++)) & 0x80) > 0) this->st_positions = -this->st_positions;
        memcpy( &(this->positions[i]), &(this->st_positions), sizeof(float));
      }
      uint8_t velocities_lengthT = *(inbuffer + offset++);
      if(velocities_lengthT > velocities_length)
        this->velocities = (float*)realloc(this->velocities, velocities_lengthT * sizeof(float));
      offset += 3;
      velocities_length = velocities_lengthT;
      for( uint8_t i = 0; i < velocities_length; i++){
      uint32_t * val_st_velocities = (uint32_t*) &(this->st_velocities);
      offset += 3;
      *val_st_velocities = ((uint32_t)(*(inbuffer + offset++))>>5 & 0x07);
      *val_st_velocities |= ((uint32_t)(*(inbuffer + offset++)) & 0xff)<<3;
      *val_st_velocities |= ((uint32_t)(*(inbuffer + offset++)) & 0xff)<<11;
      *val_st_velocities |= ((uint32_t)(*(inbuffer + offset)) & 0x0f)<<19;
      uint32_t exp_st_velocities = ((uint32_t)(*(inbuffer + offset++))&0xf0)>>4;
      exp_st_velocities |= ((uint32_t)(*(inbuffer + offset)) & 0x7f)<<4;
      if(exp_st_velocities !=0)
        *val_st_velocities |= ((exp_st_velocities)-1023+127)<<23;
      if( ((*(inbuffer+offset++)) & 0x80) > 0) this->st_velocities = -this->st_velocities;
        memcpy( &(this->velocities[i]), &(this->st_velocities), sizeof(float));
      }
      uint8_t accelerations_lengthT = *(inbuffer + offset++);
      if(accelerations_lengthT > accelerations_length)
        this->accelerations = (float*)realloc(this->accelerations, accelerations_lengthT * sizeof(float));
      offset += 3;
      accelerations_length = accelerations_lengthT;
      for( uint8_t i = 0; i < accelerations_length; i++){
      uint32_t * val_st_accelerations = (uint32_t*) &(this->st_accelerations);
      offset += 3;
      *val_st_accelerations = ((uint32_t)(*(inbuffer + offset++))>>5 & 0x07);
      *val_st_accelerations |= ((uint32_t)(*(inbuffer + offset++)) & 0xff)<<3;
      *val_st_accelerations |= ((uint32_t)(*(inbuffer + offset++)) & 0xff)<<11;
      *val_st_accelerations |= ((uint32_t)(*(inbuffer + offset)) & 0x0f)<<19;
      uint32_t exp_st_accelerations = ((uint32_t)(*(inbuffer + offset++))&0xf0)>>4;
      exp_st_accelerations |= ((uint32_t)(*(inbuffer + offset)) & 0x7f)<<4;
      if(exp_st_accelerations !=0)
        *val_st_accelerations |= ((exp_st_accelerations)-1023+127)<<23;
      if( ((*(inbuffer+offset++)) & 0x80) > 0) this->st_accelerations = -this->st_accelerations;
        memcpy( &(this->accelerations[i]), &(this->st_accelerations), sizeof(float));
      }
      uint8_t effort_lengthT = *(inbuffer + offset++);
      if(effort_lengthT > effort_length)
        this->effort = (float*)realloc(this->effort, effort_lengthT * sizeof(float));
      offset += 3;
      effort_length = effort_lengthT;
      for( uint8_t i = 0; i < effort_length; i++){
      uint32_t * val_st_effort = (uint32_t*) &(this->st_effort);
      offset += 3;
      *val_st_effort = ((uint32_t)(*(inbuffer + offset++))>>5 & 0x07);
      *val_st_effort |= ((uint32_t)(*(inbuffer + offset++)) & 0xff)<<3;
      *val_st_effort |= ((uint32_t)(*(inbuffer + offset++)) & 0xff)<<11;
      *val_st_effort |= ((uint32_t)(*(inbuffer + offset)) & 0x0f)<<19;
      uint32_t exp_st_effort = ((uint32_t)(*(inbuffer + offset++))&0xf0)>>4;
      exp_st_effort |= ((uint32_t)(*(inbuffer + offset)) & 0x7f)<<4;
      if(exp_st_effort !=0)
        *val_st_effort |= ((exp_st_effort)-1023+127)<<23;
      if( ((*(inbuffer+offset++)) & 0x80) > 0) this->st_effort = -this->st_effort;
        memcpy( &(this->effort[i]), &(this->st_effort), sizeof(float));
      }
      this->time_from_start.sec =  ((uint32_t) (*(inbuffer + offset)));
      this->time_from_start.sec |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      this->time_from_start.sec |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      this->time_from_start.sec |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      offset += sizeof(this->time_from_start.sec);
      this->time_from_start.nsec =  ((uint32_t) (*(inbuffer + offset)));
      this->time_from_start.nsec |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      this->time_from_start.nsec |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      this->time_from_start.nsec |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      offset += sizeof(this->time_from_start.nsec);
     return offset;
    }

    const char * getType(){ return "trajectory_msgs/JointTrajectoryPoint"; };
    const char * getMD5(){ return "f3cd1e1c4d320c79d6985c904ae5dcd3"; };

  };

}
#endif