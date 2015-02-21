#include <bits/stdc++.h>
using namespace std ;

class Graph {
	private :
		int V ;
		vector < vector <int> > adj ;
		vector <bool> visited ;

	public :
		Graph(int v) {
			V = v ;
			adj.resize(V) ;
			visited.resize(V) ;
		}
		void addEdge(int u , int v) {
			adj[u].push_back(v) ;
			adj[v].push_back(u) ;
		}
		bool check_cycle(int u , int parent) {
			visited[u] = true ;
			for(int i = 0 ; i < adj[u].size() ; i++) {
				if(visited[adj[u][i]] == false) {
					if(check_cycle(adj[u][i] , u)) {
						return true ;
					}
				}
				else {
					if(adj[u][i] != parent) {
						return true ;
					}
				}
			}
			return false ;
		}
		bool is_cyclic() {
			for(int i = 0 ; i < V ; i++)
				visited[i] = false ;
			for(int i = 0 ; i < V ; i++)
				if(visited[i] == false)
					if(check_cycle(i , -1))
						return true ;
			return false ;
		}
} ;

int main() {
	int N , M , u , v ;
	scanf("%d %d" , &N , &M) ;
	Graph graph(N) ;
	for(int i = 0 ; i < M ; i++) {
		scanf("%d %d" , &u , &v) ;
		graph.addEdge(u - 1 , v - 1) ;
	}
	if(graph.is_cyclic() == true)
		printf("NO\n") ;
	else
		printf("YES\n") ;
}