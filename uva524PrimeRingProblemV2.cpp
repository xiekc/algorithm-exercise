#include<iostream>
#include<cmath>
#include<cstring>
using namespace std;

int ring[20];
int prime[40];
int vis[20];

void solve(int n);
void dfs(int n,int cur,int k);
void isPrime();

int main() {
	int n,cnt=0;
	isPrime();
	while(cin>>n) {
		if(cnt)printf("\n");
		printf("Case %d:\n",++cnt);
		solve(n);
	}
	return 0;
}

void solve(int n) {
	memset(vis, 0, sizeof(vis));
	ring[1]=1;
	dfs(n,1,1);
}

void dfs(int n,int cur,int k) {
	if(cur>1&&!prime[ring[cur-1]+k])return;
	ring[cur]=k;
	if(cur==n&&prime[k+1]) {
		for(int i=1; i<n; i++)
			printf("%d ",ring[i]);
		printf("%d\n",ring[n]);
	} else for(int i=2; i<=n; i++) {
			if(!vis[i]) {
				vis[i]=1;
				dfs(n,cur+1,i);
				vis[i]=0;
			}
		}
}

void isPrime() {
	for(int i=2; i<35; i++) {
		int t=sqrt(i+0.5),ok=1;
		for(int k=2; k<=t; k++) {
			if(i%k==0) {
				prime[i]=0;
				ok=0;
				break;
			}
		}
		if(ok)prime[i]=1;
	}
}
