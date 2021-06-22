#include<stdio.h>
int cadj[20][20];
int d[20][20];
int n;
int min(int a,int b){
     if(a>b)
     return b;
     else if(b>a)
     return a;
}
void floyd()
{
     int i,j,k;
for(i=1;i<=n;i++)
{
for(j=1;j<=n;j++)
{
d[i][j]=cadj[i][j];
}
}
for(k=1;k<=n;k++)
{
for(i=1;i<=n;i++)
{
for(j=1;j<=n;j++)
{
d[i][j]=min(d[i][j],d[i][k]+d[k][j]);
}
}
}
}
void main(){
    int i,j;
    printf("ENTER THE NUMBER OF VERTICES IN YOUR GRAPH\n");
    scanf("%d",&n);
    printf("ENTER THE VALUES FOR THE COST ADJACENCY MATRIX OF THE GRAPH\n");
    for(i=1;i<=n;i++){
        for(j=1;j<=n;j++){
            scanf("%d",&cadj[i][j]);
        }
    }
   floyd();
    printf("The distance matrix is:\n");
      for(i=1;i<=n;i++){
        for(j=1;j<=n;j++){
            printf("%d\t",d[i][j]);
        }
        printf("\n");
    }
}
    