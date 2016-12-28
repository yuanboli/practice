#include <iostream>
#include <string>
using namespace std;

void match(string s, string::iterator* itr);

int main(int argc, char* argv[])
{
    string s("+-+--aaaaaa");
    string::iterator itr = s.begin();
    match(s, &itr);
    cout << endl;
    return 0;
}

void match(string s, string::iterator* itr)
{
    if(*itr == s.end())
        return;
    switch(**itr)
    {
    case 'a':
        (*itr)++;
        cout << 'a';
        break;
    case '+':
        (*itr)++;
        match(s, itr);
        cout << '+';
        match(s, itr);
        break;
    case '-':
        (*itr)++;
        match(s, itr);
        cout << '-';
        match(s, itr);
        break;
    default:
        cout << "error";
        return;
    }
}
