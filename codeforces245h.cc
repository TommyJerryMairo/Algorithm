#include <bits/stdc++.h>
#define REP(i, n) for (int i=0;i<int(n);++i)  
#define FOR(i, a, b) for (int i=int(a);i<int(b);++i)  
#define SZ(A) int(A.size())  

#ifdef bzero
#define BZERO(arr,sz) bzero(arr,sz)
#else
#define BZERO(arr,sz) memset(arr,0,sz)
#endif

using namespace std;

#define MAXL 5020
int dp[MAXL][MAXL]; 
bool palindrome[MAXL][MAXL];

int main(){
	std::ios::sync_with_stdio(false);
	cin.tie(NULL);
	// read input data
	string s; int n;
	cin >> s >> n;
	// dp process
	BZERO(dp,sizeof(dp)),BZERO(dp,sizeof(dp));
	FOR(i,1,SZ(s)+1) (dp[i][i]=1,palindrome[i][i]=1);
	FOR(k,2,SZ(s)+1)
		FOR(i,1,SZ(s)-k+2){
			int j=i+k-1;
			dp[i][j]+=dp[i+1][j]+dp[i][j-1]-dp[i+1][j-1];
			if(s[i-1]==s[j-1]&&(k==2||palindrome[i+1][j-1]))
				dp[i][j]++,palindrome[i][j]=true;
		}
	// read query and print result
	REP(T,n){
		int a,b; cin >> a >> b;
		cout << dp[a][b] << "\n";
	}
	return 0;
}
