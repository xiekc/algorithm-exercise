#include<iostream>
#include<cstring>
using namespace std;

int vis[3][20];
int board[10];
int cnt,I,J;
void addQueen(int n,int cur);

int main() {
	int n=8,times;
	cin>>times;
	while(times--) {
		cnt=0;
		memset(vis,0,sizeof(vis));
		memset(board,0,sizeof(board));
		cin>>I>>J;
		board[J]=I;
		vis[0][I]=vis[1][I+J]=vis[2][J-I+n]=1;
		cout<<"SOLN       COLUMN\n #      1 2 3 4 5 6 7 8\n\n";
		addQueen(n,1);
		if(times)cout<<endl;
	}
	return 0;
}

void addQueen(int n,int cur) {
	if(cur>n) {
		if(++cnt<10)cout<<" ";
		cout<<cnt<<"      ";
		for(int i=1; i<n; i++) {
			cout<<board[i]<<" ";
		}
		cout<<board[n]<<endl;
		return;
	}
	if(cur==J) {
		addQueen(n,cur+1);
		return;
	}
	for(int i=1; i<=n; i++) {
		if(!vis[0][i]&&!vis[1][i+cur]&&!vis[2][cur-i+n]) {
			board[cur]=i;
			vis[0][i]=vis[1][i+cur]=vis[2][cur-i+n]=1;
			addQueen(n,cur+1);
			vis[0][i]=vis[1][i+cur]=vis[2][cur-i+n]=0;
		}
	}
}
