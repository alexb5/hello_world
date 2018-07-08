#include <iostream>
#include "lib.h"

int main()
{
  std::cout << "Hello World!" << std::endl;
  std::cout << "Version " << library1::version() << std::endl;
  return 0;
}
