#include"pcpy.h"

int check_arg(const char *SFile,int arg_num,int pronum)
{
   //源文件是否存在
    if((access(SFile,F_OK))!=0)
    {
      perror("Check_arg Error");
      exit(-1);
    }
   //参数数量是否满足
    if(arg_num<3)
    {
      printf("Cheak_arg Error :参数数量异常!\n");
      exit(-1);
    }
   //用户输入进程数是否溢出
    if(pronum<=0 ||pronum>=100)
    {
      printf("Check_arg Error :进程数要大于0或小于100\n");
      exit(-1);
    }

  return 0;
  
}