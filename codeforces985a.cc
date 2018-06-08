#include<iostream>
#include<algorithm>

using namespace std;

#define MAX_N 128

int main(){
	ios::sync_with_stdio(false);
	int n;
	cin >> n;
	int p[MAX_N] = {0};
	for(int i=1;i<=(n>>1);i++)
		cin >> p[i];
	sort(p+1,p+1+(n>>1));
	int odd = 0;
	int even = 0;
	for(int i=1;i<=(n>>1);i++){
		odd += abs(p[i] - ((i<<1)-1));
		even += abs(p[i] - (i<<1));
	}
	cout << min(odd,even) << endl;
	return 0;
}
