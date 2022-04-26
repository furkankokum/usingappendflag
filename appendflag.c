
#include<sys/types.h>
#include<sys/stat.h>
#include<fcntl.h>
#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>

#define FILE_MODE       (S_IRUSR | S_IWUSR | S_IRGRP | S_IROTH)

int main(int argc,char *argv[]){
if (argc!=2){
        printf("need enter a file name .\n");
        exit(-1);
}
int n;
int fd=open(argv[1],O_WRONLY|O_CREAT|O_TRUNC,FILE_MODE);
        if(fd<0){
        printf("file open error\n");
        exit(-2);
        }
char buf[30]="this file create new.\n";
if(n=write(fd,buf,sizeof(buf)-1)<0){
        printf("write error\n");
        exit(-3);
}
close(fd);
fd=open(argv[1],O_WRONLY|O_APPEND,FILE_MODE);
char buf2[30]="second line of file\n";
if(n=write(fd,buf2,sizeof(buf2)-1)<0){
        printf("write error");
        exit(-4);
}

