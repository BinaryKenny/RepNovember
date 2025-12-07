#include <iostream>
#include "functions.hpp"
void free_planars(Planar ** pls, size_t k)
{
  for (size_t i = 0; i < k; ++i)
  {
    delete pls[i];
  }
}
void draw(Planar * pls)
{
  std::cout << pls->x();
  std::cout << " ";
  std::cout << pls->y() << "\n";
}

void draw(Triangle * pls)
{
  std::cout << pls->a() << " " << pls->b() << " " << pls->c();
}

Planar ** most_left(Planar ** pls, size_t k)
{
  if (!k)
  {
    return pls;
  }
  Planar ** res = pls;
  while (--k)
  {
    int next_x = (*(++pls))->x();
    int curr_x = (*res)->x();
    if (next_x < curr_x)
    {
      res = pls;
    }
  }
  return res;
}

Planar * make(size_t id)
{
  Planar * r = nullptr;
  switch(id)
  {
    case 0:
      r = new Point(0,0);
      break;
    default:
      throw std::logic_error("bad id");
  }
  return r;
}

Planar * make(std::istream & is)
{
  char cmd[2] = {};
  is >> cmd[0] >> cmd[1];
  int data[4] = {};
  if (cmd[0] == 'P' && cmd[1] == 'T')
  {
    if (is >> data[0] >> data[1])
    {
      return new Point(data[0], data[1]);
    }
  }
  else if (cmd[0] == 'V' && cmd[1] == 'T')
  {
    if (is >> data[0] >> data[1] >> data[2] >> data[3])
    {
      return new Vector(data[0], data[1], data[2], data[3]);
    }
  }
  else
  {
    throw std::logic_error("Bad cmd");
  }
  return nullptr;
}
Planar * max_area(Planar ** pls, size_t k)
{
  size_t index = 0;
  double max_area = 0;
  for (size_t i = 0; i < k; i++)
  {
    max_area = std::max(max_area, pls[i]->area());
  }
  for (size_t i = 0; i < k; i++)
  {
    if (max_area == pls[i]->area())
    {
      index = i;
    }
  }
  return pls[index];
}
frame_t crossing(frame_t obj1, frame_t obj2)
{
  int left_x = 0;
  int right_x = 0;
  int lower_y = 0;
  int upper_y = 0;
  left_x = std::max(obj1.AA.x, obj2.AA.x);
  right_x = std::min(obj1.BB.x, obj2.BB.x);
  lower_y = std::max(obj1.AA.y, obj2.AA.y);
  upper_y = std::min(obj1.BB.y, obj2.AA.y);
  if (left_x >= right_x || lower_y >= upper_y)
  {
    return frame_t(0,0,0,0);
  }
  return frame_t(left_x, lower_y, right_x, upper_y);
}
Planar ** max_crossing (Planar ** pls, size_t k)
{
  double max_area = 0;
  Planar ** array = new Planar * [2];
  size_t index1 = 0, index2 = 0;
  for (size_t i = 0; i < k; i++)
  {
    for (size_t j = 0; j < k; ++j)
    {
      if (i == j)
      {
        continue;
      }
      double area = crossing(pls[i]->frame(), pls[j]->frame()).area();
      max_area = std::max(area, max_area);
    }
  }
  for (size_t i = 0; i < k; ++i)
  {
    for (size_t j = 0; j < k; j++)
    {
      if (max_area == crossing(pls[i]->frame(), pls[j]->frame()).area())
      {
        index1 = i;
        index2 = j;
      }
    }
  }
  array[0] = pls[index1];
  array[1] = pls[index2];
  return array;
}
