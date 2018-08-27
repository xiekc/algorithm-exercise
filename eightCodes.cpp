#include<cstdio>
#include<cstring>
#include<queue>
using namespace std;

const int maxn=1000000,hashSize=1000000;
typedef int State[9];
State st[maxn],goal;
int dist[maxn];//or use struct to store st and dist
const int dx[]= {1,-1,0,0},dy[]= {0,0,1,-1}; //int still is the briefest way
int head[hashSize],next[maxn];


int bfs();
void initialHash();
int hashFunc();
int insertState(int s);

int main() {
	for(int i=0; i<9; i++)
		scanf("%d",&st[0][i]);
	for(int i=0; i<9; i++)
		scanf("%d",&goal[i]);

	printf("%d\n",bfs());

	return 0;
}

int bfs() {
	initialHash();
	int front=0,rear=1;
	while(front<rear) {
		State &s=st[front];
		if(memcmp(goal,s,sizeof(s))==0)return dist[front];

		int loc;
		for(loc=0; loc<9; loc++)
			if(s[loc]==0)break;

		int x=loc/3,y=loc%3;
		for(int i=0; i<4; i++) {
			int newx=x+dx[i],newy=y+dy[i];
			int newz=3*newx+newy;
			if(newx>=0&&newx<3&&newy>=0&&newy<3) {
				State &t=st[rear];
				memcpy(t,s,sizeof(s));
				t[newz]=s[loc];
				t[loc]=s[newz];
				dist[rear]=dist[front]+1;
				if(insertState(rear))rear++;
			}
		}
		front++;
	}
	return -1;
}

void initialHash() {
	memset(head,0,sizeof(head));
}

int hash(State&s) {
	int v=0;
	for(int i=0; i<9; i++) {
		v=s[i]+v*10;
	}
	return v%hashSize;
}

int insertState(int s) {
	int h=hash(st[s]);
	int u=head[h];
	while(u) {
		if(memcmp(st[u],st[s],sizeof(st[u]))==0)return 0;
		u=next[u];
	}
	next[s]=head[h];//s²åÈëheadºó
	head[h]=s;
	return 1;
}
