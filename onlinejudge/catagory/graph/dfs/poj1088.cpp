#include <iostream>
#include <cstring>
#include <algorithm>
using namespace std;
int dp[102][102];

int dfs(int** height, int row_num, int col_num, int i, int j){
    if(dp[i][j] != 0){
			return dp[i][j];
		}
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
		dp[i][j] = max(left, max(right, max(up, bottom)));
		return dp[i][j];
}

int main(){
    //init
    int row_num, col_num;
    
		while(
		std::cin >> row_num >> col_num)
		{
		if(row_num == 0 || col_num == 0)
			return 0;
		memset(dp, 0, sizeof(dp));
		int** height;
		height = new int*[row_num];
		for(int i = 0; i < row_num; i++)
			height[i] = new int[col_num];

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

    cout << dfs(height, row_num, col_num, fir, sec) << "\n";
		}
		return 0;
}
