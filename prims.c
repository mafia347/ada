#include <stdio.h>
int n,c[20][20],visited[20];

void prim(){
int a,b,count=0,cost=0;
int min=999;
visited[1]=1;
while(count<n-1){
min=999;
for(int i=1;i<=n;i++)
for(int j=1;j<=n;j++)
if(visited[i] && !visited[j] && min>c[i][j]){
min=c[i][j];
a=i;
b=j;
}
printf("%d--->%d = %d\n",a,b,c[a][b]);
cost+=c[a][b];
visited[b]=1;
count++;
}
printf("Total cost of Spanning tree is %d",cost);
}

int main(){
printf("Enter number of vertices \n");
scanf("%d",&n);
printf("Enter the cost matrix \n");
printf("Enter 999 if no direct edges \n");
for(int i=1;i<=n;i++){
for(int j=1;j<=n;j++)
scanf("%d",&c[i][j]);
visited[i]=0;
}
prim();
return 0;
}
