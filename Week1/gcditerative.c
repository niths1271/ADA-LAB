#include<stdio.h>
int min(int a,int b){
    if(a<=b)
        return a;
    else 
        return b;
}

int gcd(int a,int b){
    int i=0;
    int m=min(a,b);
    for(i=m;i>=1;i--){
        if(a%m==0 && b%m==0){
        return m;
        }
    }
}

int main(){
    int a,b;
    printf("Enter the two numbers\n");
    scanf("%d %d",&a,&b);
    printf("Gcd of two numbers is:%d",gcd(a,b));
}