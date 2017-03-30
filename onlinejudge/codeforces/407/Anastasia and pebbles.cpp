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
            if(pebbleNums[i] > pocket_max * 2){
                int times = pebbleNums[i] / pocket_max / 2;
                res += times;
                pebbleNums[i] = pebbleNums[i] - times * 2 * pocket_max;
            }

            if(pebbleNums[i] == 0){
                i++;
            }
            if(i >= pebble_type_num)
                break;
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
