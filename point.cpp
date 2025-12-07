#include <iostream>
#include <cmath>
#include "point.hpp"

Point::Point(int xx, int yy):
  Planar(),
  data{xx, yy}
{}
int Point::x() const
{
  return data[0];
}

int Point::y() const
{   
  return data[1];
}  

int Point::abs_sqr() const
{
  return std::sqrt(x() * x() + y() * y());
}

double Point::area() const
{
  return 0;
}

frame_t Point::frame() const
{
  return frame_t(data[0], data[1], x(), y());
}
