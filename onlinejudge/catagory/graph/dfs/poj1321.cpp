#include <iostream>
#include <string>
#include <cstring>
#include <vector>
#include <set>

using namespace std;
int n;// n*n is the area chessboard may use
int k;// k chess pieces we will use


/**
*@param rest is the chess pieces number still need to be used
*@return return the total ways to put all the chess pieces
*/
bool valid(int board[8][8], int i, int j){
    for(int index = 0; index < 8; index++){
        if(board[i][index] == 1)
            return false;
        if(board[index][j] == 1)
            return false;
    }
    return true;
}

int solve(int board[8][8], set<pair<int, int> > available, int rest){
    int res = 0;
    for(set<pair<int, int> >::iterator it = available.begin(); it != available.end(); it++){
        int i = it->first;
        int j = it->second;
        if(valid(board, i, j)){
            board[i][j] = 1;
            available.erase(it);
            res += solve(board, available, rest-1);
            available.insert(make_pair(i, j));
            board[i][j] = 0;
        }
    }
    return res;
}


int main(){
    while(cin >> n >> k){
        if(n == -1 && k == -1){
            break;
        }

        string str[n]; // stands for a line of board area
        set<pair<int, int> > available;
        for(int i = 0; i < n; i++){
            cin >> str[i];
            for(int j = 0; j < n; j++){
                if(str[i][j] == '#'){
                    available.insert(make_pair(i, j));
                }
            }
        }

        int board[8][8];
        memset(board, 0, sizeof(board));
        int res = solve(board, available, k);
        cout << res << endl;

    }
}
