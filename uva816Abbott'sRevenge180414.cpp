#include<cstdio>
#include<cstring>
#include<iostream>
#include<queue>
#include<string>

using namespace std;

#define MAXN 10



class Node {
	public:
		int x;
		int y;
		int d;

		Node()=default;

		Node(int x,int y,int d):x(x),y(y),d(d) {
		}
};

int has_edge[MAXN][MAXN][4][3];
const string dirs("NESW");
const string turns("FLR");
const int dx[]= {-1,0,1,0},dy[]= {0,1,0,-1};


int startx,starty,startd,endx,endy;


int dis[MAXN][MAXN][4];
Node par[MAXN][MAXN][4];

void printAns(Node u);


int dir(char c) {
	return dirs.find_first_of(c);
}

int turn(char c) {
	return turns.find_first_of(c);
}


bool readin() {
	memset(has_edge,0,sizeof(has_edge));

	string name;
	cin>>name;
	if(name=="END")return false;
	else cout<<name<<endl;

	char d;
	cin>>startx>>starty>>d>>endx>>endy;
	startd=dir(d);

	startx+=dx[startd];
	starty+=dy[startd];

	int x,y;
	string s;
	while(cin>>x&&x!=0) {
		cin>>y;
		while(cin>>s&&s[0]!='*') {

			for(int j=1; j<s.length(); j++) {
				has_edge[x][y][dir(s[0])][turn(s[j])]=1;
			}
		}
	}

	return true;
}


Node walk(const Node &u,int t) {
	int d=u.d;

	if(t==1)d=(d+3)%4;
	if(t==2)d=(d+1)%4;

	return Node(u.x+dx[d],u.y+dy[d],d);
}


void solve() {
	memset(dis,-1,sizeof(dis));

	queue<Node>q;
	Node u(startx,starty,startd);
	q.push(u);
	dis[u.x][u.y][u.d]=0;

	while(!q.empty()) {
		Node u=q.front();
		q.pop();

//		cout<<"pop\n";

		if(u.x==endx&&u.y==endy) {
			printAns(u);
			return;
		}

		for(int i=0; i<3; i++) {
			Node v=walk(u,i);

			if(has_edge[u.x][u.y][u.d][i]&&dis[v.x][v.y][v.d]<0) {
				par[v.x][v.y][v.d]=u;
				dis[v.x][v.y][v.d]=dis[u.x][u.y][u.d]+1;

				q.push(v);
			}
		}

	}

	cout<<"  No Solution Possible\n";
}


void printAns(Node u) {
	vector<Node> nodes;
	
	while(dis[u.x][u.y][u.d]!=0){
		nodes.push_back(u);
		
		u=par[u.x][u.y][u.d];
	}
	
	nodes.push_back(u);
	nodes.push_back(Node(startx-dx[startd],starty-dy[startd],startd));
	
	int cnt;
	for(int i=nodes.size()-1,cnt=0;i>=0;i--,cnt++){
		if(cnt%10==0)cout<<" ";//there are two spaces before the top of every row 
		cout<<" ("<<nodes[i].x<<","<<nodes[i].y<<")";
		if((cnt+1)%10==0)cout<<endl;
	}
	
	if((nodes.size())%10!=0)cout<<endl;
}


/*
void test(){
	for(int i=0;i<MAXN;i++){
		for(int j=0;j<MAXN;j++){
			for(int k=0;k<4;k++){
				cout<<has_edge[i][j][k][0]<<" "<<has_edge[i][j][k][1]<<
				" "<<has_edge[i][j][k][2]<<endl;
			}
			cout<<endl;
		}
		cout<<endl;
	}
	
}

*/


int main() {
	while(readin()){
		solve();
	}
	
	return 0;
}
