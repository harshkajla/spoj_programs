#include <bits/stdc++.h>
using namespace std ;

class Graph {
	public :
		int V ;
		vector < vector <int> > adj ;
		vector <bool> visited ;
		vector <int> length ;

		Graph(int v) {
			V = v ;
			adj.resize(V) ;
			visited.resize(V) ;
			length.resize(V) ;
		}
		void addEdge(int u , int v) {
			adj[u].push_back(v) ;
			adj[v].push_back(u) ;
		}
		void explore(int u) {
			visited[u] = true ;
			for(int i = 0 ; i < adj[u].size() ; i++) {
				if(!visited[adj[u][i]]) {
					length[adj[u][i]] = 1 + length[u] ;
					explore(adj[u][i]) ;
				}
			}
		}
} ;

int main() {
	int N , u , v ;
	scanf("%d" , &N) ;
	Graph g(N) ;
	N-- ;
	while(N--) {
		scanf("%d %d" , &u , &v) ;
		g.addEdge(u - 1 , v - 1) ;
	}
	for(int i = 0 ; i < g.V ; i++)
		g.visited[i] = false ;
	g.length[u - 1] = 0 ;
	g.explore(u - 1) ;
	int l = 0 ;
	for(int i = 0 ; i < g.V ; i++) {
		if(g.length[i] > l) {
			l = g.length[i] ;
			u = i ;
		}
	}
	g.length[u] = 0 ;
	for(int i = 0 ; i < g.V ; i++)
		g.visited[i] = false ;
	g.explore(u) ;
	l = 0 ;
	for(int i = 0 ; i < g.V ; i++) {
		if(g.length[i] > l) {
			l = g.length[i] ;
		}
	}
	printf("%d" , l) ;
}