#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/types.h>

int main(int argc,char* argv[]){
   char* arg[]={"touch","file1.txt",NULL};
   execvp("touch",arg);
}