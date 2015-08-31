#include<cstdio>
#include<cstring>
using namespace std;
int map[60][60],m,n,max[60][60];
int fx[2]={1,0};
int fy[2]={0,1};
int bx[2]={-1,0};
int by[2]={0,-1};
int dp(int x,int y,bool back){
	int tmp=0;
	if(max[x][y]!=-1)return max[x][y];
	if(x==m&&y==n)back=1;
	if(back){
		for(int i=0;i<2;i++){
			if((x+bx[i]<1)||(y+by[i]<1))continue;
			if(max[x+bx[i]][y+by[i]]!=-1)continue;
			if(max[x][y]+dp(x+bx[i],y+by[i],1)>tmp)
				tmp=dp(x+bx[i],y+by[i],1)+max[x][y];
		}
		max[x][y]=tmp;
	}
	else{
		for(int i=0;i<2;i++){
			if((x+fx[i]>m)||(y+fy[i]>n))continue;
			if(dp(x+fx[i],y+fy[i],0)+max[x][y]>tmp)
				tmp=dp(x+fx[i],y+fy[i],0)+max[x][y];
		}
		max[x][y]=tmp;
	}
	return max[x][y];
}
int main(){
	memset(map,0,sizeof(map));
	memset(max,-1,sizeof(max));
	scanf("%d%d",&m,&n);
	for(int i=1;i<=m;i++)
		for(int j=1;j<=n;j++) scanf("%d",&map[i][j]);
/*	printf("%d %d\n",m,n);
	for(int i=1;i<=m;i++){
		for(int j=1;j<=m;j++) printf("%d ",map[i][j]);
		printf("\n");
	}*/
	max[1][1]=0;
	for(int i=0;i<2;i++)
		if(dp(1+fx[i],1+fy[i],0)>max[1][1])
			max[1][1]=dp(1+fx[i],1+fy[i],0);
	printf("%d\n",max[1][1]);
	return 0;
}
