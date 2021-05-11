#include<stdio.h>
#include<stdlib.h>
#include<time.h>
clock_t start1, start2, end1, end2;
double cpu_time_used1, cpu_time_used2;

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

int linearSearch(int arr[], int l, int r, int x)
{
     if (r < l)
        return -1;
     if (arr[l] == x)
        return l;
     if (arr[r] == x)
        return r;
     return linearSearch(arr, l+1, r-1, x);
}

int recBinarySearch(int arr[], int l, int r, int x)
{
    if (r >= l)
    {
        int mid = l + (r - l) / 2;
        if (arr[mid] == x)
            return mid;
        if (arr[mid] > x)
            return recBinarySearch(arr, l, mid - 1, x);
        return recBinarySearch(arr, mid + 1, r, x);
    }
    return -1;
}

int main()
{
    int key;
    int result,ch; 
    printf("1:linear search\n2:binary search\n");
    scanf("%d",&ch);
    switch(ch){
    case 1 : 
    ch=ch;
     int n;
     n=5000;
    while(n<=70000){
    int arr[n];
    srand(time(0));
    for(int i=0;i<n;i++){
        arr[i]=random(1,70000);
    }
    printf("ENTER THE ELEMENT TO BE SEARCHED\n");
    scanf("%d",&key);
       start1=clock();
     result = linearSearch(arr,0,n-1,key);
     int c,d;
     for (c = 1; c <= 20000; c++)
                    for (d = 1; d <= 20000; d++){}
     end1=clock();
     cpu_time_used1=(double)(end1-start1) / CLOCKS_PER_SEC;
        (result == -1) ? printf("Element is not present in array of %d numbers and the cpu time used is %f\n",n,cpu_time_used1):
          printf("Element is present at index %d in array of %d numbers and cpu time used is %f\n",result,n,cpu_time_used1);
         n=n+5000;
    }
        break;
    case 2 : 
      ch=ch;
     int j;
     j=5000;
    while(j<=70000){
    int arr[j];
    srand(time(0));
    for(int i=0;i<j;i++){
        arr[i]=random(1,70000);
    }
    selectionsort(j,arr);
    printf("ENTER THE ELEMENT TO BE SEARCHED\n");
    scanf("%d",&key);
       start2=clock();
     result = recBinarySearch(arr,0,j-1,key);
     int c,d;
     for (c = 1; c <= 20000; c++)
                    for (d = 1; d <= 20000; d++){}    
     end2=clock();
     cpu_time_used2=(double)(end2-start2) / CLOCKS_PER_SEC;
        (result == -1) ? printf("Element is not present in array of %d numbers and the cpu time used is %f\n",j,cpu_time_used2):
          printf("Element is present at index %d in array of %d numbers and cpu time used is %f\n",result,j,cpu_time_used2);
         j=j+5000;      
}
        break;
 return 0;
    }
    }












