#ifndef _ROS_geoff_msgs_GeoffPanTiltZoom_h
#define _ROS_geoff_msgs_GeoffPanTiltZoom_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"

namespace geoff_msgs
{

  class GeoffPanTiltZoom : public ros::Msg
  {
    public:
      typedef int16_t _pan_type;
      _pan_type pan;
      typedef int16_t _tilt_type;
      _tilt_type tilt;
      typedef int16_t _zoom_type;
      _zoom_type zoom;

    GeoffPanTiltZoom():
      pan(0),
      tilt(0),
      zoom(0)
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
      union {
        int16_t real;
        uint16_t base;
      } u_zoom;
      u_zoom.real = this->zoom;
      *(outbuffer + offset + 0) = (u_zoom.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_zoom.base >> (8 * 1)) & 0xFF;
      offset += sizeof(this->zoom);
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
      union {
        int16_t real;
        uint16_t base;
      } u_zoom;
      u_zoom.base = 0;
      u_zoom.base |= ((uint16_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_zoom.base |= ((uint16_t) (*(inbuffer + offset + 1))) << (8 * 1);
      this->zoom = u_zoom.real;
      offset += sizeof(this->zoom);
     return offset;
    }

    const char * getType(){ return "geoff_msgs/GeoffPanTiltZoom"; };
    const char * getMD5(){ return "634cfef94ff2ed7578db5f7d396288a4"; };

  };

}
#endif