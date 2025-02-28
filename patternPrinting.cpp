#include<bits/stdc++.h>
using namespace std;

void sprialT(vector<vector<int>> &grid, int n){
    int m = grid.size();
    // int m = grid[0].size();
    int top = 0;
    int left = 0;
    int right = m - 1;
    int bottom = m- 1;

    while(left <= right || top <= bottom){

        //top traversal
        for(int i=left;i<=right;i++){
            grid[top][i] = n;
        }
        top++;

        //right traversal
        for(int i=top;i<=bottom;i++){
            grid[i][right] = n;
        }
        right--;

        // bottom traversal
        if(left <= right){
            for(int i=right;i>=left;i--){
                grid[bottom][i] = n;
            }
            bottom--;
        }

        if(top <= bottom){
            for(int i=bottom;i>=top;i--){
                grid[i][left] = n;
            }
            left++;
        }
        n--;

    }
}
int main(){
    int n;
    cin>>n;

    int size = 2*n;
    vector<vector<int>> grid(size-1, vector<int> (size-1, 0));
    sprialT(grid, n);

    for(int i=0;i<grid.size();i++){
        for(int j=0;j<grid[0].size();j++){
            cout<<grid[i][j]<<" ";
        }

        cout<<endl;
    }

    return 0;
    
}