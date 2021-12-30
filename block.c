#include"pcpy.h"

int block(const char *SFile,int pronum)
{
  int Filesize;
  int fd=open(SFile,O_RDONLY);
  Filesize=lseek(fd,0,SEEK_END);
  if((Filesize%pronum)==0)
  {
    return Filesize/pronum;
  }
  else
  {
    return Filesize/pronum +1;
  }
}