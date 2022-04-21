#include "laba1.h"
int main(int arg,char** argv)
{
int count,T=0,j=0,flag=0;
char* options;
options=(char*)calloc(256,sizeof(char));
for(int i=0;i<4;i++)
{
    if(*(argv+2+i)!=NULL) 
    {
        do
        {
            if(*(*(argv+i+2)+j)!='-')
            {
            *(options+T)=*(*(argv+i+2)+j);
            j++;
            T++;
            }
            else j++;
        } while (*(*(argv+i+2)+j)!='\0');
        j=0;
    }
    else break;
}
if(arg>=3) mysort(options);
if(arg>=3)
{if(strcmp(options,"l" )==0)
    {
    dirwalk_ls(*(argv+1),argv,flag);
    }
else if(strcmp(options,"f" )==0)
{
   dirwalk_fs(*(argv+1),argv,flag);
}
else if(strcmp(options,"d" )==0)
{
    dirwalk_ds(*(argv+1),argv,flag);
}
else if(strcmp(options,"s" )==0)
{
   flag=1;
   dirwalk_s(*(argv+1),argv,flag);
   flag=0;
}
else if(strcmp(options,"fl" )==0)
{
    dirwalk_fs(*(argv+1),argv,flag);
    printf("\n\n\n\n");
    dirwalk_ls(*(argv+1),argv,flag);
}
else if(strcmp(options,"dl" )==0)
{
    dirwalk_ds(*(argv+1),argv,flag);
    printf("\n\n\n\n");
    dirwalk_ls(*(argv+1),argv,flag);
}
else if(strcmp(options,"ls" )==0)
{
    flag=1;
    dirwalk_ls(*(argv+1),argv,flag);
    flag=0;
}
else if(strcmp(options,"df" )==0)
{
    dirwalk_ds(*(argv+1),argv,flag);
    printf("\n\n\n\n");
    dirwalk_fs(*(argv+1),argv,flag);
}
else if(strcmp(options,"ds" )==0)
{
    flag=1;
     dirwalk_ds(*(argv+1),argv,flag);
     flag=0;
}
else if(strcmp(options,"fs" )==0)
{   
    flag=1;
    dirwalk_fs(*(argv+1),argv,flag);
    flag=0;
}
else if(strcmp(options,"dfl" )==0)
{
    dirwalk_ds(*(argv+1),argv,flag);
    printf("\n\n\n\n");
    dirwalk_fs(*(argv+1),argv,flag);
    printf("\n\n\n\n");
    dirwalk_ls(*(argv+1),argv,flag);
}
else if(strcmp(options,"dfs" )==0)
{
    flag=1;
    dirwalk_ds(*(argv+1),argv,flag);
    printf("\n\n\n\n");
    dirwalk_fs(*(argv+1),argv,flag);
    flag=0;
}
else if (strcmp(options,"dls")==0)
{
        flag=1;
    dirwalk_ds(*(argv+1),argv,flag);
    printf("\n\n\n\n");
    dirwalk_ls(*(argv+1),argv,flag);
    flag=0;
}
else if(strcmp(options,"fls")==0)
{   
    flag=1;
    dirwalk_fs(*(argv+1),argv,flag);
    printf("\n\n\n\n");
    dirwalk_ls(*(argv+1),argv,flag);
    flag=0;
}
else if(strcmp(options,"dfls" )==0)
{  
    flag=1;
    dirwalk_ds(*(argv+1),argv,flag);
    printf("\n\n\n\n");
    dirwalk_fs(*(argv+1),argv,flag);
    printf("\n\n\n\n");
    dirwalk_ls(*(argv+1),argv,flag);
    flag=0;
};
}
else if(arg<3) dirwalk_s(*(argv+1),argv,flag);
free(options);
return 0;
}
////////////////////////////////////////////////////////////////////////////
