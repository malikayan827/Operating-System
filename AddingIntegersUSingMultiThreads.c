#include <stdio.h>
#include <pthread.h>

#define ARRAY_SIZE 20
#define NUM_THREADS 4


int arr[ARRAY_SIZE] = {5, 12, 33, 7, 19, 25, 16, 9, 10, 14, 8, 22, 31, 17, 3, 28, 11, 6, 15, 4};
int target = 14;

int sum;

void *add(void *thread_id)
{
    long tid = (long)thread_id;

    int start = tid * (ARRAY_SIZE / NUM_THREADS);
    int end = (tid + 1) * (ARRAY_SIZE / NUM_THREADS);

    for (int i = start; i < end; i++)
    {
       sum+=arr[i]; 
    }

    pthread_exit(NULL);
}
int main()
{
    pthread_t threads[NUM_THREADS];
    int rc;

    for (long t = 0; t < NUM_THREADS; t++)
    {
       
        rc = pthread_create(&threads[t], NULL, add, (void *)t);
      pthread_join(threads[t], NULL);
    }

        printf("The sum is %d ", sum);
    

    return 0;
}