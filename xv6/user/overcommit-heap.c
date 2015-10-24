#include "types.h"
#include "user.h"
#include "fs.h"
#include "fcntl.h"
#include "syscall.h"

#define PGSIZE 4096
#define PGNUM 160

void
grow_heap(int n) {
  while (n > 0) {
    --n;
    char *growth;
    growth = malloc(PGSIZE);
  }
}

int
main(int argc, char *argv[])
{
  printf(1, "overcommit-heap test\n");
  char *old = sbrk(0);
  printf(1, "Guard page at: %x\n", old + PGSIZE);
  grow_heap(50);
  printf(1, "50 page heap growth success.\n");
  //char *cur = sbrk(0);
  /*if (cur < old + 50 * PGSIZE || cur > old + 51 * PGSIZE) {
    printf(1, "error: unexpected heap addr %x\n", cur);
    exit();
  }*/
  int rd = fork();
  if (rd == 0) {
    grow_heap(PGNUM - 50 + 1);
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
