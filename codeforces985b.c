#include<stdio.h>
#include<string.h>
#include<stdbool.h>

#define N 2048
#define FOR(i, a, b) for(int i=a;i<b;i++)

int main(){
	int n,m;
	scanf("%d %d\n",&n,&m);
	char map[n][m];
	int cnt[m];
	memset(cnt,0,sizeof(cnt));
	FOR(i,0,n){
		FOR(j,0,m){
			scanf("%c",&map[i][j]);
			if('1'==map[i][j])
				cnt[j]++;
		}
		scanf("\n");
	}
	/*
	FOR(i,0,n){
		FOR(j,0,m){
			printf("%c",map[i][j]);
		}
		printf("\n");
	}
	*/
	FOR(i,0,n){
		bool trunc = true;
		FOR(j,0,m){
			if('1'==map[i][j]&&1==cnt[j]){
				trunc = false;
				break;
			}
		}
		if(trunc){
			printf("YES\n");
			return 0;
		}
	}
	printf("NO\n");
	return 0;
}
