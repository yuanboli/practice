#include <set>
#include <queue>
#include <iostream>

using std::queue;
using std::set;
using std::cin;
using std::cout;
using std::pair;


class Status{
public:
	static int capacityA;
	static int capacityB;
	int sizeA;
	int sizeB;
	queue<int>* actions;
	void print();
	Status(int a, int b){
		sizeA = a;
		sizeB = b;
		actions = new queue<int>;
	}
} ;


void Status::print(){
	while(!actions->empty()){
		int actNum = actions->front();
		actions->pop();

		switch(actNum){
			case 0:{
				cout << "fill A\n";
				break;
			}
			case 1:{
				cout << "fill B\n";
				break;
			}
			case 2:{
				cout << "empty A\n";
				break;
			}
			case 3:{
				cout << "empty B\n";
				break;
			}
			case 4:{
				cout << "pour A B\n";
				break;
			}
			case 5:{
				cout << "pour B A\n";
				break;
			}
		}
	}
	cout << "success\n";
}


Status action(Status cur, int actNum)
{
	switch(actNum)
	{
		case 0:
		{
			cur.sizeA = Status::capacityA;
			break;
		}
		case 1:
		{
			cur.sizeB = Status::capacityB;
			break;
		}
		case 2:
		{
			cur.sizeA = 0;
			break;
		}
		case 3:
		{
			cur.sizeB = 0;
			break;
		}
		case 4:
		{
			int pourAmount;
			if(cur.sizeA < Status::capacityB - cur.sizeB)
				pourAmount = cur.sizeA;
			else
				pourAmount = Status::capacityB - cur.sizeB;

			cur.sizeA -= pourAmount;
			cur.sizeB += pourAmount;
			break;
		}
		case 5:
		{
			int pourAmount;
			if(cur.sizeB < Status::capacityA - cur.sizeA)
				pourAmount = cur.sizeB;
			else
				pourAmount = Status::capacityA - cur.sizeA;

			cur.sizeA += pourAmount;
			cur.sizeB -= pourAmount;
			break;
		}
	}

	cur.actions->push(actNum);
	return cur;
}

int Status::capacityA;
int Status::capacityB;


int main(int argc, char* argv[]){
	int goal;
	while(cin >> Status::capacityA >> Status::capacityB >> goal){
		//set up queue and set
		queue<Status> q;
		set<pair<int, int> > s;

		Status init = Status(0, 0);
		q.push(init);
		while(!q.empty()){
			//get the Status that needs to be dealt with
			Status current = q.front();
			q.pop();
			if(current.sizeB == goal){
				current.print();
				return 0;
			}
			for(int i = 0; i < 6; i++){
				Status newStatus = action(current, i);
				if(s.find(std::make_pair(newStatus.sizeA, newStatus.sizeB)) != s.end())
				{
					s.insert(std::make_pair(newStatus.sizeA, newStatus.sizeB));
					q.push(newStatus);
				}
			}
		}
	}
	return 0;
}



