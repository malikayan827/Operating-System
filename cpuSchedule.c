#include <stdio.h>
#include <stdlib.h>

int main(){
 int bust[4]={2,3,6,1};
 int waiting[4];
 int throughput[4];
 waiting[0]=0;
 int wait_avg=0;
  int throughput_avg=0;

 for(int i = 1;i < 4;i++){
    waiting[i]=bust[i-1]+waiting[i-1];

 }
 for(int i = 0;i < 4;i++){
    throughput[i]=bust[i]+waiting[i];

 }
 for(int i=0;i<4;i++){
    wait_avg+=waiting[i];
    throughput_avg+=throughput[i];
 }
 printf("Waiting Throughput \n");
 for(int i=0;i<4;i++){
     printf("%d\t",waiting[i]);
    printf("%d\n",throughput[i]);
 }
 printf("Average waiting: %d \t Average throughput: %d",wait_avg/4,throughput_avg/4);
}