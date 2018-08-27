#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;

const int maxn=1000+5;
void permutation(int cur,char*a,int n,char*ans);

int main() {
	char a[maxn]={0},ans[maxn]={0};
	scanf("%s",a);
	sort(a,a+strlen(a));
	permutation(0,a,strlen(a),ans);
	return 0;
}

void permutation(int cur,char*a,int n,char*ans) {
	if(cur==n) {
		for(int i=0; i<n; i++)
			printf("%c",ans[i]);
		printf("\n");
	} else {
		for(int i=0; i<n; i++) {
			if(!i||a[i]!=a[i-1]) {
				int cnta=0,cntans=0;
				for(int j=0; j<cur; j++)//the first element must be ok
					if(ans[j]==a[i])cntans++;
				for(int j=0; j<n; j++)//the first element must be ok
					if(a[j]==a[i])cnta++;
				if(cntans<cnta) {
					ans[cur]=a[i];
					permutation(cur+1,a,n,ans);
				}
			}
		}
	}
}
