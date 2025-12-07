#ifndef FUNCTIONS_HPP
#define FUNCTIONS_HPP
#include <iostream>
#include "planar.hpp"
#include "point.hpp"
#include "vector.hpp"
#include "triangle.hpp"
#include "frame_t.hpp"

Planar * make(std::istream & is);
Planar ** most_left(Planar ** pls, size_t k);
Planar * make(size_t id);
void draw(Planar * pl);
void draw(Triangle * pls);
void free_planars(Planar ** pls, size_t k);
Planar * max_area(Planar ** pls, size_t k);
frame_t crossing(frame_t obj1, frame_t obj2);
Planar ** max_crossing(Planar ** pls, size_t);
#endif
