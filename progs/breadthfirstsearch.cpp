#include <iostream>
#include <stdio.h>
#include <vector>
#include <queue>
using namespace std ;

class Binary {
	private :
		vector <int> node ;
	public :
		Binary() {
			
		}
		void add(int x) {
			node.push_back(x) ;
			return ;
		}
		vector <int> bfs() {
			vector <int> a ;
			queue <int> indices ;
			queue <int> q ;
			q.push(node[0]) ;
			indices.push(0) ;
			while(!q.empty()) {
				int curr = indices.front() ;
				if(2 * curr + 1 < node.size()) {
					indices.push(2 * curr + 1) ;
					q.push(node[2 * curr + 1]) ;
				}
				if(2 * curr + 2 < node.size()) {
					indices.push(2 * curr + 2) ;
					q.push(node[2 * curr + 2]) ;
				}
				a.push_back(q.front()) ;
				q.pop() ;
				indices.pop() ;
			}
			return a ;
		}
} ;

int main() {
	Binary b ;
	for(int i = 0 ; i < 20 ; i++)
		b.add(i) ;
	vector <int> a = b.bfs() ;
	for(int i = 0 ; i < a.size() ; i++)
		cout << a[i] << endl ;
}
