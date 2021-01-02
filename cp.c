#include "types.h"
#include "stat.h"
#include "user.h"
#include "fcntl.h"

char buf[512];

int
main(int argc, char *argv[])
{
  int fd, tfd, data;

  if(argc <= 2){
    printf(1, "Please include the destination file name\n");
    exit();
  }

  if((fd = open(argv[1], O_RDWR)) < 0){
    printf(1, "cp: cannot open %s\n", argv[1]);
    exit();
  }

  if((tfd = open(argv[2], O_CREATE | O_RDWR)) < 0){
    printf(1, "cp: cannot open %s\n", argv[2]);
    exit();
  }

  while((data = read(fd, buf, sizeof(buf))) > 0){
	write(tfd, buf, data);
  }

  close(fd);
  close(tfd);
  exit();
}
