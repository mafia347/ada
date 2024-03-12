#include<stdio.h>

int main(){
int n;
printf("Enter the no of elements: ");
scanf("%d", &n);
int arr[n];
printf("Enter the elements: ");
for(int i=0; i<n; i++){
scanf("%d", &arr[i]);
}

for(int i=0; i<n-1; i++){
for(int j=i+1; j<n; j++){
if(arr[j]<arr[i]){
int temp = arr[i];
arr[i] = arr[j];
arr[j] = temp;
}
}
}

printf("Sorted list: ");
for(int i=0; i<n; i++){
printf("%d ", arr[i]);
}
return 0;
}
