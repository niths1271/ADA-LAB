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
void insertionSort(int arr[], int n)
{
    int i, key, j;
    for (i = 1; i < n; i++) {
        key = arr[i];
        j = i - 1;
        while (j >= 0 && arr[j] > key) {
            arr[j + 1] = arr[j];
            j = j - 1;
        }
        arr[j + 1] = key;
    }
}
int main(){
     int n=1000;
    while(n<20000){
    int arr[n];
    srand(time(0));
    for(int i=0;i<n;i++){
        arr[i]=random(1,20000);
    }
     start=clock();
    insertionSort(arr,n);
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