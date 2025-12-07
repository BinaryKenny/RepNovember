#ifndef FRAME_T_HPP
#define FRAME_T_HPP
#include "p_t.hpp"
struct frame_t
{
  p_t AA, BB;
  double area() const;
  frame_t(int x1, int y1, int x2, int y2);
};
#endif
