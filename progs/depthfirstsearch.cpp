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
		void dfs(vector <int> & a , int i) {
			cout << "dfs called on : " << node[i] << endl ;
			if(2 * i + 1 < node.size())
				dfs(a , 2 * i + 1) ;
			a.push_back(node[i]) ;
			if(2 * i + 2 < node.size())
				dfs(a , 2 * i + 2) ;
			return ;
		}
} ;

int main() {
	Binary b ;
	for(int i = 0 ; i < 20 ; i++)
		b.add(i) ;
	vector <int> a ;
	b.dfs(a , 0) ;
	for(int i = 0 ; i < a.size() ; i++)
		cout << a[i] << endl ;
}
