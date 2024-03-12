#define n 4
#include <stdio.h>
#include <stdbool.h>

void printsol(int board[n][n]){
for(int i=0;i<n;i++){
for(int j=0;j<n;j++){
if(board[i][j])
printf("Q");
else
printf(". ");
}
printf("\n");
}
}

bool isSafe(int board[n][n],int row,int col){
int i,j;

for(i=0;i<col;i++)
if(board[row][i])
return false;

for(i=row,j=col;i>=0&&j>=0;i--,j--)
if(board[i][j])
return false;

for(i=row,j=col;j>=0&&i<n;i++,j--)
if(board[i][j])
return false;

return true;

}
bool nqueen(int board[n][n],int col){
if(col>=n)
return true;
for(int i=0;i<n;i++){
if(isSafe(board,i,col)){
board[i][col]=1;
if(nqueen(board,col+1))
return true;

board[i][col]=0;
}
}
return false;
}
bool solveNQ(){
int board[n][n]={ { 0, 0, 0, 0 },
{ 0, 0, 0, 0 },
{ 0, 0, 0, 0 },
{ 0, 0, 0, 0 } };
if(!nqueen(board,0)){
printf("sol not exists");
return false;
}
printsol(board);
return true;
}
int main(){
solveNQ();
return 0;
}
