#include <iostream>

struct Planar
{
  virtual int x() const = 0;
  virtual int y() const = 0;
  virtual int abc_sqr() const = 0;
  virtual ~Planar() = default;
};

Planar * make(std::istream & is);
Planar * most_left(Planar ** pls, size_t k);

int main()
{
  Planar * pls[10] = {};
  size_t k = 0;
  //pls[k++] = make(std::cin);
  //Planar * left = most_left(pls, k);
  //draw(left);
  //free_planars(pls,k);
}
