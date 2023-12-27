#include<bits/stdc++.h>
using namespace std;
int main(){
int n,a[n];
cout<<"enter the size";
cin>>n;
cout<<"enter the elements";
for(int i=0;i<n;i++)
{
cin>>a[i];
}
cout<<"\nbefore sorting\n";
for(int i=0;i<n;i++)
{
cout<<a[i]<<" ";
}
cout<<"\n";
clock_t start,end;
start = clock();
for(int i=0;i<n-1;i++)
{
for(int j=i+1;j<n;j++)
{
if(a[j]<a[i])
{
int temp = a[j];
a[j]=a[i];
a[i]=temp;
}
}
}
end = clock();
cout<<"\nafter sorting\n";
for(int i=0;i<n;i++){
    cout<<a[i]<<" ";
}
double time_spent = (double)(end-start)/CLOCKS_PER_SEC;
cout<<"\ntime spent: "<<time_spent;
return 0;
}
