#ifndef VECTOR_HPP
#define VECTOR_HPP
#include <cmath>
#include <algorithm>
#include "planar.hpp"
#include "point.hpp"
#include "frame_t.hpp"

struct Vector : Planar
{
  virtual int x() const;
  virtual int y() const;
  virtual int abs_sqr() const;
  virtual double area() const;
  virtual frame_t frame() const;
  Vector (int x1, int y1, int x2, int y2);
  virtual ~Vector() = default;
private:
  Point data[2];
};

#endif
