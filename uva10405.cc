#include <iostream>
#include <algorithm>
#include <string>
#include <cstring>

using namespace std;

#define MAXLEN 1024

long long soln[MAXLEN][MAXLEN];
long long LLCS(const string & str0, const string & str1);

int main(){
	ios_base::sync_with_stdio(false);
	string str0, str1;
	getline(cin,str0);
	getline(cin,str1);
	while(!cin.eof()){
		/** Test input 
		* cout << str0 << endl;
		* cout << str1 << endl;
		**/
		cout << LLCS(str0,str1) << endl;
		getline(cin,str0);
		getline(cin,str1);
	}
	return 0;
}

long long LLCS_helper(const string & str0, const string & str1, ssize_t n, ssize_t m) {
	if (-1 == soln[n][m]) 
		soln[n][m] = 
			(n==0||m==0)?0:
			(str0[n-1]==str1[m-1])?LLCS_helper(str0,str1,n-1,m-1)+1:
			max(LLCS_helper(str0,str1,n-1,m),LLCS_helper(str0,str1,n,m-1));
	return soln[n][m];
}

long long LLCS(const string & str0, const string & str1) {
	memset(soln,-1,sizeof(soln));
	return LLCS_helper(str0,str1,str0.length(),str1.length());
}
