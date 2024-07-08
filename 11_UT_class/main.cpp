/**
 *  Class is used in header files
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
  calculator obj;  // create Normal Object
  int c = obj.add(2, 3);
  std::cout << "Using Normal Obj call add function Addition value : " << c << std::endl;

  calculator *pobj = nullptr;
  int pc = pobj->add(2, 3);
  std::cout << "Using pointer Obj call add function Addition value : " << pc << std::endl;

  return 0;
}
