#include<stdio.h>
void bfs(int v,int n,int adj[][20],int visited[]){
 int i,u;
 int f=0,r=0;
 int q[10];
 visited[v]=1;
 q[r]=v;
while(f<=r){
u=q[f];
printf("%d\t",u);
for(i=1;i<=n;i++){
     if(adj[v][i]==1 && visited[i]==0){
          q[++r]=i;
          visited[i]=1;
     }
}
f++;
}
}

void main(){
    int i,j,n;
    int starting;
    int adj[20][20];
    int visited[20];
    printf("ENTER THE NUMBER OF VERTICES IN YOUR GRAPH\n");
    scanf("%d",&n);
    printf("ENTER THE VALUES FOR THE ADJACENCY MATRIX OF THE GRAPH\n");
    for(i=1;i<=n;i++){
        for(j=1;j<=n;j++){
            scanf("%d",&adj[i][j]);
        }
    }
    for(i=1;i<=n;i++){
        visited[i]=0;
    }
//     printf("ENTER THE STARTING NODE FOR THE GRAPH\n");
//     scanf("%d",&starting);
    printf("BFS TRAVERSAL:  ");
    for(i=1;i<=n;i++){
  if(visited[i]==0){
        bfs(i,n,adj,visited);
    }
}
}