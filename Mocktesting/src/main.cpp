/***/

#include <iostream>
#include "header.h"

int main() {
  Add obj;
  int c = 0;
  c = obj.add(2, 3);
  std::cout << "Output " << c << std::endl;
  return 0;
}
