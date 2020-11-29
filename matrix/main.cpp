#include <iostream>
#include "matrix.h"

int main()
{
  std::cout << '\n' << "####################_init_sum_out_out-index_####################" << '\n' << '\n';

  TMatrix<int> a(9);
  TMatrix<int> b(9);
  TMatrix<float> af(9);
  TMatrix<float> bf(9);
  TMatrix<float> cf(99);
  TMatrix<int> d(100);
  TMatrix<int> c(b);
  TMatrix<int> a0;

  TMatrix<float> af0;
  c = c + a + b;

  std::cout << c << '\n';
  std::cout << a[0] << '\n';
  std::cout << a0 << '\n';
  std::cout << af0 << '\n';

  d = c - a - b;
  c = c - b - a;
  std::cout << d << '\n';
  std::cout << c << '\n';

  std::cout << '\n' << "####################_set-element_####################" << '\n' << '\n';

  a[4][4] = 1;
  std::cout << a[4][4] << '\n';

  std::cout << '\n' << "####################_not-equal_equal_####################" << '\n' << '\n';

  std::cout << (a != d) << '\n'; //true
  std::cout << (af != bf) << '\n'; //false
  std::cout << (af == bf) << '\n'; //true
  std::cout << (af == cf) << '\n'; //false
  std::cout << (a != b) << '\n'; //false
  std::cout << (a == c) << '\n'; // true
  std::cout << (b == c) << '\n'; // true
  std::cout << (c != c) << '\n'; // false

  std::cout << '\n' << "####################_cycle_and_index_####################" << '\n' << '\n';

  TMatrix<int> a1(5);

  std::cout << a1.GetSize() << '\n';

  for (int i = 0; i < a1.GetSize(); i++)
    for (int j = i; j < a1.GetSize(); j++)
      a1[i][j] = i + j;

  std::cout << a1 << '\n';

  return 0;
}
