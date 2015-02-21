#include <bits/stdc++.h>
using namespace std ;

class Graph {
	public :
		int V ;
		vector < vector <int> > adj ;
		vector <bool> visited ;
		vector <int> level ;
		Graph(int v) {
			V = v ;
			adj.resize(V) ;
			visited.resize(V) ;
			level.resize(V) ;
		}
		void addEdge(int u , int v) {
			adj[u].push_back(v) ;
			adj[v].push_back(u) ;
		}
		bool explore(int u , int parent) {
			if(parent == -1)
				level[u] = 0 ;
			else
				level[u] = 1 + level[parent] ;
			visited[u] = true ;
			for(int i = 0 ; i < adj[u].size() ; i++) {
				if(!visited[adj[u][i]]) {
					if(explore(adj[u][i] , u))
						return true ;
				}
				else {
					if((level[adj[u][i]] - level[u]) % 2 == 0)
						return true ; //means suspicious
				}
			}
			return false ;
		}
		bool DepthFirstSearch() {
			for(int i = 0 ; i < V ; i++)
				visited[i] = false ;
			for(int i = 0 ; i < V ; i++)
				if(!visited[i])
					if(explore(i , -1))
						return true ;
			return false ;
		}
} ;

int main() {
	int T , V , E ;
	int u , v ;
	scanf("%d" , &T) ;
	for(int z = 1 ; z <= T ; z++) {
		scanf("%d %d" , &V , &E) ;
		Graph g(V) ;
		for(int i = 0 ; i < E ; i++) {
			scanf("%d %d" , &u , &v) ;
			g.addEdge(u - 1 , v - 1) ;
		}
		printf("Scenario #%d:\n" , z) ;
		if(g.DepthFirstSearch())
			printf("Suspicious bugs found!\n") ;
		else
			printf("No suspicious bugs found!\n") ;
	}
}