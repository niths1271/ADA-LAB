#include<stdio.h>
void depthfirstsearch(int i,int n,int adj[][20],int visited[]){
 int j;
 visited[i]=1;
 printf("%d\t",i);
 for(j=0;j<n;j++){
       if(adj[i][j]==1 && !visited[j]){
           depthfirstsearch(j,n,adj,visited);
       }
 }
}

void main(){
    int i,j,n;
    int count;
    int starting;
    int adj[20][20];
    int visited[20];
    printf("ENTER THE NUMBER OF VERTICES IN YOUR GRAPH\n");
    scanf("%d",&n);
    printf("ENTER THE VALUES FOR THE ADJACENCY MATRIX OF THE GRAPH\n");
    for(i=0;i<n;i++){
        for(j=0;j<n;j++){
            scanf("%d",&adj[i][j]);
        }
    }
    for(i=0;i<n;i++){
        visited[i]=0;
    }
    printf("ENTER THE STARTING NODE FOR THE GRAPH\n");
    scanf("%d",&starting);
    printf("THE NODES REACHABLE FROM GIVEN NODE ARE:  ");
    depthfirstsearch(starting,n,adj,visited);
    printf("\n");
    for(i=0;i<n;i++){
  if(visited[i]==1){
        count++;
    }
}
if(count==n){
    printf("Graph is Connected");
}
else{
    printf("Graph is not Connected");
}
}