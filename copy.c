#include "pcpy.h"

int main(int argc,char* argv[])
{
//argv[1]源文件 argv[2]目标文件 argv[3]blocksize argv[4]pos偏移量
  int pos=atoi(argv[4]);
  int blocksize=atoi(argv[3]);
  char buffer[blocksize];
  bzero(buffer,sizeof(blocksize));

  int sfd=open(argv[1],O_RDONLY);
  int dfd=open(argv[2],O_WRONLY|O_CREAT,0664);
  lseek(sfd,pos,SEEK_SET);
  lseek(dfd,pos,SEEK_SET);
  printf("Copy ChildPro pid[%d] pos[%d] block[%d]\n",getpid(),pos,blocksize);
  
  int nlen;
  nlen=read(sfd,buffer,sizeof(buffer));
  write(dfd,buffer,nlen);
  printf(" 拷贝完成...\n"); 
  return 0;
}