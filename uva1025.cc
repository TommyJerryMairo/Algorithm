#include <bits/stdc++.h>
using namespace std;
#define FOR(i, a, b) for (int i=int(a);i<int(b);++i)  
#define DWN(i, b, a) for (int i=int(b-1);i>=int(a);--i) 

#define MAXN 64
#define MAXT 256
#define MAX_VAL 127

unsigned int N;
unsigned int T;
unsigned int t[MAXN];
unsigned int M1;
unsigned int d[MAXN];
unsigned int M2;
unsigned int e[MAXN];

inline void printInput() {
	static unsigned int casenum = 1;
	cout << "Case Number " << casenum++ << ": " << endl;
	cout << "N: " << N << endl;
	cout << "T: " << T << endl;
	cout << "t: ";
	FOR(i,1,N)
		cout << t[i] << " ";
	cout << endl;
	cout << "M1: " << M1 << endl;
	cout << "d: ";
	FOR(i,1,M1+1)
		cout << d[i] << " ";
	cout << endl;
	cout << "M2: " << M2 << endl;
	cout << "e: ";
	FOR(i,1,M2+1)
		cout << e[i] << " ";
	cout << endl;
}

int main() {
	ios_base::sync_with_stdio(false);
	static unsigned int casenum = 1;
	while(cin>>N,N>0){
		// Read input data
		cin >> T;
		FOR(i,1,N)
			cin >> t[i];
		cin >> M1;
		FOR(i,1,M1+1)
			cin >> d[i];
		cin >> M2;
		FOR(i,1,M2+1)
			cin >> e[i];
		//printInput();
		//Init array has train
#define TORIGHT 0
#define TOLEFT 1
		bool has_train[MAXT][MAXN][2]; // Time, Station, Direction
		memset(has_train,0,sizeof(has_train));
		// First station to last
		FOR(i,1,M1+1){
			int dn = d[i];
			FOR(j,1,N){
				if(dn<=T) has_train[dn][j][TORIGHT] = true;
				dn += t[j];
			}
		}
		// Last station to first
		FOR(i,1,M2+1){
			int en = e[i];
			DWN(j,N,1){
				if(en<=T) has_train[en][j+1][TOLEFT] = true;
				en += t[j];
			}
		}
		//DP body
		unsigned int dp[MAXT][MAXN]; memset(dp,MAX_VAL,sizeof(dp));
		dp[T][N] = 0;
		DWN(i,T,0) // i is for timestamp
			FOR(j,1,N+1){ // j is for station
				dp[i][j] = dp[i+1][j] + 1;
				if(j<N&&has_train[i][j][TORIGHT]&&i+t[j]<=T)
					dp[i][j] = min(dp[i][j],dp[i+t[j]][j+1]); // Go right
				if(j>1&&has_train[i][j][TOLEFT]&&i+t[j-1]<=T)
					dp[i][j] = min(dp[i][j],dp[i+t[j-1]][j-1]); // Go left
			}
		//Output result
		cout << "Case Number " << casenum++ <<": " << ((dp[0][1]>T)?"impossible":to_string(dp[0][1])) << '\n';
	}
	return 0;
}
