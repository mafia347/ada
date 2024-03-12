#include<stdio.h>
int partition(int arr[], int s, int e){
int pivot = arr[s];
int pivotindex;
int x=0;
for(int i=s+1; i<=e; i++){
if(arr[i] <= pivot)
x++;
}
pivotindex = s + x;
int temp = arr[pivotindex];
arr[pivotindex] = arr[s];
arr[s] = temp;
int y = s;
int j = e;
while(y<pivotindex && j>pivotindex){
while(arr[y] <= pivot)
y++;
while(arr[j] > pivot)
j--;
if(y<pivotindex && j>pivotindex){
int temp = arr[y];
arr[y] = arr[j];
arr[j] = temp;
y++;
j--;
}
}
return pivotindex;
}
void quicksort(int arr[], int s, int e){
if(s>=e){
return ;
}
int p = partition(arr, s, e);
quicksort(arr,s,p);
quicksort(arr,p+1,e);
}
int main(){
printf("Enter the no of elements : ");
int n;
scanf("%d",&n);
printf("Enter the elements : ");
int arr[n];
for(int i=0; i<n; i++){
scanf("%d",&arr[i]);
}
quicksort(arr,0,n-1);
printf("Output : ");
for(int i=0; i<n; i++){
printf("%d  ",arr[i]);
}
return 0;
}
