#include<iostream>
#include<cstring>

using namespace std;



typedef int State[9];
const int maxn=1000000;
State st[maxn],goal;
int dis[maxn];

const int dx[]= {0,1,0,-1},dy[]= {1,0,-1,0};

void print(int n) {
	for(int i=0; i<9; i++) {

		cout<<st[n][i]<<" ";

		if((i+1)%3==0)cout<<endl;
	}
	cout<<memcmp(st[n],goal,sizeof(goal))<<endl;
}


void initish() {
	memset(st[1],0,sizeof(st)-sizeof(int)*9);//very important! wrong:memset(st[1],0,sizeof(st))it will cover goal!
	memset(dis,0,sizeof(dis));

}

bool insert(int r) {
	for(int i=0; i<r; i++) {
		if(memcmp(st[i],st[r],sizeof(st[r]))==0) {
			//	cout<<"false\n";
			return false;
		}
	}
//	cout<<"true"<<endl;
	return true;
}



int bfs() {
//	initish();
	dis[0]=0;

	int front=0,rear=1;
	int x,y,z;
	while(front<rear) {
		getchar();
		print(front);

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
			//x+=dx[i];  wrong! In the next three loops the x,y has been changed!
			//y+=dy[i];

			if(newx>=0&&newx<3&&newy>=0&&newy<3) {

				memcpy(st[rear],st[front],sizeof(st[front]));
				st[rear][z]=st[rear][newx+3*newy];
				st[rear][newx+3*newy]=0;



				if(insert(rear)) {
					dis[rear]=dis[front]+1;
					rear++;
				}

				if(memcmp(st[rear],goal,sizeof(goal))==0) {
					return rear;
				}
			}
		}

		front++;
	}

	return -1;
}


int main() {
	int t;
	cin>>t;
	while(t--) {


		for(int i=0; i<9; i++) {
			cin>>st[0][i];
		}


		for(int i=0; i<9; i++) {
			cin>>goal[i];
		}

		int re=bfs();
		if(re<0)cout<<re<<endl;
		else cout<<dis[re]<<endl;
		//cout<<(re>=0?dis[re]:-1)<<endl;
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
