#include<bits/stdc++.h>
using namespace std;

const int maxn=1000+5;
void permutation(int cur,char*a,int n,char*ans,long long& result);
//too slow!
int main() {
	char a[maxn]= {0},ans[maxn]= {0};
	int times;
	long long result;
	scanf("%d",&times);
	while(times--) {
		scanf("%s %lld",a,&result);
		sort(a,a+strlen(a));
		permutation(0,a,strlen(a),ans,result);
	}
	return 0;
}

void permutation(int cur,char*a,int n,char*ans,long long& result) {
	if(cur==n) {
		if(result==0){
		for(int i=0; i<n; i++)
			printf("%c",ans[i]);
		printf("\n");
		}
		result--;
	} else {
		for(int i=0; i<n; i++) {
			if(!i||a[i]!=a[i-1]) {
				int cnta=0,cntans=0;
				for(int j=0; j<cur; j++)
					if(ans[j]==a[i])cntans++;
				for(int j=0; j<n; j++)
					if(a[j]==a[i])cnta++;
				if(cntans<cnta) {
					ans[cur]=a[i];
					permutation(cur+1,a,n,ans,result);
				}
			}
		}
	}
}
