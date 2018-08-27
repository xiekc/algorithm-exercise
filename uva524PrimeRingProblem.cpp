#include<iostream>
#include<cmath>
using namespace std;
/*too slow*/
int ring[20];
int prime[40];

void solve(int n);
void dfs(int n,int cur,int k);
void isPrime();

int main() {
	int n,cnt=0;
	while(cin>>n) {
		if(cnt)printf("\n");
		printf("Case %d:\n",++cnt);
		solve(n);
	}
	return 0;
}

void solve(int n) {
	isPrime();
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
			int ok=1;
			for(int j=2; j<=cur; j++) {
				if(ring[j]==i) {
					ok=0;
					break;
				}
			}
			if(ok)dfs(n,cur+1,i);
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
