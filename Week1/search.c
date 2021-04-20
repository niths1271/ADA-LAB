#include<stdio.h>
#include<time.h>
/*clock_t start,end;
double cpu_time_used;
 start=clock();*/
int binarysearch(int arr[],int n,int key)
{
    int low,high,mid;
    low = 0;
high = n - 1;
mid = (low+high)/2;
while (low <= high) {
if(arr[mid] < key)
low = mid + 1;
else if (arr[mid] == key) {
return mid+1;
break;
}
else
high = mid - 1;
mid = (low + high)/2;
}
if(low > high)
return -1;
}

int linearsearch(int arr[], int n, int key)
{
    int i;
    for (i = 0; i < n; i++)
        if (arr[i] == key)
            return i+1;
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
     result = linearsearch(arr,n,key);
        (result == -1) ? printf("Element is not present in array") : printf("Element is present at position %d",result);
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
    result = binarysearch(arr,n,key);
        (result == -1) ? printf("Element is not present in array") : printf("Element is present at position %d",result);
    }
    return 0;
}

/*end=clock();
cpu_time_used=(double)(end-start) / CLOCKS_PER_SEC;

printf("CPU TIME USED IS:%f",cpu_time_used);*/