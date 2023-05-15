#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

#define array 10

int arr[array];

void *generate_array(void *arg)
{
    int i;
    printf("Generating array:\n");
    for (i = 0; i < array; i++) {
        arr[i] = rand() % 100;
        printf("%d ", arr[i]);
    }
    printf("\n");
    pthread_exit(NULL);
}

void *sort_array(void *arg)
{
    int i, j, temp;
    printf("Sorting array:\n");
    for (i = 0; i < array - 1; i++) {
        for (j = i + 1; j < array; j++) {
            if (arr[i] > arr[j]) {
                temp = arr[i];
                arr[i] = arr[j];
                arr[j] = temp;
            }
        }
    }
    for (i = 0; i < array; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
    pthread_exit(NULL);
}

int main()
{
    pthread_t thread1, thread2;
    srand(time(NULL));
    pthread_create(&thread1, NULL, generate_array, NULL);
    pthread_join(thread1, NULL);
    pthread_create(&thread2, NULL, sort_array, NULL);
    pthread_join(thread2, NULL);
    return 0;
}
