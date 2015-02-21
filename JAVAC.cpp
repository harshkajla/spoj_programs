#include <bits/stdc++.h>
using namespace std ;

string s ;

bool is_java() {
	if(s.find('_') != string :: npos)
		return false ;
	return true ;
}

bool is_c() {
	for(int i = 0 ; i < s.length() ; i++)
		if(s[i] >= 'A' && s[i] <= 'Z')
			return false ;
	return true ;
}

string convert() {
	if(s[0] >= 'A' && s[0] <= 'Z')
		return "Error!" ;
	if(is_java()) {
		vector <int> capitalizations ;
		for(int i = 0 ; i < s.length() ; i++)
			if(s[i] >= 'A' && s[i] <= 'Z')
				capitalizations.push_back(i) ;
		if(capitalizations.size() == 0)
			return s ;
		capitalizations.push_back(s.length()) ;
		string res = "" ;
		res = res + s.substr(0 , capitalizations[0]) ;
		for(int i = 1 ; i <= capitalizations.size() - 1 ; i++) {
			string tmp = s.substr(capitalizations[i - 1] , capitalizations[i] - capitalizations[i - 1]) ;
			tmp = tmp.substr(1) ;
			tmp = (char)(s[capitalizations[i - 1]] - 'A' + 'a') + tmp ;
			res = res + '_' + tmp ;
		}
		return res ;
	}
	else if(is_c()) {
		vector <int> underscores ;
		for(int i = 0 ; i < s.length() ; i++)
			if(s[i] == '_')
				underscores.push_back(i) ;
		if(underscores.size() == 0)
			return s ;
		for(int i = 0 ; i < underscores.size() - 1 ; i++) {
			if(underscores[i] == underscores[i + 1] - 1)
				return "Error!" ;
		}
		if(underscores[0] == 0 || underscores[underscores.size() - 1] == s.length() - 1)
			return "Error!" ;
		underscores.push_back(s.length()) ;
		string res = "" ;
		res = res + s.substr(0 , underscores[0]) ;
		for(int i = 1 ; i < underscores.size() ; i++) {
			string tmp = s.substr(underscores[i - 1] + 1 , underscores[i] - underscores[i - 1] - 1) ;
			tmp = tmp.substr(1) ;
			tmp = (char)(s[underscores[i - 1] + 1] - 'a' + 'A') + tmp ;
			res = res + tmp ;
		}
		return res ;
	}
	else
		return "Error!" ;
}

int main() {
	while(cin >> s) {
		cout << convert() << endl ;
	}
}