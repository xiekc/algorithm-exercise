#include<iostream>
#include<cstring>
#include<map>
#include<queue>
#include<stack>
using namespace std;
/*have used char to present direction, but difficult*/
/*distinguish dir and turn*/
/*unfinished*/
struct Node {
	int r, c, dir; // 站在(r,c)，面朝方向dir(0~3分别表示N, E, S, W)
	Node(int r=0, int c=0, int dir=0):r(r),c(c),dir(dir) {}
};
const int maxn=100+5;
int edge[maxn][maxn][4][3],d[maxn][maxn][4];
Node pre[maxn][maxn][4];
int startr,startc,endr,endc,r1,c1,dire;
map<char,int>dir,tr;
int dr[]= {-1,0,1,0},dc[]= {0,1,0,-1};

void initialize();
void solve();
bool readIn();
bool isInside(const Node& t);
Node walk(const Node&u,int turn);
void printAns(Node a);

int main() {
//	freopen("uva816.in","r",stdin);
//	freopen("uva816.out","w",stdout);
	initialize();
	while(readIn()) {
		solve();
	}
	return 0;
}

bool readIn() {
	char s[100],s2[5];
	if(scanf("%s%d%d%s%d%d",s,&startr,&startc,s2,&endr,&endc) != 6) return false;
	cout<<s<<endl;

	dire =dir[s2[0]];
	r1 =startr+dr[dire];
	c1 =startc+dc[dire];
	memset(edge, 0, sizeof(edge));
	while(1) {
		int r,c;
		cin>>r;
		if(r==0)break;
		cin>>c;
		while(cin>>s&&s[0]!='*') {
			for(int i=1; i<strlen(s); i++)
				edge[r][c][dir[s[0]]][tr[s[i]]]=1;
		}
	}
	return true;
}

void solve() {
	queue<Node>q;
	memset(d,-1,sizeof(d));
	Node n(r1,c1,dire);
	d[n.r][n.c][n.dir]=0;
	q.push(n);
	while(!q.empty()) {
		Node t=q.front();
		q.pop();
		if(t.r==endr&&t.c==endc) {
			printAns(t);
			return;
		}
		for(int i=0; i<3; i++) {
			Node w=walk(t,i);
			if(isInside(w)&&edge[t.r][t.c][t.dir][i]&&d[w.r][w.c][w.dir]<0) {
				d[w.r][w.c][w.dir]=d[t.r][t.c][t.dir]+1;
				pre[w.r][w.c][w.dir]=t;
				q.push(w);
			}
		}
	}
	cout<<"No Solution Possible\n";
}

void initialize() {
	dir['N']=0;
	dir['E']=1;
	dir['S']=2;
	dir['W']=3;
	tr['F']=0;
	tr['L']=1;
	tr['R']=2;
}

bool isInside(const Node& t) {
	if(t.r>0&&t.r<=9&&t.c>0&&t.c<=9)
		return true;
	else return false;
}

Node walk(const Node&u,int turn) {
	int dir=u.dir;
	if(turn==1)dir=(dir+3)%4;
	else if(turn==2)dir=(dir+1)%4;
	return Node(u.r+dr[turn],u.c+dc[turn],dir);
}

void printAns(Node a) {
	stack<Node> sn;
	sn.push(a);
	Node t=pre[a.r][a.c][a.dir];
	while(t.r!=r1&&t.c!=c1) {
		sn.push(t);
		t=pre[t.r][t.c][t.dir];
	}
	int cnt;
	for(cnt=0; !sn.empty(); cnt++) {
		t=sn.top();
		sn.pop();
		cout<<"("<<t.r<<","<<t.c<<")\n";
		if(cnt%10!=0)cout<<" ";
		else cout<<endl;
	}
	if(cnt%10!=0)cout<<endl;
}
