#include <cctype>
#include <iostream>
#include <string>
#include <map>
using namespace std;

//will assume itr will not be line.end()
string nextToken(string::iterator itr, string str){
    string result;
    if(isupper(*itr)){
        //a new element
        result = to_string(*itr);
        itr++;
        while(itr != str.end() && islower(*itr)){
            result += to_string(*itr);
            itr++;
        }
    }else if(*itr == '('){
        itr++;
        return "(";
    }else if(*itr == ')'){
        itr++;
        return ")";
    }else if(isdigit(*itr)){
        result = to_string(*itr);
        itr++;
        while(itr != str.end() && isdigit(*itr)){
            result += to_string(*itr);
            itr++;
        }
    }
    return result;


}

class Env{
public:
    map<string, int> *atomCounter;
    Env(){
        atomCounter = new map<string, int>();
    }
    ~Env(){
        free(atomCounter);
    }
};

//get the iterator of the string, return the newly allocated Env
Env* getOneLevelEnv(string::iterator itr, string str){
    string s("");
    pair<string, int> p = make_pair(s, 1);
    Env *e = new Env();
    for(itr; itr != str.end(); itr++){
        string token = nextToken(itr, str);
        if(isupper(token[0])){
            //token represents an atom
            if(p.first != ""){
                e->atomCounter->insert(p);
            }
            p = make_pair(token, 1);
        }
    }
    return e;
}

string line = string();
int main(){
    while(getline(cin, line)){
        Env* e = getOneLevelEnv(line.begin(), line);
        map<string, int>::iterator itr = e->atomCounter->begin();
        cout << itr->second << itr->first;
        itr++;
        for(itr; itr != e->atomCounter->end(); itr++){
            cout << "+" << itr->second << itr->first;
        }
        cout << endl;
        getchar();
        free(e);
    }
}