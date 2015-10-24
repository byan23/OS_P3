#include "types.h"
#include "user.h"
#include "fs.h"
#include "fcntl.h"
#include "syscall.h"

int
main(int argc, char *argv[])
{
  int i;
  int *int_on_heap = malloc(sizeof(int) * 100);
  for (i = 0; i < 100; ++i) int_on_heap[i] = i;
  for (i = 0; i < 100; ++i)
    if (int_on_heap[i] != i) {
      printf(1, "FAILED: incorrect value on heap.\n");
      printf(1, "expecting %d, received: %d.\n", int_on_heap[i], i);
      exit();
    }
  printf(1, "int_on_heap ranges from %x to %x.\n",
	 &int_on_heap[0], &int_on_heap[99]);
  printf(1, "PASSED.\n");
  exit();
}
