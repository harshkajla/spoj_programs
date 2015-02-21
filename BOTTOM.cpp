#include <bits/stdc++.h>
using namespace std ;

class Graph {
	public:
		int V ;
		vector < vector <int> > adj ;
		vector < vector <int> > adj_transpose ;
		vector <bool> visited ;
		stack <int> topology ;
		vector <int> component_number ;
		vector <int> answer ;
	public:
		Graph(int v) {
			V = v ;
			adj.resize(V + 1) ;
			adj_transpose.resize(V + 1) ;
			visited.resize(V + 1) ;
			component_number.resize(V + 1) ;
		}
		void addEdge(int u , int v) {
			adj[u].push_back(v) ;
		}
		void transpose() {
			for(int i = 1 ; i <= V ; i++) {
				for(int j = 0 ; j < adj[i].size() ; j++)
					adj_transpose[adj[i][j]].push_back(i) ;
			}
		}
		void dfs(int u) {
			visited[u] = true ;
			for(int i = 0 ; i < adj_transpose[u].size() ; i++)
				if(!visited[adj_transpose[u][i]])
					dfs(adj_transpose[u][i]) ;
			topology.push(u) ;
		}
		void connected(int u , int& number) {
			visited[u] = true ;
			for(int i = 0 ; i < adj[u].size() ; i++)
				if(!visited[adj[u][i]]) {
					component_number[adj[u][i]] = number ;
					connected(adj[u][i] , number) ;
				}
		}
		void printSCC() {
			transpose() ;
			for(int i = 1 ; i <= V ; i++)
				visited[i] = false ;
			for(int i = 1 ; i <= V ; i++)
				if(!visited[i])
					dfs(i) ;
			for(int i = 1 ; i <= V ; i++)
				visited[i] = false ;
			int number = 0 ;
			while(topology.empty() == false) {
				int curr = topology.top() ;
				topology.pop() ;
				if(!visited[curr]) {
					component_number[curr] = number ;
					connected(curr , number) ;
					number++ ;
				}
			}
			vector <bool> valid_components(number , true) ;
			for(int i = 1 ; i <= V ; i++) {
				for(int j = 0 ; j < adj[i].size() ; j++) {
					if(component_number[i] != component_number[adj[i][j]])
						valid_components[component_number[i]] = false ;
				}
			}
			for(int i = 1 ; i<= V ; i++)
				if(valid_components[component_number[i]] == true)
					answer.push_back(i) ;
		}
} ;

int main() {
	int V , E , u , v ;
	while(true) {
		scanf("%d" , &V) ;
		if(V == 0)
			break ;
		Graph g(V) ;
		scanf("%d" , &E) ;
		for(int i = 0 ; i < E ; i++) {
			scanf("%d %d" , &u , &v) ;
			g.addEdge(u , v) ;
		}
		g.printSCC() ;
		for(int i = 0 ; i < g.answer.size() ; i++)
			cout << g.answer[i] << " " ;
		cout << endl ;
	}
}