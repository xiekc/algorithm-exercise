#include<cstdio>
using namespace std;

const int maxn=1000+5;
int ans[maxn][2];

int main() {
	int n,cnt;
	while(scanf("%d",&n)==1) {
		cnt=0;
		for(int i=n+1; i<=2*n; i++) {
			if(i*n%(i-n)==0) {
				ans[cnt][0]=i*n/(i-n);
				ans[cnt][1]=i;
				cnt++;
			}
		}
		printf("%d\n",cnt);
		for(int i=0; i<cnt; i++)
			printf("1/%d = 1/%d + 1/%d\n",n,ans[i][0],ans[i][1]);
	}
	return 0;
}
