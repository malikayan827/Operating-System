#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>


int main(int argc, char *argv[]) {
   char *file1 = argv[1];
   char * file2= argv[2];
    int f1 = open(file1, O_RDONLY,0777);
    int f2 = creat(file2, 0777);
    size_t num_read;
    char buffer[1024];
    while((num_read=read(f1,buffer,1))>0){
        ssize_t num_written = write(f2, buffer, num_read);


    }
    close(f1);
    close(f2);
    remove(file1);
}
