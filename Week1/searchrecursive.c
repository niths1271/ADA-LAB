#include<stdio.h>
int linearsearch(int arr[],int i, int n, int key)
{
    if(i>=n){
      return -1;
    }
      if(arr[i]==key){
          return i;
      }     
          return linearsearch(arr,i+1,n,key);    
  }

int binarysearch(int arr[],int l,int h,int key)
{
    if(h>=l){
   int mid=l+(h-1)/2;
   if(arr[mid]==key){
       return mid;
   }
    if(key>arr[mid]){
         return binarysearch(arr,mid+1,h,key);
   }
   return(arr,l,mid-1,key);
}
return -1;
}

int main()
{
    int arr[100];
    int n,key;
    int result, ch; 
    printf("1:linear search\n2:binary search\n");
    scanf("%d",&ch);
    switch(ch){
    case 1 :
     printf("ENTER THE NUMBER OF ELEMENTS IN THE ARRAY\n");
    scanf("%d",&n);
    printf("ENTER THE ELEMENTS OF THE ARRAY\n");
    for(int i=0;i<n;i++){
        scanf("%d",&arr[i]);
    }
    printf("ENTER THE ELEMENT TO BE SEARCHED\n");
    scanf("%d",&key);
     result = linearsearch(arr,0,n,key);
        (result == -1) ? printf("Element is not present in array") : printf("Element is present at index %d",result);
        break;
    case 2 : 
    printf("ENTER THE NUMBER OF ELEMENTS IN THE ARRAY\n");
    scanf("%d",&n);
    printf("ENTER THE ELEMENTS OF THE ARRAY IN SORTED ORDER\n");
    for(int i=0;i<n;i++){
        scanf("%d",&arr[i]);
    }
    printf("ENTER THE ELEMENT TO BE SEARCHED\n");
    scanf("%d",&key);
    result = binarysearch(arr,0,n-1,key);
        (result == -1) ? printf("Element is not present in array") : printf("Element is present at index %d",result);
    }
    return 0;
}