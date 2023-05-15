#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <sched.h>



void *Even(void *thread_id) {
    int *val=(int *)thread_id;
    int n = *val;
    for(int i=0;i<n;i++){
        if(i%2==0){
            printf("%d  \n",i);
            sched_yield();
        }
         

    }
}

void *Odd(void *thread_id) {
     int *val=(int *)thread_id;
    int n = *val;
    for(int i=0;i<n;i++){
        if(i%2!=0){
            printf("%d  \n",i);
            
        }
        

    }
}

int main() {
    
    pthread_t threadid;
    pthread_t threadid1;
    int a;
    printf("Enter the number: ");
    scanf("%d",&a);

    pthread_create(&threadid, NULL, Odd, (void *)&a);
   

    //printf("Even\n");
    pthread_create(&threadid1, NULL, Even, (void *)&a);
     pthread_join(threadid, NULL);
    pthread_join(threadid1, NULL);

    return 0;
/*#include <stdio.h>
#include <pthread.h>
#include <stdlib.h>

#include <sched.h>


void * Thread1(void * arg){
  int * val = (int *)arg;
  int n = *val;
  for(int i=0; i<n; i++){
    if(i%2 == 0){
      printf("%d  ", i);  
    }
    sched_yield();
  }
          printf("\n");
  return NULL;
}

void * Thread2(void * arg){
  int * val = (int *)arg;
  int n = *val;
  for(int i=0; i<n; i++){
    if(i%2 != 0){
      printf("%d  ", i);  
    }
    sched_yield();
  }

  return NULL;

}


int main (){
  pthread_t ID1;
  pthread_t ID2;
  int a;
  printf("Enter first no= ");
  scanf("%d", &a);
  pthread_create(&ID1, NULL, Thread1, (void *)&a);

  pthread_create(&ID2, NULL, Thread2, (void *)&a);
    pthread_join(ID1, NULL);
  pthread_join(ID2, NULL);
 
  return 0;
}*/
