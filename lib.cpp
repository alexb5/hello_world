#include "lib.h"
#include "version.h"

int library1::version()
{
  return PRODUCT_VERSION;
}

int library1::square(int x)
{
  return x * x;
}
