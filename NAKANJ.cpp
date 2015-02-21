#include <bits/stdc++.h>
using namespace std ;

int distance_[64][64] ;

class Graph {
	public:
		int V ;
		vector < vector <int> > adj ;
		vector <int> visited ;
		vector <int> dist ;
	public:
		Graph(int v) {
			V = v ;
			adj.resize(V) ;
			visited.resize(V) ;
			dist.resize(V) ;
		}
		void addEdge(int u , int v) {
			adj[u].push_back(v) ;
		}
		void BreadthFirstSearch(int source) {
			for(int i = 0 ; i < V ; i++)
				visited[i] = false ;
			for(int i = 0 ; i < V ; i++)
				distance_[source][i] = 200000000 ;
			distance_[source][source] = 0 ;
			queue <int> data ;
			data.push(source) ;
			visited[source] = true ;
			int curr ;
			while(data.empty() == false) {
				curr = data.front() ;
				for(int i = 0 ; i < adj[curr].size() ; i++) {
					if(!visited[adj[curr][i]]) {
						visited[adj[curr][i]] = true ;
						data.push(adj[curr][i]) ;
					}
					distance_[source][adj[curr][i]] = min(1 + distance_[source][curr] , distance_[source][adj[curr][i]]) ;
				}
				data.pop() ;
			}
		}
} ;

int map_node(int x , char y) {
	return (y - 'a') + 8 * (x - 1) ;
}

int main() {
	Graph chess(64) ;
	int x ;
	char y ;
	for(int i = 1 ; i <= 8 ; i++) {
		for(int j = 'a' ; j <= 'h' ; j++) {
			x = i + 2 ; y = j + 1 ;
			if(1 <= x && x <= 8 && 'a' <= y && y <= 'h')
				chess.addEdge(map_node(i , j) , map_node(x , y)) ;
			x = i + 1 ; y = j + 2 ;
			if(1 <= x && x <= 8 && 'a' <= y && y <= 'h')
				chess.addEdge(map_node(i , j) , map_node(x , y)) ;
			x = i - 1 ; y = j + 2 ;
			if(1 <= x && x <= 8 && 'a' <= y && y <= 'h')
				chess.addEdge(map_node(i , j) , map_node(x , y)) ;
			x = i - 2 ; y = j + 1 ;
			if(1 <= x && x <= 8 && 'a' <= y && y <= 'h')
				chess.addEdge(map_node(i , j) , map_node(x , y)) ;
			x = i - 2 ; y = j - 1 ;
			if(1 <= x && x <= 8 && 'a' <= y && y <= 'h')
				chess.addEdge(map_node(i , j) , map_node(x , y)) ;
			x = i - 1 ; y = j - 2 ;
			if(1 <= x && x <= 8 && 'a' <= y && y <= 'h')
				chess.addEdge(map_node(i , j) , map_node(x , y)) ;
			x = i + 1 ; y = j - 2 ;
			if(1 <= x && x <= 8 && 'a' <= y && y <= 'h')
				chess.addEdge(map_node(i , j) , map_node(x , y)) ;
			x = i + 2 ; y = j - 1 ;
			if(1 <= x && x <= 8 && 'a' <= y && y <= 'h')
				chess.addEdge(map_node(i , j) , map_node(x , y)) ;
		}
	}
	for(int i = 0 ; i < 64 ; i++)
		chess.BreadthFirstSearch(i) ;
	int T ;
	string a , b ;
	scanf("%d" , &T) ;
	while(T--) {
		cin >> a ;
		cin >> b ;
		//cout << map_node(a[1] - '0' , a[0]) << " " << map_node(b[1] - '0' , b[0]) << endl ;
		cout << distance_[map_node(a[1] - '0' , a[0])][map_node(b[1] - '0' , b[0])] << endl ;
	}
}