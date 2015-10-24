#include "types.h"
#include "user.h"
#include "fs.h"
#include "fcntl.h"
#include "syscall.h"
#include "param.h"

int
main(int argc, char *argv[])
{
  char *p = (char*) (USERTOP - 0x1000 - 0x1000 - 0x5);
  open(p, O_CREATE|O_RDWR);
  exit();
}
