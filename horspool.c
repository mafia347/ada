#include <string.h>
#include <stdio.h>
int table[1000];

void shift(char p[]){
int len=strlen(p);
for(int i=0;i<1000;i++)
table[i]=len;
for(int j=0;j<=len-2;j++)
table[p[j]]=len-1-j;
}

int horspool(char p[], char t[]){
shift(p);
int m=strlen(p);
int n=strlen(t);
int i=m-1;
while(i<n){
int k=0;
while(k<m && (p[m-1-k]==t[i-k]))
k++;
if(k==m)
return i-m+1;
else
i=i+table[t[i]];
}
return -1;
}

int main(){
char str[100],ptn[20];
printf("Enter the text \n");
gets(str);
printf("Enter the pattern to be found \n");
gets(ptn);
int res=horspool(ptn,str);
if(res==-1)
printf("\nPattern not found\n");
else
printf("Pattern found at %d index \n",res);
return 0;
}
