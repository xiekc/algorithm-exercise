#include<cstdio>
using namespace std;

int main() {
	int n,kase=1;
	long long ans,pro;
	while(scanf("%d",&n)==1) {
		int a[20]= {0};
		ans=-1;
		for(int i=0; i<n; i++) {
			scanf("%d",&a[i]);
		}
		for(int start=0; start<n; start++) {
			for(int end=start; end<n; end++) {
				pro=(a[start]!=0)?1:0;
				for(int i=start; i<=end; i++) {
					pro*=a[i];
				}
				if(ans<pro)ans=pro;
			}
		}
		printf("Case #%d: The maximum product is %lld.\n\n",
		       kase++,ans>0?ans:0);
	}
	return 0;
}
