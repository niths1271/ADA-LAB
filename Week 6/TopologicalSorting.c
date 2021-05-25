#include<stdio.h>
int k;
void depthfirstsearch(int v,int n,int adj[][20],int visited[],int exp[]){
 int i;
 visited[v]=1;
 for(i=1;i<=n;i++){
       if(adj[v][i]==1 && !visited[i]){
           depthfirstsearch(i,n,adj,visited,exp);
       }
 }
exp[k++]=v;
}

void main(){
    int i,j,n,m;
    int u,v;
    int adj[20][20];
    int vis[20];
    int exp[20];
    printf("ENTER THE NUMBER OF VERTICES IN YOUR GRAPH\n");
    scanf("%d",&n);
    for(i=1;i<=n;i++){
        for(j=1;j<=n;j++){
            adj[i][j]=0;
        }
    }
    printf("Enter the number of edges\n");
    scanf("%d",&m);
    for(i=1;i<=m;i++)
{
printf("enter an edge\n");
scanf("%d %d",&u,&v);
adj[u][v]=1;
}
    for(i=1;i<=n;i++){
        vis[i]=0;
    }
    for(i=1;i<=n;i++){
  if(vis[i]==0){
        depthfirstsearch(i,n,adj,vis,exp);
    }
    }
    printf("Topological Order: ");
for(i=n-1;i>=0;i--)
printf("%d\t",exp[i]);
}

