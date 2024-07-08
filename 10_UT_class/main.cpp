/**
 *  Seperate header.h header.cpp main.cpp headertest.cpp
 *  Perform Gtest and run executable file
 *  g++ main.cpp header.cpp
 *  ./a.out
 *  g++ headertest.cpp header.cpp -o gtestout -lgtest -lgtest_main -pthread -L/home/t0101u7/05_UnitTest_Tutorial/Tutorial_Gtest/library/ -I/home/t0101u7/05_UnitTest_Tutorial/Tutorial_Gtest/library/
 *  ./gtestout
 *
 */
#include <iostream>
#include "header.h"

using namespace std;

int main() {
  int c = add(2, 3);
  std::cout << "Addition value : " << c << std::endl;
  return 0;
}
