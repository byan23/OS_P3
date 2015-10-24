#include "types.h"
#include "user.h"
#include "fs.h"
#include "fcntl.h"
#include "syscall.h"
#include "param.h"

int
main(int argc, char *argv[])
{
  int rd = fork();
  if (rd == 0) {
    int *p = (int*)(USERTOP - 3*4096 - 100);
    *p = 100;
    //printf(1, "value at addr: %d %x \n", p, p);
    //printf(1, "the int is %d\n", *p);
  } else if (rd > 0) {
    wait();
    printf(1, "PASSED.\n");
  } else {
    printf(1, "FORK FAILURE.\n");
  }
  exit();
}
