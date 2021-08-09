#ifndef _ROS_geoff_msgs_GeoffPanTilt_h
#define _ROS_geoff_msgs_GeoffPanTilt_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"

namespace geoff_msgs
{

  class GeoffPanTilt : public ros::Msg
  {
    public:
      typedef int16_t _pan_type;
      _pan_type pan;
      typedef int16_t _tilt_type;
      _tilt_type tilt;

    GeoffPanTilt():
      pan(0),
      tilt(0)
    {
    }

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      union {
        int16_t real;
        uint16_t base;
      } u_pan;
      u_pan.real = this->pan;
      *(outbuffer + offset + 0) = (u_pan.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_pan.base >> (8 * 1)) & 0xFF;
      offset += sizeof(this->pan);
      union {
        int16_t real;
        uint16_t base;
      } u_tilt;
      u_tilt.real = this->tilt;
      *(outbuffer + offset + 0) = (u_tilt.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_tilt.base >> (8 * 1)) & 0xFF;
      offset += sizeof(this->tilt);
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer)
    {
      int offset = 0;
      union {
        int16_t real;
        uint16_t base;
      } u_pan;
      u_pan.base = 0;
      u_pan.base |= ((uint16_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_pan.base |= ((uint16_t) (*(inbuffer + offset + 1))) << (8 * 1);
      this->pan = u_pan.real;
      offset += sizeof(this->pan);
      union {
        int16_t real;
        uint16_t base;
      } u_tilt;
      u_tilt.base = 0;
      u_tilt.base |= ((uint16_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_tilt.base |= ((uint16_t) (*(inbuffer + offset + 1))) << (8 * 1);
      this->tilt = u_tilt.real;
      offset += sizeof(this->tilt);
     return offset;
    }

    const char * getType(){ return "geoff_msgs/GeoffPanTilt"; };
    const char * getMD5(){ return "e5401181ff33a9d514daeb8a647b3152"; };

  };

}
#endif