#include <algorithm>
#include <iostream>
using namespace std;

int l; //limit
int p; //period
int v; //vacation
int main(){
    int caseNum = 1;
    while(cin >> l >> p >> v){
        if(l == 0 && p == 0 && v == 0){
            break;
        }
        int t = v % p;
        int result = t * l + min(l, v - t * p);
        cout << "Case " << caseNum << ": " << result << endl;
        caseNum ++;
    }
}
