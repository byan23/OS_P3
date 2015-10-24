#include "types.h"
#include "user.h"
#include "fs.h"
#include "fcntl.h"
#include "syscall.h"

int
main(int argc, char *argv[])
{
  int array[100];
  int i;
  for (i = 0; i < 100; ++i)
    array[i] = i;
  char c_array[11];
  for (i = 0; i < 10; ++i)
    c_array[i] = 'y';
  c_array[i] = 0;
  int fd = open("test_small_stack", O_CREATE|O_RDWR);
  if (fd >= 0) {
    if (write(fd, c_array, 11) != 11) {
      printf(1, "error: writing error.\n");
      exit();
    }
  } else {
    printf(1, "error: open file failure.\n");
    exit();
  }
  close(fd);
  fd = open("test_small_stack", O_RDWR);
  char buf[10];
  int rd = read(fd, buf, 10);
  if (rd == 10) {
    for (i = 0; i < 10; ++i) {
      if (buf[i] != 'y') {
	printf(1, "write in wrong stuff...\n");
	printf(1, "wrote 'y', received %c (at %d byte)...\n", buf[i], i);
	exit();
      }
    }
    printf(1, "PASSED\n");
  } else {
    printf(1, "error: should read 10 bytes, actually reads %d bytes...\n",
	   rd);
    exit();
  }
  exit();
}
