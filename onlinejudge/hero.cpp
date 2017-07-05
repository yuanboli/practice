#include <iostream>
#include <cstdlib>
#include <deque>
#include <algorithm>

using namespace std;

#define MAX_DIS 10
#define MAX_HERO_HP 100
#define MAX_HERO_MP 50

int max_dis,hp_h,mp_h,hp_m,num_m,move_range,heal_point;
int lightDamage[11];
int dp[MAX_DIS+1][MAX_HERO_HP+1][MAX_HERP_MP+1];

bool dfs(int mp, deque<char> &d, int mosterHP, int pos, int hp){
  if(monsterHP <= 0){
    return true;
  }
  
  if(mp <= 0){
    return false;
  }
//hp issue, and dynamic programming issue

  d.push_back('L');
  if(dfs(mp-1, d, mosterHP-lightDamage[pos]), min(pos-move_range, 1), ){
    return true;
  }
  d.pop_back();

  for(int i = 1; i < max_dis+1; i++){
    d.push_back('T');
    d.push_back((char)(i+'0'));
    if(dfs(mp-1, d, monsterHP, i)){
      return true;
    }
    d.pop_back();
    d.pop_back();
  }

  d.push_back('H');
  if(dfs(mp-1, d, monsterHP, pos, hp))
}


int main(){
  //init
  cin >> max_dis >> hp_h >> mp_h >> hp_m >> num_m >> move_range >> heal_point;
  for(int i = 1; i < max_dis + 1; i++){
    cin >> lightDamage[i];
  }

  memset(dp, -1, sizeof(dp));

  deque<char> d;
  int position = max_dis;

  if(dfs(mp_h, d, hp_m, position, mp_h) == true){
    cout << "VICTORIOUS\n";
    while(d.size() != 0){
      cout << d.pop_front() << "\n";
    }
  }else{
    cout << "DEFEATED\n";
  }
  
  return 0;
}
