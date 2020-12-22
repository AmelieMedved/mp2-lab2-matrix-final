#include <iostream>
#include "matrix.h"

int main()
{
  TMatrix <int> mtrx1(3), mtrx2(3), mtrx3(3);

  mtrx1[0][0] = 1; 
  mtrx1[0][1] = 2;
  mtrx1[0][2] = 2;
  mtrx1[1][0] = 1; 
  mtrx1[1][1] = 2;
  mtrx1[2][0] = 1;

  mtrx2[0][0] = 3;
  mtrx2[0][1] = 2;
  mtrx2[0][2] = 2;
  mtrx2[1][0] = 3;
  mtrx2[1][1] = 2;
  mtrx2[2][0] = 3;

  mtrx3[0][0] = 3;
  mtrx3[0][1] = 8;
  mtrx3[0][2] = 12;
  mtrx3[1][0] = 3;
  mtrx3[1][1] = 8;
  mtrx3[2][0] = 3;

  /*std::cout << mtrx1 << '\n' << mtrx2 << '\n' << mtrx3;*/

  cout << (mtrx3 == (mtrx1 * mtrx2));

  return 0;
}
