#include<bits/stdc++.h>
using namespace std;
int main()
{
int n;
cout<<"enter the size";
cin>>n;
int a[n];
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
for(int i=1;i<n;i++)
{
int cur=a[i];
int j=i-1;
while(a[j]>cur && j>=0)
{
a[j+1]=a[j];
j--;
}
a[j+1]=cur;
}
end = clock();
cout<<"\nafter sorting\n";
for(int i=0;i<n;i++)
{
cout<<a[i]<<" ";
}
double time_spent = (double)(end-start)/CLOCKS_PER_SEC;
cout<<"\ntime spent: "<<time_spent;
return 0;
}
