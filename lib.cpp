#include "lib.h"
#include "version.h"

int library1::version()
{
  return PROJECT_VERSION_PATCH;
}

int library1::square(int x)
{
  return x * x;
}
