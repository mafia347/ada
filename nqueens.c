#include <stdio.h>
#include <math.h>
int count=0,x[100];

int place(int k,int i){
for(int j=1;j<k;j++)
if((x[j]==i) || (abs(x[j]-i)==abs(j-k)))
return(0);
return(1);
}

void nqueen(int k,int n){
for(int i=1;i<=n;i++)
if(place(k,i)){
x[k]=i;
if(k==n){
count++;
for(int j=1;j<=n;j++){
for(int p=1;p<=n;p++)
if(x[j]==p)
printf(" q ");
else
printf(" 0 ");
printf("\n");
}
}
else
nqueen(k+1,n);
}
printf("\n");
}

int main(){
int n;
printf("Enter the number of queens: ");
scanf("%d",&n);
nqueen(1,n);
if(count==0)
printf("There is no solution for '%d - Queens' problem",n);
else
printf("Total number of solutions :%d",count);
return 0;
}
