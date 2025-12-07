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
