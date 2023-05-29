#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <stdbool.h>

#define buffer_size 5

pthread_mutex_t mutex;
pthread_cond_t empty;
pthread_cond_t full;
int buffer[buffer_size];
bool isfull = false;
bool isempty = true;

void *producer() {
   
      for(int i 0;i<5;i++){
        pthread_mutex_lock(&mutex);
        while(isfull){
            pthread_cond_wait(&full,&mutex);
            buffer[i]=1;
            i++;
            pthread_cond_signal(&empty);
        }
        pthread_mutex_unlock(&mutex);
       
      }  
      pthread_exit(NULL);
        
    
    return NULL;
}

void *consumer() {
      for(int i 0;i<5;i++){
        while(isempty){
            pthread_cond_wait(&empty,&mutex);
            buffer[i]=0;
            i--;
            pthread_cond_signal(&full);
        }
        pthread_mutex_unlock(&mutex);
       
      }  
      pthread_exit(NULL);
        
    
    return NULL;
      
}

int main() {
    pthread_t producer_thread, consumer_thread;
    pthread_mutex_init(&mutex, NULL);
     pthread_mutex_init(&full, NULL);
      pthread_mutex_init(&empty, NULL);
    srand(time(NULL));

    pthread_create(&producer_thread, NULL, producer, NULL);
    pthread_create(&consumer_thread, NULL, consumer, NULL);

    pthread_join(producer_thread, NULL);
    pthread_join(consumer_thread, NULL);

    pthread_mutex_destroy(&mutex);
     pthread_mutex_destroy(&full);
      pthread_mutex_destroy(&empty);

    return 0;
}
