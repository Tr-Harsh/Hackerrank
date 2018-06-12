#include<iostream>
#include<vector>
using namespace std;
int maxsize=6;
int offset=2;
int maxhourglass=-1000;
void hourglass(int i,int j,vector< vector<int> >mat){
    int sum=0;
    for(int k=j;k<=j+offset;k++){
        sum+=mat[i][k];
        sum+=mat[i+offset][k];
    }
    sum+=mat[i+1][j+1];
    if(maxhourglass<sum)
        maxhourglass=sum;
}

int main(){
    vector< vector<int> > arr(6,vector<int>(6));
    for(int arr_i = 0;arr_i < 6;arr_i++){
       for(int arr_j = 0;arr_j < 6;arr_j++){
          cin >> arr[arr_i][arr_j];
       }
    }
    for(int i=0;i<maxsize-offset;i++)
        for(int j=0;j<maxsize-offset;j++)
            hourglass(i,j,arr);
    cout<<maxhourglass;
    return 0;
}
