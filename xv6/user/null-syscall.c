#include "types.h"
#include "user.h"
#include "fs.h"
#include "fcntl.h"
#include "syscall.h"

int
main(int argc, char *argv[])
{
  char *p = 0;
  open(p, O_CREATE|O_RDWR);
  exit();
}
