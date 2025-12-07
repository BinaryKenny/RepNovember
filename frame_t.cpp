#include "frame_t.hpp"
frame_t::frame_t(int x1, int y1, int x2, int y2):
AA(p_t(x1, y1)),
BB(p_t(x2, y2))
{}
double frame_t::area() const
{
  return (BB.x - AA.x) * (BB.y - AA.y);
}
