#include "get_DPI_scale.hpp"

#if defined(__unix__)

#include <X11/Xlib.h>

float get_DPI_scale()
{
  Display* display = XOpenDisplay(nullptr);
  const int width = XDisplayWidth(display, 0);
  const int widthMM = XDisplayWidthMM(display, 0);
  XCloseDisplay(display);
  return width/(92*0.0393700787402f*widthMM);
}

#else

#error "Platform implementation missing"

#endif
