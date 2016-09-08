#pragma GCC diagnostic error "-std=c++11"
#include <iostream>
#include <cstring>
#include <vector>
using namespace std;
class Graph_traverse
{
private:
	int n;
	vector<int>* edges;
	bool *visited;
public:
	Graph_traverse(int input_n){
		n = input_n;
		edges = new vector<int>[n];
		visited = new bool[n];
		memset(visited,0,n);
	}
	~Graph_traverse(){
		delete[] edges;
		delete[] visited;
	}
	void insert(int x,int y){
		edges[x].push_back(y);
		edges[y].push_back(x);
	}
	void dfs(int vertex) {
        cout<<vertex<<endl;
        visited[vertex] = true;
        for(int adj_vertex: edges[vertex]){
            if(!visited[adj_vertex]){
                dfs(adj_vertex);
            }
        }
    }
	 void bfs(int start_vertex) {
        queue<int> bfs_queue;
        bfs_queue.push(start_vertex);
        visited[start_vertex] = true;
        while(!bfs_queue.empty()){
            int vertex = bfs_queue.front();
            cout<<vertex<<endl;
            bfs_queue.pop();
            for(int adj_vertex: edges[vertex]){
                if(!visited[adj_vertex]){
                    visited[adj_vertex]=true;
                    bfs_queue.push(adj_vertex);
                }
            }
        }
    }
};
int main(int argc, char const *argv[])
{
	/* code */
	return 0;
}