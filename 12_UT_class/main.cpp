/**
 *  GMOCK is Used
 *  Make sure installed Libraries gmock gtest
 *  Class is used in header files
 *  Seperate header.h header.cpp main.cpp headertest.cpp
 *  Perform Gtest and run executable file
 *  g++ main.cpp header.cpp
 *  ./a.out
  g++ headertest.cpp header.cpp -o gtestout -lgtest -lgmock -lgtest_main -lgmock_main -pthread -L/home/t0101u7/05_UnitTest_Tutorial/Tutorial_Gtest/library/
  -I/home/t0101u7/05_UnitTest_Tutorial/Tutorial_Gtest/library/
 * ./gtestrout
 */

/*  This output came but struck at infinity cursor is continuously blinking ... even comment defintion in header.cpp
    I think we need to use Interface
 */
#include <iostream>
#include "header.h"

using namespace std;

int main() {
  int c = add(2, 3);
  std::cout << "Addition value : " << c << std::endl;

  return 0;
}

/***Both Should Work Preferred 1st Command only*/
/*
g++ headertest.cpp -o a.out -lgtest -lgtest_main -lgmock -pthread -L/home/t0101u7/05_UnitTest_Tutorial/Tutorial_Gtest/library/ -I/home/t0101u7/05_UnitTest_Tutorial/Tutorial_Gtest/library/
g++ header.cpp headertest.cpp -o a.out -lgtest -lgtest_main -lgmock -pthread -L/home/t0101u7/05_UnitTest_Tutorial/Tutorial_Gtest/library/ -I/home/t0101u7/05_UnitTest_Tutorial/Tutorial_Gtest/library/
*/