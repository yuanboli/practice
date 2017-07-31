#include <iostream>
#include <algorithm>
#include <cstring>
using std::cin;
using std::cout;
using std::endl;

int tower[101][102];//one more row for 0, two more column for unified expression
int dp[101][101];

int main(){
    int testCase;
    cin >> testCase;
    while(testCase-- > 0){
        memset(tower, 0, sizeof(tower));
        memset(dp, 0, sizeof(dp));
        int n;
        cin >> n;
        
        for(int i = 1; i < n + 1; i++){
            for(int j = 1; j < i + 1; j++){
                cin >> tower[i][j];
            }
        }

        for(int i = 1; i < n + 1; i++){
            for(int j = 1; j < i + 1; j++){
                if(i == 0){
                    dp[i][j] = tower[i][j];
                }else{
                    dp[i][j] = tower[i][j] + std::max(dp[i-1][j-1], dp[i-1][j]);
                }
            }
        }

        int result = -1;
        for(int i = 1; i < n + 1; i++){
            if(dp[n][i] > result){
                result = dp[n][i];
            }
        }
        cout << result << endl;
        
    }
}