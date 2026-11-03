#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <cmath>
#include <map>
#include <set>

using namespace std;

int n,fixedRow,fixedCol;

bool isSafe(vector<vector<int>> &board,int row,int col){
    for(int i=0;i<n;i++){
        if(board[i][col] == 1){
            return false;
        }
    }

    for(int i=row-1,j=col-1;i>=0 && j>=0;i--,j--){
        if(board[i][j] == 1){
            return false;
        }
    }

    for(int i=row-1,j=col+1;i>=0 && j<n;i--,j++){
        if(board[i][j] == 1){
            return false;
        }
    }
    return true;
}

bool solve(int row,vector<vector<int>> &board){
    if(row == n) return true;

    if(row == fixedRow){
        return solve(row+1,board);
    }

    for(int col=0;col<n;col++){
        if(isSafe(board,row,col)){
            board[row][col] = 1;
            if(solve(row+1,board)){
                return true;
            }
            board[row][col] = 0;
        }
    }
    return false;
}

int main() {

    cout<<"Enter total no. of rows and columns: ";
    cin>>n;
    cout<<"\nEnter position of firstRow and firstCol: ";
    cin>>fixedRow>>fixedCol;

    fixedRow--;
    fixedCol--;

    if (fixedRow < 0 || fixedRow >= n || fixedCol < 0 || fixedCol >= n) {
        cout << "Invalid position";
        return 0;
    }

    vector<vector<int>> board(n,vector<int>(n,0));
    board[fixedRow][fixedCol] = 1;
    if(solve(0,board)){
        cout<<"\nSolution:\n";
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                cout<<board[i][j]<<" ";
            }
            cout<<endl;
        }
    }
    else{
        cout<<"\nNo solution exists";
    }

    return 0;
}