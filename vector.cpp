#include <cmath>
#include "vector.hpp"

Vector::Vector(int x1, int y1, int x2, int y2):
Planar(),
data{Point(x1, y1), Point(x2, y2)}
{}

int Vector::x() const
{
  return data[1].x() - data[0].x();
}

int Vector::y() const
{
  return data[1].y() - data[0].y();
}

int Vector::abs_sqr() const
{
  return std::sqrt(x() * x() + y() * y());
}

double Vector::area() const
{
  return 0;
}

frame_t Vector::frame() const
{
  int left_x = 0;
  int right_x = 0;
  int upper_y = 0;
  int lower_y = 0;
  left_x = std::min(data[0].x(), data[1].x());
  lower_y = std::min(data[0].y(), data[1].y());
  right_x = std::max(data[0].x(), data[1].x());
  upper_y = std::max(data[0].y(), data[1].y());
  return frame_t(left_x, lower_y, right_x, upper_y);
}
