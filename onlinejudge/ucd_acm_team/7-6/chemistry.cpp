#include <cctype>
#include <iostream>
#include <string>
#include <map>
using namespace std;

//will assume itr will not be line.end()
string nextToken(string::iterator& itr, string& str){
    string result;
    if(isupper(*itr)){
        //a new element
        result = string(1, *itr);
        itr++;
        while(itr != str.end() && islower(*itr)){
            result += string(1, *itr);
            itr++;
        }
    }else if(*itr == '('){
        itr++;
        return "(";
    }else if(*itr == ')'){
        itr++;
        return ")";
    }else if(isdigit(*itr)){
        result = string(1, *itr);
        itr++;
        while(itr != str.end() && isdigit(*itr)){
            result += string(1, *itr);
            itr++;
        }
    }
    return result;


}

class Env{
public:
    map<string, long long> *atomCounter;
    Env(){
        atomCounter = new map<string, long long>();
    }
    ~Env(){
        free(atomCounter);
    }

	void mul(long long n){
		for(map<string, long long>::iterator itr = atomCounter->begin(); itr != atomCounter->end(); itr++){
			itr->second = itr->second * n;
		}
	}

	void add(Env* rhs){
		for(map<string, long long>::iterator itr = rhs->atomCounter->begin(); itr != rhs->atomCounter->end(); itr++){
			map<string, long long>::iterator targetItr = atomCounter->find(itr->first);
			if(targetItr != atomCounter->end()){
				targetItr->second += itr->second;
			}else{
				atomCounter->insert(make_pair(itr->first, itr->second));
			}
		}
	}
};

//get the iterator of the string, return the newly allocated Env
Env* getOneLevelEnv(string::iterator& itr, string& str){
    string s("");
    pair<string, long long> p = make_pair(s, 1);
    Env *e = new Env();
	Env *temp = NULL;
    while(itr != str.end()){
        string token = nextToken(itr, str);
        if(isupper(token[0])){
            //token represents an atom
			if(temp != NULL){
				e->add(temp);
				free(temp);
				temp = NULL;
			}else if(p.first != ""){
				map<string, long long>::iterator tempItr = e->atomCounter->find(p.first);
				if(tempItr != e->atomCounter->end()){
					tempItr->second += p.second;
				}else{
                	e->atomCounter->insert(p);
				}
				//p = make_pair("", 1);
            }
            p = make_pair(token, 1);
        }else if(isdigit(token[0])){
			if(temp != NULL){
				//precede it is a block
				temp->mul(stoll(token));
			}else{
				p.second = stoll(token);
			}
		}else if(token == "("){
			if(temp != NULL){
				e->add(temp);
				free(temp);
				temp = NULL;
			}else if(p.first != ""){
				map<string, long long>::iterator tempItr = e->atomCounter->find(p.first);
				if(tempItr != e->atomCounter->end()){
					tempItr->second += p.second;
				}else{
                	e->atomCounter->insert(p);
				}
				p = make_pair("", 1);
			}
			temp = getOneLevelEnv(itr, str);
		}else{
			//token == ")"
			//itr++;
			break;
		}
    }
	if(temp != NULL){
		e->add(temp);
		free(temp);
		temp = NULL;
	}else if(p.first != ""){
		map<string, long long>::iterator tempItr = e->atomCounter->find(p.first);
		if(tempItr != e->atomCounter->end()){
			tempItr->second += p.second;
		}else{
        	e->atomCounter->insert(p);
		}
		p = make_pair("", 1);
	}
	
    return e;
}

string line = string();
int main(){
    while(getline(cin, line)){
		string::iterator itr_str = line.begin();
        Env* e = getOneLevelEnv(itr_str, line);
        map<string, long long>::iterator itr = e->atomCounter->begin();
        cout << itr->second << itr->first;
        itr++;
        for(itr; itr != e->atomCounter->end(); itr++){
            cout << "+" << itr->second << itr->first;
        }
        cout << endl;
        free(e);
    }
}
