#include<iostream>
using namespace std;

void permutation(int cur,int*ans,int n);

int main() {
	int ans[11];
	int n=10;//from 0 to 9
	permutation(0,ans,n);
	return 0;
}

void permutation(int cur,int*ans,int n) {
	if(cur==n) {
		for(int i=0; i<n; i++)
			printf("%d",ans[i]);
		printf("\n");
	} else {
		for(int i=0; i<n; i++) {
			int ok=1;
			for(int j=0; j<cur; j++) {//the first element must be ok
				if(ans[j]==i) {
					ok=0;
					break;
				}
			}
			if(ok) {
				ans[cur]=i;
				permutation(cur+1,ans,n);
			}
		}
	}
}
