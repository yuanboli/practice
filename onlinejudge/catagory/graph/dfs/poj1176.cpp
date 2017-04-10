#include <iostream>
#include <vector>
#include <set>

using namespace std;

int lightNum, counter;
set<pair<vector<int>, int> > s;
vector<int> on, off;

bool valid(vector<int>& lights){
    //check on
    for(int i = 0; i < on.size(); i++){
        if(lights[on[i] - 1] != 1)
            return false;
    }
    //check off
    for(int i = 0; i < off.size(); i++){
        if(lights[off[i] - 1] != 0){
            return false;
        }
    }
    return true;
}

void display(vector<int>& lights){
    for(int i = 0 ; i < lights.size(); i++){
        cout << lights[i];
    }
    cout << endl;
    return;
}

vector<int> button(vector<int>& lights, int buttonNum){
    vector<int> result(lights);
    if(buttonNum == 1){
        for(int i = 0; i < lights.size(); i++){
            if(lights[i] == 0){
                result[i] = 1;
            }else{
                result[i] = 0;
            }
        }
    }else if(buttonNum == 2){
        for(int i = 0; i < lights.size(); i = i + 2){
            if(lights[i] == 0){
                result[i] = 1;
            }else{
                result[i] = 0;
            }
        }
    }else if(buttonNum == 3){
        for(int i = 1; i < lights.size(); i = i + 2){
            if(lights[i] == 0){
                result[i] = 1;
            }else{
                result[i] = 0;
            }
        }
    }else{
        for(int i = 0; i < lights.size(); i = i + 3){
            if(lights[i] == 0){
                result[i] = 1;
            }else{
                result[i] = 0;
            }
        }
    }


    return result;
}

void dfs(vector<int> lights, int cntr){
    if(s.find(make_pair(lights, cntr)) != s.end()){
        return;
    }
    s.insert(make_pair(lights, cntr));
    if(counter == cntr){
        if(valid(lights)){
            display(lights);
        }
        return;
    }
    cntr++;
    dfs(button(lights, 1), cntr);
    dfs(button(lights, 2), cntr);
    dfs(button(lights, 3), cntr);
    dfs(button(lights, 4), cntr);
    return;
}

int main(){
    //init
    cin >> lightNum >> counter;

		if(counter > 4)
		{
			if(counter % 2 == 1){
				counter = 3;
			}
			else{
				counter = 4;
			}
		}

    while(true){
        int temp;
        cin >> temp;
        if(temp == -1){
            break;
        }
        on.push_back(temp);
    }

    while(true){
        int temp;
        cin >> temp;
        if(temp == -1){
            break;
        }
        off.push_back(temp);
    }

    //search, display result during searching.
    vector<int> lights;
    vector<int>::iterator it = lights.begin();
    lights.insert(it, lightNum, 1);
    dfs(lights, 0);

    return 0;
}
