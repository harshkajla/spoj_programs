#include <bits/stdc++.h>
using namespace std ;

class Graph {
	public:
		int V ;
		vector < vector <int> > adj , adj_transpose , scc ;
		vector <bool> visited ;
		stack <int> topology ;
		vector <int> component_number , answer ;
	public:
		Graph(int v) {
			V = v ;
			adj.resize(V + 1) ;
			visited.resize(V + 1) ;
			adj_transpose.resize(V + 1) ;
			component_number.resize(V + 1) ;
		}
		void addEdge(int u , int v) {
			adj[u].push_back(v) ;
		}
		void transpose() {
			for(int i = 1 ; i <= V ; i++)
				for(int j = 0 ; j < adj[i].size() ; j++)
					adj_transpose[adj[i][j]].push_back(i) ;
		}
		void explore(int source) {
			visited[source] = true ;
			for(int i = 0 ; i < adj[source].size() ; i++) {
				if(!visited[adj[source][i]])
					explore(adj[source][i]) ;
			}
			topology.push(source) ;
		}
		void getSCC() {
			for(int i = 1 ; i <= V ; i++)
				visited[i] = false ;
			for(int i = 1 ; i <= V ; i++)
				if(!visited[i])
					explore(i) ;
			for(int i = 1 ; i <= V ; i++)
				visited[i] = false ;
			transpose() ;
			int number = 0 ;
			while(topology.empty() == false) {
				int curr = topology.top() ;
				topology.pop() ;
				if(!visited[curr]) {
					vector <int> current_component ;
					solve(curr , current_component , number) ;
					scc.push_back(current_component) ;
					number++ ;
				}
			}
			vector <int> validSCCs ;
			vector <bool> accepted(scc.size() , true) ;
			for(int i = 0 ; i < scc.size() ; i++) {
				for(int j = 0 ; j < scc[i].size() ; j++) {
					for(int k = 0 ; k < adj_transpose[j].size() ; k++)
						if(component_number[j] != component_number[adj_transpose[j][k]])
							accepted[i] = false ;
				}
			}
			for(int i = 0 ; i < accepted.size() ; i++) {
				if(accepted[i]) {
					for(int j = 0 ; j < scc[i].size() ; j++)
						answer.push_back(scc[i][j]) ;
				}
			}
		}
		void solve(int u , vector <int>& current_component , int number) {
			component_number[u] = number ;
			visited[u] = true ;
			current_component.push_back(u) ;
			for(int i = 0 ; i < adj_transpose[u].size() ; i++)
				if(!visited[adj_transpose[u][i]])
					solve(adj_transpose[u][i] , current_component , number) ;
		}
} ;

int main() {
	int T , N , M , u , v ;
	scanf("%d" , &T) ;
	while(T--) {
		scanf("%d %d" , &N , &M) ;
		Graph g(N) ;
		for(int i = 0 ; i < M ; i++) {
			scanf("%d %d" , &u , &v) ;
			g.addEdge(v , u) ;
		}
		g.getSCC() ;
		for(int i = 0 ; i < g.answer.size() ; i++)
			cout << g.answer[i] << " " ;
		cout << endl ;
	}
}