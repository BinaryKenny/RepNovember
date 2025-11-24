#ifndef FUNCTIONS_HPP
#define FUNCTIONS_HPP
#include <iostream>
#include "planar.hpp"
#include "point.hpp"

Planar * make(std::istream & is);
Planar * most_left(Planar ** pls, size_t k);
Planar * make(size_t id);
void draw(Planar * pl);
void free_planars(Planar ** pls, size_t k);

#endif
