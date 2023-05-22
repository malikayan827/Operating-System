#include <stdio.h>
#include <pthread.h>

#define ARRAY_SIZE 20
#define NUM_THREADS 4

int arr[ARRAY_SIZE] = {5, 12, 33, 7, 19, 25, 16, 9, 10, 14, 8, 22, 31, 17, 3, 28, 11, 6, 15, 4};
int target = 14;
int found = 0;

void *search(void *thread_id)
{
    long tid = (long)thread_id;

    int start = tid * (ARRAY_SIZE / NUM_THREADS);
    int end = (tid + 1) * (ARRAY_SIZE / NUM_THREADS);

    for (int i = start; i < end; i++)
    {
        if (arr[i] == target)
        {
            found = 1;
            break;
        }
    }

    pthread_exit(NULL);
}
int main()
{
    pthread_t threads[NUM_THREADS];
    int rc;

    for (long t = 0; t < NUM_THREADS; t++)
    {
       if(found==1){
           break;}
        rc = pthread_create(&threads[t], NULL, search, (void *)t);
      pthread_join(threads[t], NULL);
    }

    

    if (found)
    {
        printf("The target number %d is found in the array.\n", target);
    }
    else
    {
        printf("The target number %d is not found in the array.\n", target);
    }

    return 0;
}