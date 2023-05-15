#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

int a,b;

void *add(void *thread_id) {
    int c=a+b;
    printf("result = %d",c);
    
}
void *mul(void *thread_id) {
    int c=a*b;
    printf("result = %d",c);
    
}
void *divi(void *thread_id) {
    int c=a/b;
    printf("result = %d",c);
    
}
void *sub(void *thread_id) {
    int c=a-b;
    printf("result = %d",c);
    
}

int main() {
    printf("Enter two numbers: ");
    scanf("%d %d",&a,&b);
    printf("Enter 1 for addition, 2 for subtraction, 3 for multiplication, 4 for division: ");
    int choice;
    scanf("%d",&choice);
    pthread_t threadid;
    if(choice==1)
    pthread_create(&threadid, NULL, add, NULL);
    else if(choice==2)
    pthread_create(&threadid, NULL, sub, NULL);
    else if(choice==3)
    pthread_create(&threadid, NULL, mul, NULL);
    else if(choice==4)
    pthread_create(&threadid, NULL, divi, NULL);
    else
    printf("Invalid choice");
   
   pthread_join(threadid, NULL);

    return 0;
}
