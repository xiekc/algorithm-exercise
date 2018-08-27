#include<iostream>
#include<string>
#include<sstream>
using namespace std;

const int maxn=10000+5;
int inorder[maxn],postorder[maxn],r[maxn],l[maxn];
const int root=1;//0 for NULL
int n,minL,minCost;

bool readIn(int*a);
int build(int inb,int ine,int postb,int poste);
void dfs(int u,int sum);

int main() {
	freopen("uva548.in","r",stdin);
	freopen("uva548.out","w",stdout);
	while(readIn(inorder)) {
		readIn(postorder);
		build(0,n-1,0,n-1);
		minCost=100000000;
		dfs(postorder[n-1],0);
		cout<<minL<<endl;
	}
	return 0;
}

bool readIn(int*a) {
	string line;
	if(!getline(cin,line))return false;
	stringstream ss(line);//´úÌæsscanf¡¢sprintf
	n=0;
	int x;
	while(ss>>x)a[n++]=x;
	return n>0;
}

int build(int inb,int ine,int postb,int poste) {
	if(inb>ine)return 0;
	int root=postorder[poste];
	int t=inb;
	while(inorder[t++]!=root);
	int cnt=--t-inb;
	l[root]=build(inb,t-1,postb,postb+cnt-1);
	r[root]=build(t+1,ine,postb+cnt,poste-1);
	return root;
}

void dfs(int u,int sum) {
	sum+=u;
	if(r[u]==0&&l[u]==0) {
		if(sum<minCost||(sum==minCost&&u<minL)) {
			minCost=sum;
			minL=u;
		}
	}
	if(l[u])dfs(l[u],sum);
	if(r[u])dfs(r[u],sum);
}
