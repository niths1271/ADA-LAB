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

int partition(int a[],int low,int high){
     int i,j,temp,pivot;
     pivot=a[low];
     i=low+1;
     j=high;
     while(i<=j){
          while(a[i]<=pivot)
          i++;
          while(a[j]>pivot)
          j--;
          if(i<j){
               temp=a[i];
               a[i]=a[j];
               a[j]=temp;
          }
     }
     temp=a[low];
     a[low]=a[j];
     a[j]=temp;
     return j;
}

void quicksort(int a[],int low,int high){
       int mid;
       if(low<high){
            mid=partition(a,low,high);
            quicksort(a,low,mid-1);
            quicksort(a,mid+1,high);
       }
}

void main(){
     int i,j;
     int n=5000;
     // printf("Enter the number of elements\n");
     // scanf("%d",&n);
     // printf("Enter the elements of the array\n");
     // for(int i=0;i<n;i++){
     //      scanf("%d",&a[i]);
     // }
    while(n<70000){
    int a[n];
    srand(time(0));
    for(i=0;i<n;i++){
        a[i]=random(1,70000);
    }
     start=clock();
     quicksort(a,0,n-1);
      end=clock();
     cpu_time_used=(double)(end-start) / CLOCKS_PER_SEC;
//       printf("Sorted Array\n");
//      for(i=0;i<n;i++){
//           printf("%d\t",a[i]);
//     }
printf("CPU TIME USED FOR %d NUMBERS IS:%f\n",n,cpu_time_used);
 n=n+5000;
}
}
