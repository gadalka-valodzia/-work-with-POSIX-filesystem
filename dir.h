
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include <string.h>
#include <dirent.h>
void dirwalk(char* way,char** argv)
{
    DIR* dr;
    char* ways;
    int point;

    struct dirent *ep;
    dr=opendir(way);
    if(dr!=NULL)
    {
        while((ep=readdir(dr))!=NULL)
        {
            if(ep->d_name[0] == '.') continue;
            point=strlen(way)+strlen(ep->d_name)+2;
            ways=(char*)calloc(point,sizeof(char));
            strcat(ways,way);
            strcat(ways,"/");
            strcat(ways,ep->d_name);
            printf("%s\n",ways);
            dirwalk(ways,argv);
        }
        (void) closedir (dr);
    }       
    else return;

    return;
}
////////////////////////////////////////////////////////////////////////////
 int dirwalk_f(char* way,char** argv)
 {
     
       DIR* dr;
     char* ways;
     int point;
     struct dirent *ep;
     dr=opendir(way);
     if(dr!=NULL)
     {
         while((ep=readdir(dr))!=NULL)
         {
             if(ep->d_name[0] == '.') continue;
             point=strlen(way)+strlen(ep->d_name)+2;
             ways=(char*)calloc(point,sizeof(char));
             strcat(ways,way);
             strcat(ways,"/");
             strcat(ways,ep->d_name);
             if(dirwalk_f(ways,argv)==0)continue;
                 else printf("%s\n",ways);
             dirwalk_f(ways,argv);
             free(ways);
         }
         (void) closedir (dr);
     }
     else return 1;
     return 0;
 }
 ////////////////////////////////////////////////////////////////////////////
 void dirwalk_s(char* way,char** argv,int flag1)
 {
      int size=0,i=0;
     DIR* dr;
     char** sort;
     int point=0;
     struct dirent *ep;
     dr=opendir(way);
     if(dr!=NULL)
     {
         while((ep=readdir(dr))!=NULL)
         {
             if(ep->d_name[0]=='.') continue;
             size++;
        }
         rewinddir(dr);
         sort=(char**)calloc(size,sizeof(char*));
         while((ep=readdir(dr))!=NULL)
         {
             if(ep->d_name[0]=='.') continue;
              point=strlen(ep->d_name)+strlen(way)+2;
                *(sort+i)=(char*)calloc(point,sizeof(char));
                strcat(*(sort+i),way);
                strcat(*(sort+i),"/");
                strcat(*(sort+i),ep->d_name);
                i++;
         }
         if(flag1==1)sortir(sort,size);
         for(int i=0;i<size;i++)
         {  
             dirwalk_s(*(sort+i),argv,flag1);
         }
         for(int i=0;i<size;i++)
         {  
             printf("%s\n",*(sort+i));
         }
         
        (void) closedir (dr);
    }
    else return;
    for(i=0;i<size;i++)
    {
        free(*(sort+i));
    }
    free(sort);
    
 }
 ////////////////////////////////////////////////////////////////////////////

    void dirwalk_ls(char* way,char** argv,int flag1)
 {
     int size=0,i=0;
     DIR* dr;char PAGENOK[1000-7];
     char** sort;int flag;
     int point=0;
     struct dirent *ep;
     dr=opendir(way);
     if(dr!=NULL)
     {
         while((ep=readdir(dr))!=NULL)
         {
             if(ep->d_name[0]=='.') continue;
             size++;
        }
         rewinddir(dr);
         sort=(char**)calloc(size,sizeof(char*));
         while((ep=readdir(dr))!=NULL)
         {
             if(ep->d_name[0]=='.') continue;
              point=strlen(ep->d_name)+strlen(way)+2;
                *(sort+i)=(char*)calloc(point,sizeof(char));
                strcat(*(sort+i),way);
                strcat(*(sort+i),"/");
                strcat(*(sort+i),ep->d_name);
                i++;
         }
         if(flag1==1) sortir(sort,size);
         for(int i=0;i<size;i++)
         {  
             dirwalk_ls(*(sort+i),argv,flag1);
         }
         for(int i=0;i<size;i++)
         {  
             flag=readlink(*(sort+i),PAGENOK,1000-7);
             if (flag!=-1)printf("%s\n",*(sort+i));
         }
         
        (void) closedir (dr);
    }
    else return;
    for(i=0;i<size;i++)
    {
        free(*(sort+i));
    }
    free(sort);
 }
////////////////////////////////////////////////////////////////////////////
 ////////////////////////////////////////////////////////////////////////////
 void sortir(char** a,int str)
{
    
int o1=0,o2=0,k=0;
char *temp;
    for(o1=0;o1<str;o1++)
        for(o2=o1+1;o2<str;o2++)
            for(k=0;k<1000-7;k++)
    {
        if(a[o1][k]==a[o2][k]) continue;
            else if(a[o1][k]>a[o2][k])
    {
        temp=*(a+o1);
        *(a+o1)=*(a+o2);
        *(a+o2)=temp;
        break;
    }
    else break;
    }
}
////////////////////////////////////////////////////////////////////////////
void mysort(char* str)
{
    char temp;
    int i=0;
for(int i=0;i<strlen(str)-1;i++)
    {
        if(*(str+i)>*(str+i+1))
        {
            temp=*(str+i);
            *(str+i)=*(str+i+1);
            *(str+i+1)=temp;
            i=0;
        }
    }
}
/////////////////////////////////////////////////////////////////////////////
 int dirwalk_ds(char* way,char** argv,int flag1)
 {
      int size=0,i=0;
     DIR* dr;
     char** sort;
     int point=0;
     struct dirent *ep;
     dr=opendir(way);
     if(dr!=NULL)
     {
         while((ep=readdir(dr))!=NULL)
         {
             if(ep->d_name[0]=='.') continue;
             size++;
         }
         rewinddir(dr);
         sort=(char**)calloc(size,sizeof(char*));
         while((ep=readdir(dr))!=NULL)
         {
             if(ep->d_name[0]=='.') continue;
              point=strlen(ep->d_name)+strlen(way)+2;
                *(sort+i)=(char*)calloc(point,sizeof(char));
                strcat(*(sort+i),way);
                strcat(*(sort+i),"/");
                strcat(*(sort+i),ep->d_name);
                i++;
         }
         if(flag1==1)sortir(sort,size);

         for(int i=0;i<size;i++)
         {  
             if(dirwalk_ds(*(sort+i),argv,flag1)==0)printf("%s\n",*(sort+i));
         }
         
        (void) closedir (dr);
    }
    else return 1;
    for(i=0;i<size;i++)
    {
        free(*(sort+i));
    }
    free(sort);
    return 0;
 }
  ////////////////////////////////////////////////////////////////////////////
 int  dirwalk_fs(char* way,char** argv,int flag1)
 {
      int size=0,i=0;
     DIR* dr;
     char** sort;
     int point=0;
     struct dirent *ep;
     dr=opendir(way);
     if(dr!=NULL)
     {
         while((ep=readdir(dr))!=NULL)
         {
             if(ep->d_name[0]=='.') continue;
             size++;
        }
         rewinddir(dr);
         sort=(char**)calloc(size,sizeof(char*));
         while((ep=readdir(dr))!=NULL)
         {
             if(ep->d_name[0]=='.') continue;
              point=strlen(ep->d_name)+strlen(way)+2;
                *(sort+i)=(char*)calloc(point,sizeof(char));
                strcat(*(sort+i),way);
                strcat(*(sort+i),"/");
                strcat(*(sort+i),ep->d_name);
                i++;
         }
         if(flag1==1)sortir(sort,size);
         for(int i=0;i<size;i++)
         {  
            if(dirwalk_fs(*(sort+i),argv,flag1)==1) printf("%s\n",*(sort+i));
         }
         
        (void) closedir (dr);
    }
    else return 1;
    for(i=0;i<size;i++)
    {
        free(*(sort+i));
    }
    free(sort);
    return 0;
    
 }

