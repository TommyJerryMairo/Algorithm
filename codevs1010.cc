#include<cstdio>
#include<cstring>
using namespace std;
struct Place{
	short int x,y;
	}A,B,C,team[16777216],next;
int dx[11]={-2,-2,-1,1,2,2,1,-1,0,-2,1};
int dy[11]={-1,1,2,2,1,-1,-2,-2,0,-2,1};
int nx[2]={1,0};
int ny[2]={0,1};
int sum=0,tmp;
unsigned short head_level=0,tail_level=0;
bool place_same(Place a,Place b){
	bool rst=true;
	if(a.x!=b.x)rst=false;
	if(a.y!=b.y)rst=false;
	return rst;
}
bool avaliable(Place here){
	bool rst=true;
	if(here.x>B.x)rst=false;
	if(here.y>B.y)rst=false;
//	printf("%d\n",rst);
	for(int i=0;i<11;i++){
		if((here.x==(C.x+dx[i]))&&(here.y==(C.y+dy[i])))rst=false;
//		printf("(%d,%d),(%d,%d),%d\n",here.x,here.y,C.x+dx[i],C.y+dy[i],rst);
	}
	return rst;
}
void bfs(Place start){
	memset(team,0,sizeof(team));
	int head=0;
	int tail=1;
	team[tail].x=start.x;
	team[tail].y=start.y;
	while(head_level<=tail_level){
		if(head_level==tail_level)
			if(head>=tail)
				break;
		head++;
		tmp=(head&16777215);
		if(tmp<head)head_level++;
		head=tmp;
		if(place_same(team[head],B)){
			sum++;
		}
//		printf("(%d,%d)\n",team[head].x,team[head].y);
		int now=tail;
		for(int i=0;i<2;i++){
			next.x=team[head].x+nx[i];
			next.y=team[head].y+ny[i];
//			printf("Finding (%d,%d)\n",next.x,next.y);
			if(avaliable(next)){
				tail++;
				tmp=(tail&16777215);
				if(tmp<tail)tail_level++;
				tail=tmp;;
				team[tail].x=next.x;
				team[tail].y=next.y;
//			printf("(%d,%d)is avaliable.\n",team[tail].x,team[tail].y);
//			printf("head=%d of %lld tail=%d of %lld\n",head,head_level,tail,tail_level);
			}
		}
	}
//	printf("End bfs.\n");
	return ;
}
int main(){
	A.x=0;
	A.y=0;
	scanf("%hd %hd %hd %hd",&B.x,&B.y,&C.x,&C.y);
//	printf("%d %d %d %d \n",B.x,B.y,C.x,C.y);
	bfs(A);
	printf("%d",sum);
	return 0;
}
