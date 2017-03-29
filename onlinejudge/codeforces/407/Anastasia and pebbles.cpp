#include <cstring>
#include <iostream>

using namespace std;

int main()
{
    int pocket_max, pebble_type_num;
    while(cin >> pebble_type_num >> pocket_max){
        int pebbleNums[pebble_type_num];
        for(int i = 0; i < pebble_type_num; i++){
            cin >> pebbleNums[i];
        }

        int res = 0;
        int i = 0;
        while(i < pebble_type_num){
            res++;
            //fill a pocket
            if(pebbleNums[i] <= pocket_max){
                pebbleNums[i] = 0;
                i++;
            }else{
                pebbleNums[i] -= pocket_max;
            }

            //fill another pocket
            if(i >= pebble_type_num)
                break;
            if(pebbleNums[i] <= pocket_max){
                pebbleNums[i] = 0;
                i++;
            }else{
                pebbleNums[i] -= pocket_max;
            }
        }

        cout << res << "\n";
    }
}
