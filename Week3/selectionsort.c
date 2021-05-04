#include<stdio.h>
#include<stdlib.h>
#include<time.h>
    clock_t start,end;
double cpu_time_used;

int random(int lower, int upper)
{
    int i;
        int num = (rand() %
           (upper - lower + 1)) + lower;
       return num;
}

void selectionsort(int n,int arr[]){
    int small;
    int pos;
    int temp;
    int i;
    for( i=0;i<=n-2;i++){
           small=arr[i];
           pos=i;
           for(int j=i+1;j<n;j++){
               if(arr[j]<small){
                   small=arr[j];
                   pos=j;
               }
           }
           temp=arr[i];
           arr[i]=arr[pos];
           arr[pos]=temp;
    }
    return;
}
int main(){
     int n=5000;
    while(n<20000){
    int arr[n];
    srand(time(0));
    for(int i=0;i<n;i++){
        arr[i]=random(1,30000);
    }
     start=clock();
    selectionsort(n,arr);
    //  for(int d=0;d<=8000;d++){
    //       for(int c=0;c<=8000;c++){}
    //  }
    end=clock();
     cpu_time_used=(double)(end-start) / CLOCKS_PER_SEC;

    // printf("Sorted Array: \n");
    // for(int i=0;i<n;i++){
    //      printf("%d\n",arr[i]);
    // }
printf("CPU TIME USED FOR %d NUMBERS IS:%f\n",n,cpu_time_used);
 n=n+2000;
}
}