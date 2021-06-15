#include <stdio.h>
#include<stdlib.h>
#include <time.h>
clock_t start, end;
double cpu_time_used;

int random(int lower, int upper)
{
    int i;
        int num = (rand() %
           (upper - lower + 1)) + lower;
       return num;
}

void merge(int a[], int low, int mid, int high)
{
    int i, j, k, c[high];
    i = low;
    k = low;
    j = mid + 1;
    while (i <= mid && j <= high)
    {
        if (a[i] < a[j])
            c[k++] = a[i++];
        else
            c[k++] = a[j++];
    }
    while (i <= mid)
            c[k++] = a[i++];
        while(j<=high)
            c[k++]=a[j++];
        for(i=low;i<=high;i++){
            // for (m = 0; m < 10000; m++)
            // {
            // }
            a[i] = c[i];
        }          
}

void mergesort(int a[], int low, int high)
{
    int mid;
    if (low < high)
    {
        mid = (low + high) / 2;
        mergesort(a, low, mid);
        mergesort(a, mid + 1, high); 
        merge(a, low, mid, high);
    }
}

void main()
{
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
        a[i]=random(1,100000);
    }
     start=clock();
     mergesort(a,0,n-1);
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