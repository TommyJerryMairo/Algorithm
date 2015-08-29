#include<cstdio>
#include<cstring>
using namespace std;
struct Place {
	short x,y;
}A,B,C,team[65536];
bool avaliable[16][16];
int step[16][16];
short dx[9]={-1,-2,-2,-1,1,2,2,1,0};
short dy[9]={-2,-1,1,2,2,1,-1,-2,0};
short nx[2]={1,0};
short ny[2]={0,1};
int main(){
	memset(avaliable,-1,sizeof(avaliable));
	memset(step,0,sizeof(step));
	memset(team,0,sizeof(team));
	scanf("%d%d%d%d",&B.x,&B.y,&C.x,&C.y);
//	printf("%hd %hd %hd %hd\n",B.x,B.y,C.x,C.y);
	A.x=0; A.y=0;
	for(short i=0;i<9;i++)avaliable[C.x+dx[i]][C.y+dy[i]]=0;
	unsigned short head=0,tail=1;
	step[0][0]=1;
	team[1].x=0; team[1].y=0;
	while(head<tail){
		head++;
		for(short i=0;i<2;i++)
			if(0<=(team[head].x+nx[i])&&(team[head].x+nx[i])<=15&&0<=(team[head].y+ny[i])&&(team[head].y+ny[i])<=15){
					step[team[head].x+nx[i]][team[head].y+ny[i]]+=step[team[head].x][team[head].y];
					if(avaliable[team[head].x+nx[i]][team[head].y+ny[i]]){
						tail++;
						avaliable[team[head].x+nx[i]][team[head].y+ny[i]]=0;
						team[tail].x=team[head].x+nx[i];
						team[tail].y=team[head].y+ny[i];
					}
				}
	}
	printf("%d\n",step[B.x][B.y]);
	return 0;
}
