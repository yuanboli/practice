#include <iostream>
#include <algorithm>
#include <vector>
#include <memory>
#include <string>

using namespace std;

int num;
int dimension;

class Node{
public:
	int id;
	vector<int>* box;
	shared_ptr<vector<Node*> > edges; 

	Node(int i, vector<int>* b){
		id = i + 1;
		box = b;
		edges = shared_ptr<vector<Node*> > (new vector<Node*>);
	}

	//return true if n can be contained in the object
	bool contain(Node* n){
		for(int i = 0; i < box->size(); i++){
			if(n->box->at(i) > box->at(i))
				return false;
		}
		return true;
	}

	void addEdge(Node* n){
		edges.get()->push_back(n);
	}
} ;


vector<int> dfs(Node* node){
	vector<int> path;
	if(node->edges.get()->size() == 0){
		path.push_back(node->id);
		return path;
	}
	int res = 0;
	vector<Node*> edges = *(node->edges.get());
	for(int i = 0; i < edges.size(); i++){
		vector<int> tmp = dfs(edges[i]);
		if(tmp.size() > res){
			res = tmp.size();
			path = tmp;
		}
	}
	path.push_back(node->id);
	return path;
}

int main(){
	while(cin >> num >> dimension){
		//fetch all input
		shared_ptr<Node> nodes[num];
		vector<int> boxes[num];
		for(int i = 0; i < num; i++){
			for(int j = 0; j < dimension; j++){
				int tmp;
				cin >> tmp;
				boxes[i].push_back(tmp);
			}
			sort(boxes[i].begin(), boxes[i].end());
			nodes[i] = shared_ptr<Node>(new Node(i, &(boxes[i])));
		}

		for(int i = 0; i < num; i++){
			for(int j = 0; j < num; j++){
				if(i == j)
					continue;
				if(nodes[i].get()->contain(nodes[j].get())){
					nodes[i].get()->addEdge(nodes[j].get());
				}			
			}
		}

		int res = 0;
		vector<int> path;
		for(int i = 0; i < num; i++){
			vector<int> tmp = dfs(nodes[i].get());
			if(tmp.size() > res){
				res = tmp.size();
				path = tmp;
			}
		}

		cout << res << endl;
		for(int i = 0; i < path.size(); i++){
			cout << path[i];
			if(i != path.size() - 1){
				cout << " ";
			}
		}
		cout << endl;
	}

	return 0;
}
