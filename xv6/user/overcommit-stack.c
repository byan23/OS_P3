#include "types.h"
#include "user.h"
#include "fs.h"
#include "fcntl.h"
#include "syscall.h"

#define PGSIZE 4096
#define PGNUM 160

int
main(int argc, char *argv[])
{
  int i;
  printf(1, "overcommit-stack test\n");
  char *cur = sbrk(0);
  printf(1, "Guard page at: %x\n", cur + PGSIZE);
  for (i = 0; i < 50; ++i) {
    char growth1[PGSIZE];
    growth1[0] = growth1[0];
  }
  printf(1, "50 page stack growth success.\n");
  int rd = fork();
  if (rd == 0) {
    for (i = 0; i < PGNUM - 50 + 1; ++i) {
      char growth2[PGSIZE];
      growth2[0] = growth2[0];
    }
    printf(1, "FAILED.\n");
    exit();
  } else if (rd > 0) {
    wait();
    printf(1, "PASSED.\n");
  } else {
    printf(1, "FORK FAILURE.\n");
  }
  
  exit();
}
