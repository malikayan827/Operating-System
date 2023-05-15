#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>



void *print_hello(void *thread_id) {
    printf("hello world");
    printf("%ld",pthread_self());
    return NULL;
}

int main() {

   pthread_t threadid;
    pthread_create(&threadid, NULL, print_hello, NULL);
   pthread_join(threadid, NULL);

    return 0;
}
