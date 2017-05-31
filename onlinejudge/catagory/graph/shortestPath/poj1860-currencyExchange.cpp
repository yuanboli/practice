#include <iostream>
#include <list>

using namespace std;

class CurrencyEdge;

class CurrencyNode{
public:
    list<CurrencyEdge*>* edges;
    double dis;

    CurrencyNode(){
        dis = 0;
				edges = new list<CurrencyEdge*>();
    }

    void addEdge(CurrencyEdge* edge){
        edges->push_back(edge);
    }
};

class CurrencyEdge{
public:
    int startPoint;
    int endPoint;
    double rate;
    double commission;

    CurrencyEdge(int s, int e, double r, double c){
        startPoint = s;
        endPoint = e;
        rate = r;
        commission = c;
    }
};

int currencyNum, pointNum, currency;
double quantity;
//CurrencyNode *nodes;

bool bellman_ford(CurrencyNode* nodes, int nodeNum, int source, double value)
{

    nodes[source].dis = value;
    for(int i = 0; i < nodeNum-1; i++)//v-1 passes
    {
        for(int j = 0; j < nodeNum; j++)
        {
            list<CurrencyEdge*>::iterator itr = nodes[j].edges->begin();
            for(; itr != nodes[j].edges->end(); itr++)
            {
                if(nodes[j].dis != 0)
                {
                    double temp = (nodes[j].dis - ((*itr)->commission))*((*itr)->rate);
                    if(temp > nodes[(*itr)->endPoint].dis)
                    {
                        nodes[(*itr)->endPoint].dis = temp;
                    }
                }
            }
        }
    }

    for(int j = 0; j < nodeNum; j++) //judge negative circle
    {
        list<CurrencyEdge*>::iterator itr = nodes[j].edges->begin();
        for(; itr != nodes[j].edges->end(); itr++)
        {
            if(nodes[j].dis != 0)
            {
                double temp = (nodes[j].dis - (*itr)->commission)*((*itr)->rate);
                if(temp > nodes[(*itr)->endPoint].dis)
                {
                    return true;
                }
            }
        }
    }

    return false;
}

int main(){
    //read data
    cin >> currencyNum >> pointNum >> currency >> quantity;
    CurrencyNode nodes[currencyNum];
    int i = 0;
    while(i < currencyNum){
        int currencyA, currencyB;
        double rateAB, commissionAB, rateBA, commissionBA;
        cin >> currencyA >> currencyB >> rateAB;
        cin >> commissionAB >> rateBA >> commissionBA;

        //build graph
        nodes[currencyA-1].addEdge(new CurrencyEdge(currencyA-1, currencyB-1, rateAB, commissionAB));
        nodes[currencyB-1].addEdge(new CurrencyEdge(currencyB-1, currencyA-1, rateBA, commissionBA));

        i++;
    }

    if(bellman_ford(nodes, currencyNum, currency-1, quantity)){
        cout << "YES\n";
    }
    else{
        cout << "NO\n";
    }



}
