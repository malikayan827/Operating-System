#include <stdio.h>
#include <stdlib.h>

int main(){

    int fd[2];

    char message[20]={"Hello World"};
    char message2[20]={"Mushaim"};
    char output[20];

    pipe(fd);
    if(pipe(fd)==-1){
        exit(EXIT_FAILURE);
    }
    else{
        write(fd[1],message,sizeof(message));
        read(fd[0],output,sizeof(output));
        printf("%s\n",output);
        write(fd[1],message2,sizeof(message2));
        read(fd[0],output,sizeof(output));
        printf("%s\n",output);
        exit(EXIT_SUCCESS);
    }
}