#include<iostream>
using namespace std;

int board[10];
void addQueen(int n,int cur);
bool attack(int i,int cur);

int main() {
	addQueen(8,1);
	return 0;
}

void addQueen(int n,int cur) {
	if(cur>n) {
		for(int i=1; i<=n; i++) {
			cout<<board[i]<<" ";
		}
		cout<<endl;
		return;
	}
	for(int i=1; i<=n; i++) {
		if(!attack(i,cur)) {
			board[cur]=i;
			addQueen(n,cur+1);
		}
	}
}

bool attack(int i,int cur) {
	for(int j=1; j<cur; j++) {
		if(board[j]==i)return true;
		if(cur-j==i-board[j])return true;
		if(cur-j==board[j]-i)return true;
	}
	return false;
}
