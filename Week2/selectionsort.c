#include<stdio.h>
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
    int arr[100];
    int n;
    printf("Enter the number of elements in the array\n");
    scanf("%d",&n);
     printf("Enter the of elements in the array\n");
     int i;
    for(i=0;i<n;i++){
         scanf("%d",&arr[i]);
    }
    selectionsort(n,arr);
    printf("Sorted Array: \n");
    for(int i=0;i<n;i++){
         printf("%d\n",arr[i]);
    }
}