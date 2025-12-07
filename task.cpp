#include <iostream>
#include "functions.hpp"
#include "point.hpp"
#include "planar.hpp"
int main()
{
  size_t s = 0;
  size_t c = 20;
  Planar ** pls = new Planar*[c];
  while (std::cin)
  {
    Planar *pl = nullptr;
    try
    {
      pl = make(std::cin);
      if (s == c)
      {
        Planar ** epls = new Planar * [c * 2];
        for (size_t i = 0; i < s; ++i)
        {
          epls[i] = pls[i];
        }
        delete [] pls;
        pls = epls;
        c *= 2;
      }
      pls[s++] = pl;
    }
    catch(...)
    {
      delete pl;
      free_planars(pls, s);
      delete [] pls;
      return 2;
    }
  }
  if (!std::cin.eof())
  {  
    free_planars(pls, s);
    delete [] pls;
    return 3;
  }
  else
  { 
    Planar ** ml = most_left(pls, s);
    if (ml == pls + s)
    {
      std::cout << "Not found";
      free_planars(pls, s);
      delete [] pls;
      return 0;
    }
    else
    {
    draw(*ml);
    std::cout << "\n";
    Planar * figure = nullptr;
    figure = max_area(pls, s);
    draw(figure);
    std::cout << "\n";
    Planar ** array = nullptr;
    array = max_crossing(pls, s);
    draw(array[0]);
    std::cout << "\n";
    draw(array[1]);
    free_planars(pls, s);
    delete [] pls;
    delete [] array;
    }
  }
}
