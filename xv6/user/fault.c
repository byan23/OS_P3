#include "types.h"
#include "user.h"

int
main(int argc, char *argv[])
{
  int *p = 0;
  printf(1, "Dereferencing a NUll: %x\n", *p);
  exit();
}
