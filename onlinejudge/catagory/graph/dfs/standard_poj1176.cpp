#include <iostream>
#include <string>
#include <set>

using namespace std;

int N,C,num = 1;
bool lamps[101],ONs[101],OFFs[101];
bool results[345][101];
set<string> ResSet;

void Change_All()
{
    if (num <= 4)
    {
        for (int i = 1;i <= N;i++)
        {
            results[num][i] = !lamps[i];
        }
    }
    else
    {
        for (int i = 1;i <= N;i++)
        {
            results[num][i] = !results[(num-1)/4][i];
        }
    }
}

void Change_Odds()
{
    if (num <= 4)
    {
        for (int i = 1;i <= N;i++)
        {
            if (i%2==1)
                results[num][i] = !lamps[i];
            else
                results[num][i] = lamps[i];
        }
    }
    else
    {
        for (int i = 1;i <= N;i++)
        {
            if (i%2==1)
                results[num][i] = !results[(num-1)/4][i];
            else
                results[num][i] = results[(num-1)/4][i];
        }
    }
}

void Change_Evens()
{
    if (num <= 4)
    {
        for (int i = 1;i <= N;i++)
        {
            if (i%2==0)
                results[num][i] = !lamps[i];
            else
                results[num][i] = lamps[i];
        }
    }
    else
    {
        for (int i = 1;i <= N;i++)
        {
            if (i%2==0)
                results[num][i] = !results[(num-1)/4][i];
            else
                results[num][i] = results[(num-1)/4][i];
        }
    }
}

void Change_3K1()
{
    if (num <= 4)
    {
        for (int i = 1;i <= N;i++)
        {
            if (i%3==1)
                results[num][i] = !lamps[i];
            else
                results[num][i] = lamps[i];
        }
    }
    else
    {
        for (int i = 1;i <= N;i++)
        {
            if (i%3==1)
                results[num][i] = !results[(num-1)/4][i];
            else
                results[num][i] = results[(num-1)/4][i];
        }
    }
}

bool Check()
{
    for (int i = 1;i <= N;i++)
    {
        if (ONs[i]==true&&results[num][i]==false)
        {
            return false;
        }
        if (OFFs[i]==true&&results[num][i]==true)
        {
            return false;
        }
    }
    return true;
}

int main()
{
    //int C;
    memset(lamps,true,101);
    memset(ONs,false,101);
    memset(OFFs,false,101);
    memset(results,false,sizeof(results));

    for (int i = 1;i <= 4;i++)
    {
        memset(results[i],true,101);
    }

    void (*pfcn[4])();
    pfcn[0] = Change_All;
    pfcn[1] = Change_Odds;
    pfcn[2] = Change_Evens;
    pfcn[3] = Change_3K1;

    cin>>N>>C;
    if(C>4)
    {
        C%=2;
        if (C==1)
        {
            C=3;
        }
        else
        {
            C=4;
        }
    }

    int temp;
    while (1)
    {
        cin>>temp;
        if (temp == -1)
        {
            break;
        }
        ONs[temp] = true;
    }
    while (1)
    {
        cin>>temp;
        if (temp == -1)
        {
            break;
        }
        OFFs[temp] = true;
    }

    int loop = 1;
    while (C--)
    {
        loop *= 4;
        for (int i = 0;i < loop;i++)
        {
            pfcn[i%4]();
            if (C==0)
            {
                if (Check())
                {
                    string str;
                    for (int j = 1;j <= N;j++)
                    {
                        str.push_back(results[num][j]?'1':'0');
                        //cout<<results[num][j]?1:0;
                    }
                    ResSet.insert(str);
                }
            }
            ++num;
        }
    }
    for (set<string>::iterator it = ResSet.begin();it != ResSet.end();it++)
    {
        cout<<*it<<endl;
    }
}

