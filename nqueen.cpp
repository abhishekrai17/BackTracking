#include<iostream>
using namespace std;
bool issafe(int** arr,int x,int y,int n){
    for(int row=0;row<x;row++){
        if(arr[row][y]==1){
            return false;
        }
    }

    int row =x;
    int col=y;
    while(row>=0 && col>=0){
        if(arr[row][col]==1){
            return false;
        }
        row--;
        col--;
    }

    row =x;
    col=y;
    while(row>=0 && col<n){
        if(arr[row][col]==1){
            return false;
        }
        row--;
        col++;
    }

    return true;
}

bool nqueen(int** arr,int x,int n){
    if(x>=n){
        return true;
    }


    for(int col=0;col<n;col++){
        if(issafe(arr,x,col,n)){
            arr[x][col]=1;

            if(nqueen(arr,x+1,n)){
                return true;
            }
            arr[x][col]=0;
        }
    }
    return false;
}
int main(){
    int** arr = new int* [5];
    for(int i=0;i<5;i++){
        arr[i]= new int[5];
    }
    for(int i=0;i<5;i++){
        for(int j=0;j<5;j++){
            arr[i][j]=0;
        }
    }
   
   
   if(nqueen(arr,0,5))
   {
    for(int i=0;i<5;i++){
        for(int j=0;j<5;j++){
            cout<<arr[i][j];
            cout<<" ";
        }
        cout<<endl;
    }
   }
}