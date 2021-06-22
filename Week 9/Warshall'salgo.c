#include<stdio.h>
int adj[20][20];
int path[20][20];
int n;
void warshall()
{
     int i,j,k;
for(i=1;i<=n;i++)
{
for(j=1;j<=n;j++)
{
path[i][j]=adj[i][j];
}
}
for(k=1;k<=n;k++)
{
for(i=1;i<=n;i++)
{
for(j=1;j<=n;j++)
{
if((path[i][j]!=1) && (path[i][k]==1 && path[k][j]==1))
path[i][j]=1;
}
}
}
}
void main(){
    int i,j;
    printf("ENTER THE NUMBER OF VERTICES IN YOUR GRAPH\n");
    scanf("%d",&n);
    printf("ENTER THE VALUES FOR THE ADJACENCY MATRIX OF THE GRAPH\n");
    for(i=1;i<=n;i++){
        for(j=1;j<=n;j++){
            scanf("%d",&adj[i][j]);
        }
    }
    warshall();
    printf("The path matrix is:\n");
      for(i=1;i<=n;i++){
        for(j=1;j<=n;j++){
            printf("%d\t",path[i][j]);
        }
        printf("\n");
    }
}
    