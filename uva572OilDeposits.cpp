#include<iostream>
#include<cstring>
using namespace std;

const int maxn=1000+5;
char graph[maxn][maxn];
int r,c,idx[maxn][maxn],cnt;//index has been used!

void dfs(int i,int j,int id) {
	if(i<0||j<0||i>=r||j>=c)return;
	if(idx[i][j]||graph[i][j]=='*')return;
	idx[i][j]=id;
	for(int m=-1; m<2; m++)
		for(int n=-1; n<2; n++)
			if(m!=0||n!=0)dfs(i+m,j+n,id);
}

int main() {
	while(cin>>r>>c&&r&&c) {
		memset(idx,0,sizeof(idx));
		for(int i=0; i<r; i++)
			cin>>graph[i];
		cnt=0;
		for(int i=0; i<r; i++)
			for(int j=0; j<c; j++) {
				if(graph[i][j]=='@'&&!idx[i][j])
					dfs(i,j,++cnt);
			}
		cout<<cnt<<endl;
	}
	return 0;
}
