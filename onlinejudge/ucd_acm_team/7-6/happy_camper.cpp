#include <algorithm>
#include <iostream>
using namespace std;

long long l; //limit
long long p; //period
long long v; //vacation
int main(){
    int caseNum = 1;
    while(cin >> l >> p >> v){
        if(l == 0 && p == 0 && v == 0){
            break;
        }
        long long t = v / p;
        long result = t * l + min(l, v % p);
        cout << "Case " << caseNum << ": " << result << endl;
        caseNum ++;
    }
    return 0;
}
