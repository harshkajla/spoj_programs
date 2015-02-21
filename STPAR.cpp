#include <bits/stdc++.h>
using namespace std ;

int main() {
	int n , x ;
	while(true) {
		int needed = 1 ;
		scanf("%d" , &n) ;
		if(n == 0)
			break ;
		stack <int> num_stack ;
		queue <int> num_queue ;
		for(int i = 0 ; i < n ; i++) {
			scanf("%d" , &x) ;
			num_queue.push(x) ;
		}
		bool possible = true ;
		while(true) {
			if(num_queue.empty() == true)
				if(num_stack.empty() == false)
					if(num_stack.top() != needed) {
						//cout << num_stack.top() << " " << needed << endl ;
						possible = false ;
						break ;
					}
			if(num_queue.empty() == true && num_stack.empty() == true) {
				possible = true ;
				break ;
			}
			if(num_queue.empty() == true) {
				num_stack.pop() ;
				needed++ ;
			}
			else {
				if(num_queue.front() == needed) {
					num_queue.pop() ;
					needed++ ;
				}
				else {
					if(num_stack.empty() == false) {
						if(num_stack.top() == needed) {
							num_stack.pop() ;
							needed++ ;
						}
						else {
							num_stack.push(num_queue.front()) ;
							num_queue.pop() ;
						}
					}
					else {
						num_stack.push(num_queue.front()) ;
						num_queue.pop() ;
					}
				}
			}
		}
		if(possible == true) {
			printf("yes\n") ;
		}
		else
			printf("no\n") ;
	}
}