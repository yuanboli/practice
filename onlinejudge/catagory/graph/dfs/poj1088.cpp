#include <iostream>
#include <cstring>
#include <algorithm>
using namespace std;

dfs(int** height, int row_num, int col_num, int i, int j){
    int left, right, up, bottom;
    left = right = up = bottom = 1;
    if(j != 0 && height[i][j-1] < height[i][j]){
        left += dfs(height, row_num, col_num, i, j-1);
    }
    if(j != col_num - 1 && height[i][j+1] < height[i][j]){
        right += dfs(height, row_num, col_num, i, j+1);
    }
    if(i != 0 && height[i-1][j] < height[i][j]){
        up += dfs(height, row_num, col_num, i-1, j);
    }
    if(i != row_num-1 && height[i+1][j] < height[i][j]){
        bottom += dfs(height, row_num, col_num, i+1, j);
    }
    return max(left, max(right, max(up, bottom)));
}

int main(){
    //init
    int row_num, col_num;
    std::cin >> row_num >> col_num;
    int height[row_num][col_num];
    memset(height, 0, row_num*col_num*sizeof(int));

    //find max
    int cur_max = 0;
    int fir = 0, sec = 0;
    for(int i = 0; i < row_num; i++){
        for(int j = 0; j < col_num; j++){
            cin >> height[i][j];
            if(height[i][j] > cur_max){
                cur_max = height[i][j];
                fir = i;
                sec = j;
            }
        }
    }

    return dfs((int**)height, row_num, col_num, fir, sec);
}