#include<iostream>
#include<cstring>

using namespace std;



typedef int State[9];
const int maxn=1000000;
State st[maxn],goal;
int dis[maxn],par[maxn];
int vis[maxn],fact[11];

const int dx[]= {0,1,0,-1},dy[]= {1,0,-1,0};

void print(int n) {
	for(int i=0; i<9; i++) {

		cout<<st[n][i]<<" ";

		if((i+1)%3==0)cout<<endl;
	}
	
	cout<<endl;
//	cout<<memcmp(st[n],goal,sizeof(goal))<<endl;
}



void printAns(int r){
	int stack[110],i;
	
	for(i=0;i<110&&r>0;i++){
		stack[i]=r;
		r=par[r];
	}
	
	print(0);
	
	i--;
	while(i>=0){
		print(stack[i]);
		i--;
	}
}


void initish() {
	fact[0]=1;
	for(int i=1; i<10; i++) {
		fact[i]=fact[i-1]*i;
	}

	memset(vis,0,sizeof(vis));

}

bool insert(int r) {
	int code=0,cnt;

	for(int i=0; i<9; i++) {
		cnt=0;
		for(int j=i+1; j<9; j++) {
			if(st[r][j]<st[r][i])cnt++;
		}
		code+=fact[8-i]*cnt;
	}

	if(vis[code]==1)return false;
	vis[code]=1;
	return true;
}



int bfs() {
	initish();
	dis[0]=0;

	int front=0,rear=1;
	int x,y,z;
//	int pre=0;
	while(front<rear) {
//		getchar();
//		print(front);

		/**
				for(int i=0; i<9; i++) {

					cout<<goal[i]<<" ";

					if((i+1)%3==0)cout<<endl;
				}
		/**/

		if(memcmp(st[front],goal,sizeof(goal))==0) {
			return front;
		}


		for(z=0; z<9; z++) {
			if(st[front][z]==0)break;
		}

		x=z%3;
		y=z/3;

		for(int i=0; i<4; i++) {
			int newx=x+dx[i],newy=y+dy[i];
			if(newx>=0&&newx<3&&newy>=0&&newy<3) {

				memcpy(st[rear],st[front],sizeof(st[front]));
				st[rear][z]=st[rear][newx+3*newy];
				st[rear][newx+3*newy]=0;



				if(insert(rear)) {
					dis[rear]=dis[front]+1;
		/*			
					if(dis[rear]>pre){
						pre=dis[rear];
						cout<<pre<<endl;
					}
		*/			
					par[rear]=front;
					rear++;
				}

				if(memcmp(st[rear-1],goal,sizeof(goal))==0) {
					return rear-1;
				}
			}
		}

		front++;
	}

	return -1;
}


int main() {



	for(int i=0; i<9; i++) {
		cin>>st[0][i];
	}


	for(int i=0; i<9; i++) {
		cin>>goal[i];
	}

	int re=bfs();
	if(re<0)cout<<"It needs "<<re<<endl;
	else cout<<dis[re]<<" steps to arrive."<<endl;
	//cout<<(re>=0?dis[re]:-1)<<endl;

	if(re>=0){
		printAns(re);
	}

	return 0;


}


/*case
2 6 4 1 3 7 0 5 8
8 1 5 7 3 6 4 0 2


2 6 4 1 3 7 0 5 8
0 6 4 2 1 8 5 7 3


2 6 4 1 3 7 0 5 8
2 6 4 1 7 8 5 3 0
*/
