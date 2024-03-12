#include<stdio.h>
int n;
int a[50];

void mergesort(int low, int mid, int high){
int h, i, j, k, b[50];
i=h=low;
j=mid+1;
while(h<=mid && j<=high){
if(a[h] <= a[j]){
b[i] = a[h];
h++;
}
else{
b[i] = a[j];
j++;
}
i++;
}
if(h>mid)
for(k=j; k<=high; k++){
b[i] = a[k];
i++;
}
else
for(k=h; k<=mid; k++){
b[i] = a[k];
i++;
}
for(k=low; k<=high; k++){
a[k] = b[k];
}
}

void divide(int low, int high){
if(low < high){
int mid = (low + high)/2;
divide(low, mid);
divide(mid+1, high);
mergesort(low,mid,high);
}
}

int main(){
printf("\nMERGE SORT\n");
printf("Enter the no of elements: ");
scanf("%d",&n);
printf("\nEnter the elements: ");
for(int i=1; i<=n; i++){
scanf("%d",&a[i]);
}
divide(1,n);
printf("\nSorted elements are: ");
for(int i=1; i<=n; i++){
printf("%d  ",a[i]);
}
return 0;
}
