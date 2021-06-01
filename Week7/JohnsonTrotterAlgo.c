// CPP program to print all permutations using
// Johnson and Trotter algorithm.
#include <stdio.h>
#include <stdlib.h>
#include<stdbool.h>

bool LEFT_TO_RIGHT = 1;
bool RIGHT_TO_LEFT = 0;


// Utility functions for finding the
// position of largest mobile integer in a[].
int searchArr(int a[], int n, int mobile)
{
    for (int i = 0; i < n; i++)
        if (a[i] == mobile)
           return i + 1;
}
  
// To carry out step 1 of the algorithm i.e.
// to find the largest mobile integer.
int getMobile(int a[], bool dir[], int n)
{
    int mobile_prev = 0, mobile = 0;
    for (int i = 0; i < n; i++)
    {
        // direction 0 represents RIGHT TO LEFT.
        if (dir[a[i]-1] == RIGHT_TO_LEFT && i!=0)
        {
            if (a[i] > a[i-1] && a[i] > mobile_prev)
            {
                mobile = a[i];
                mobile_prev = mobile;
            }
        }
  
        // direction 1 represents LEFT TO RIGHT.
        if (dir[a[i]-1] == LEFT_TO_RIGHT && i!=n-1)
        {
            if (a[i] > a[i+1] && a[i] > mobile_prev)
            {
                mobile = a[i];
                mobile_prev = mobile;
            }
        }
    }
  
    if (mobile == 0 && mobile_prev == 0)
        return 0;
    else
        return mobile;
}
  
// Prints a single permutation
int printOnePerm(int a[], bool dir[], int n)
{
    int mobile = getMobile(a, dir, n);
    int pos = searchArr(a, n, mobile);
  
    // swapping the elements according to the
    // direction i.e. dir[].
        int t;
    if (dir[a[pos - 1] - 1] ==  RIGHT_TO_LEFT){
         t=a[pos-1];
         a[pos-1]=a[pos-2];
         a[pos-2]=t;
    }
  
    else if (dir[a[pos - 1] - 1] == LEFT_TO_RIGHT){
         t=a[pos];
         a[pos]=a[pos-1];
         a[pos-1]=t;
    }
  
    // changing the directions for elements
    // greater than largest mobile integer.
    for (int i = 0; i < n; i++)
    {
        if (a[i] > mobile)
        {
            if (dir[a[i] - 1] == LEFT_TO_RIGHT)
                dir[a[i] - 1] = RIGHT_TO_LEFT;
            else if (dir[a[i] - 1] == RIGHT_TO_LEFT)
                dir[a[i] - 1] = LEFT_TO_RIGHT;
        }
    }
    for (int i = 0; i < n; i++)
        printf("%d",a[i]);
    printf(" ");
}
  
// To end the algorithm for efficiency it ends
// at the factorial of n because number of
// permutations possible is just n!.
int fact(int n)
{
    int res = 1;
    for (int i = 1; i <= n; i++)
        res = res * i;
    return res;
}
  
// This function mainly calls printOnePerm()
// one by one to print all permutations.
void printPermutation(int n)
{
    // To store current permutation
    int a[n];
  
    // To store current directions
    bool dir[n];
  
    // storing the elements from 1 to n and
    // printing first permutation.
    printf("The permutations are: ");
    for (int i = 0; i < n; i++)
    {
        a[i] = i + 1;
        printf("%d",a[i]);
    }
  printf(" ");
    // initially all directions are set
    // to RIGHT TO LEFT i.e. 0.
    for (int i = 0; i < n; i++)
        dir[i] =  RIGHT_TO_LEFT;
  
    // for generating permutations in the order.
    for (int i = 1; i < fact(n); i++)
        printOnePerm(a, dir, n);
}
  
// Driver code
int main()
{
     int n;
     printf("Enter the value of n\n");
     scanf("%d",&n);
    printPermutation(n);
    return 0;
}

