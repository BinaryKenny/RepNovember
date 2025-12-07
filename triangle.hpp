#ifndef TRIANGLE_HPP
#define TRIANGLE_HPP
#include "planar.hpp"
#include "point.hpp"
struct Triangle: Planar
{
  Triangle(int x1, int y1, int x2, int y2, int x3, int y3);
  virtual ~Triangle() = default;
  virtual double area() const;
  virtual int x() const;
  virtual int y() const;
  virtual int abs_sqr() const;
  virtual frame_t frame() const;
  int a() const;
  int b() const;
  int c() const;
private:
  Point data[3];
};
#endif
