#include <iostream>
#include <vector>
#include <set>

using namespace std;

int main(){
	vector<int> firstDay;
	vector<int> secondDay;
	vector<int> thirdDay;
	firstDay.reserve(16);
	secondDay.reserve(16);
	thirdDay.reserve(16);
	while(cin >> firstDay[0]){
		for(int i = 1; i < 16; i++){
			cin >> firstDay[i];
		}
		for(int i = 0; i < 16; i++){
			cin >> secondDay[i];
		}
		for(int i = 0; i< 16; i++){
			cin >> thirdDay[i];
		}

		set<int> used[16];
		for(int i = 0; i < 16; i++)
			used[i].insert(i);

		for(int days = 0; days < 3; days++){
			for(int i = 0; i < 16; i++){
				int self, group;
				self = i % 4;
				group = i / 4;
				for(int j = 0; j < 4; j++){
					if(j != self){
						used[i+group*4].insert(j+group*4);
					}
				}
			}
		}

		int j = 0; 
		j++;
		j = j + 1;
		
	}
}
