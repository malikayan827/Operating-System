#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <stdbool.h>

#define buffer_size 5

pthread_mutex_t mutex;
int buffer[buffer_size];
int in = 0;
int out = 0;
bool full = false;
bool empty = true;

void *producer() {
   
        pthread_mutex_lock(&mutex);
        if (full) {
            printf("Buffer is full\n");
            pthread_mutex_unlock(&mutex);
          
            return 0;
        }
        while(!full){
                int item = rand() % 100;
        buffer[in] = item;
        printf("Producer produced %d at %d\n", item, in);
        in = (in + 1) % buffer_size;
        if (in == out) {
            full = true;
            empty = false;
        }
       
        pthread_mutex_unlock(&mutex);}
        
    
    return NULL;
}

void *consumer() {
    
        pthread_mutex_lock(&mutex);
        if (empty) {
            printf("Buffer is empty\n");
            pthread_mutex_unlock(&mutex);
            
           return 0;
        }
        while(!empty){
        int item = buffer[out];
        printf("Consumer consumed %d at %d\n", item, out);
        out = (out + 1) % buffer_size;
        if (out == in) {
            full = false;
            empty = true;
        }
        
        pthread_mutex_unlock(&mutex);}
      
    
    return NULL;
}

int main() {
    pthread_t producer_thread, consumer_thread;
    pthread_mutex_init(&mutex, NULL);
    srand(time(NULL));

    pthread_create(&producer_thread, NULL, producer, NULL);
    pthread_create(&consumer_thread, NULL, consumer, NULL);

    pthread_join(producer_thread, NULL);
    pthread_join(consumer_thread, NULL);

    pthread_mutex_destroy(&mutex);

    return 0;
}
