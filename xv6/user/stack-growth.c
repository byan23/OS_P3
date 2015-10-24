#include "types.h"
#include "user.h"
#include "fs.h"
#include "fcntl.h"
#include "syscall.h"
#include "param.h"

#define ASIZE 1500
#define PGSIZE 4096
void funcA() {
  char A[ASIZE];
  int i;
  for (i = 0; i < ASIZE; ++i)
    A[i] = 'a';
  if ((int)&A[ASIZE-1] < USERTOP - PGSIZE * 2 ||
      (int)&A[0] > USERTOP - PGSIZE) {
    printf(1, "A starts at: %d, ends at: %d\n", (int)&A[0], (int)&A[ASIZE-1]);
    printf(1, "unreasonable addr in A...\n");
    exit();  
  }
}

void funcB() {
  // call A
  char B[ASIZE];
  int i;
  for (i = 0; i < ASIZE; ++i)
    B[i] = 'b';
  /*if (&A[0] < USERTOP - PGSIZE) {
    printf(1, "unreasonable addr in A...\n");
    exit();  
  }*/
  funcA();
}

void funcC() {
  // call B
  char C[ASIZE];
  int i;
  for (i = 0; i < ASIZE; ++i)
    C[i] = 'c';
  if ((int)&C[0] < USERTOP - PGSIZE) {
    printf(1, "unreasonable addr in C...\n");
    exit();  
  }
  funcB();
}


int
main(int argc, char *argv[])
{
  funcC(); 
  printf(1, "PASSED\n");
  exit();
}
