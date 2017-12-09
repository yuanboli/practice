#include <iostream>
#include <ctime>

using namespace std;

#define INFINITY 0x7f7f7f7f  //infinity cannot be too large, because it will be added with a number, possibly overflow
#define MAXNUM 10000 
int map[MAXNUM][MAXNUM];// edge length info
int visited[MAXNUM];  
int dist[MAXNUM];  

int dijkstra(int nv, int src, int dest){  
    int min,min_i;  
    for(int i = 0; i < nv; i++){  
        dist[i] = map[src][i];  
        visited[i] = 0;  
    }  
    visited[src] = 1;  
    for(int i = 1; i < nv; i++){  
        min = INFINITY;  
        for(int j = 0; j < nv; j++){  
            if(!visited[j] && dist[j] < min){  
                min = dist[j];  
                min_i = j;  
            }  
        }  
        visited[min_i] = 1;  
        for(int k = 0; k < nv; k++){  
            if(!visited[k] && (dist[k] > (dist[min_i] + map[min_i][k])))  
                dist[k] = dist[min_i] + map[min_i][k];  
        }  
    }  
    return dist[dest];  
}  

int main(){
    int n; // vertex number
    cin >> n;
    for(int i = 0; i < n; i++)
        for(int j = 0; j < n; j++)
            map[i][j] = INFINITY;
    int i, j;
    while(cin >> i >> j){
        cin >> map[i][j];
    }

    clock_t begin, end;
    
    begin = clock();
    for(int i = 0; i < 10; i++)
        dijkstra(n, 0, n-1);
    end = clock();
    cout << "c++ running time: " << (double)(end-begin) / (double) CLOCKS_PER_SEC << ".\n";
    return 0;
}
