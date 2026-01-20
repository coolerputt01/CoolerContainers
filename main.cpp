/* Custom C++ CLArray type by Coolerputt  */

#include <algorithm>
#include <initializer_list>
#include <iostream>
#include <cassert>
#include "src/array/CLArray.hpp"

int main() {
  CLArray<int, 4> array = {1, 2};

  int g = 9;
  array.push_back(g);
  array.print();
  std::cout << array.back()<< std::endl << std::flush;

  return 0;
}
