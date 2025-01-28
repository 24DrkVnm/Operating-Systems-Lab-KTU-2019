#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<sys/types.h>
#include<sys/stat.h>
void main()
{
char *path,path1[10];
struct stat*nfile;
nfile=(struct stat*)malloc(sizeof(struct stat));
printf("Enter the file name");
scanf("%s",path1);
stat(path1,nfile);
printf("User ID: %d\n",nfile->st_uid);
printf("BlockSize %ld\n",nfile->st_blksize);
printf("Mode %d\n",nfile->st_mode);
printf("AccessTime%ld\n",nfile->st_atime);
printf("Nlink %ld\n",nfile->st_nlink);
printf("Size %ld\n",nfile->st_size);
printf("Modified time %ld\n",nfile->st_mtime);

}
