//program to create child process
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/types.h>
int main(){
    pid_t q;
    q=fork();
    if(q==0){
        sleep(3);
        printf("Child having pid %d\n",getpid());
        printf("Child's parent having pid %d\n",getppid());
    }
    else{
        wait(NULL);//only used in parent process
        printf("Parent having pid %d\n",q);
        printf("Parent's parent having pid %d\n",getpid());
    }
}