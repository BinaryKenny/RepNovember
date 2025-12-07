#include "triangle.hpp"
#include <cmath>
#include <algorithm>
Triangle::Triangle(int x1, int y1, int x2, int y2, int x3, int y3):
Planar(),
data{Point(x1, y1), Point(x2, y2), Point(x3, y3)}
{}

int Triangle::x() const
{
  return 0;
}

int Triangle::y() const
{
  return 0;
}

int Triangle::abs_sqr() const
{
  return 0;
}

int Triangle::a() const
{
  int x = data[1].x() - data[0].x();
  int y = data[1].y() - data[0].y();
  return x * x + y * y;
}

int Triangle::b() const
{
  int x = data[2].x() - data[1].x();
  int y = data[2].y() - data[1].y();
  return x * x + y * y;
}

int Triangle::c() const
{
  int x = data[0].x() - data[2].x();
  int y = data[0].y() - data[2].y();
  return x * x + y * y;
}

double Triangle::area() const
{
  int p = a() + b() + c();
  return std::sqrt(p * (p - a()) * (p - b()) * (p - c()));
}

frame_t Triangle::frame() const
{
  int left_x = 0;
  int right_x = 0;
  int upper_y = 0;
  int lower_y = 0;
  left_x = std::min(data[0].x(), std::min(data[1].x(), data[2].x()));
  right_x = std::max(std::max(data[0].x(), data[1].x()), data[2].x());
  lower_y = std::min(data[0].y(), std::min(data[1].y(), data[2].y()));
  upper_y = std::max(std::max(data[0].y(), data[1].y()), data[2].y());
  return frame_t(left_x, lower_y, right_x, upper_y);
}

