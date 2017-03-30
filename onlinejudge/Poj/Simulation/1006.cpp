#include <iostream>
#include <vector>

using namespace std;

int main(){
    int p,  //physical peak
        e,  //emotional peak
        i,  //intellectual peak
        d;  //given date

    int turn = 1;

    while(cin >> p >> e >> i >> d){
        if(p == -1){
            break;

        }

        int j, date;
        for(j = 1; j <= 21252; j++){
            date = j;
            if((d+j - p) % 23 == 0 && (d+j - e) % 28 == 0 && (d+j - i) % 33 == 0){
                break;
            }
        }
        cout << "Case " << turn << ": the next triple peak occurs in " << date << " days.\n";

        turn ++;
    }
    return 0;
}
