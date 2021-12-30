#include"pcpy.h"


int procreate(const char *SFile,const char *DFile,int pronum,int blocksize)
{
   int flag;
   pid_t pid;
   
   char cblock[10];
   char cpos[10];
   bzero(cblock,sizeof(cblock));
   bzero(cpos,sizeof(cpos));

   for(flag=0;flag<pronum;flag++)
   {
     pid=fork();
     if(pid==0)
      break;
   }
   if(pid>0)
   {
     printf("Parent pro pid[%d] 非阻塞回收...\n",getpid());
     pid_t zpid;
     while((zpid=waitpid(-1,NULL,WNOHANG))!=-1)
     {
       if(zpid>0)
       {
         printf("Parent Wait Success:zombie pid[%d]\n",zpid);
       }
     }
   }
   else if(pid==0)
   {
     //偏移量pos计算
     int pos=flag*blocksize;
     sprintf(cblock,"%d",blocksize);
     sprintf(cpos,"%d",pos);
     //重载
     execl("/home/zyt/0322晚班Linux/1228test/processcopy/copy","./copy",SFile,DFile,cblock,cpos,NULL);
   }
   else
   {
     perror("FORK CALL FAILED");
     exit(-1);
   }

   return 0;

}