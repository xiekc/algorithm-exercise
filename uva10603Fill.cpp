#include<iostream>
#include<queue>
using namespace std;

const int maxn=200+5;
int vis[maxn][maxn],cap[3],ans[maxn];

struct Node{
	int v[3],dist;
	bool operator < (const Node& t){
		return dist>t.dist;
	}
	Node(int a,int b,int c): v[0](a),v[1](b),v[2](c) {//v({a,b,c})
	}
};

void solve(int a,int b,int c,int d);
void initial();

int main(){
	int t,a,b,c,d;
	cin>>t;
	while(t--){
		cin>>a>>b>>c>>d;
		solve(a,b,c,d);
	}
	return 0;
}

void solve(int a,int b,int c,int d){
	initial();
	cap[0]=a;cap[1]=b;cap[2]=c;
	priority_queue<Node>q;
	q.push()
		
}

void initial(){
	memset(vis,0,sizeof(vis));
	memset(ans,-1,sizeof(ans));
}
