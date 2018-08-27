#include<iostream>
using namespace std;

int n,L,cnt,s[1000];

int dfs(int cur);

int main() {
	while(cin>>n>>L&&n) {
		cnt=0;
		dfs(0);
	}
	return 0;
}

int dfs(int cur) {
	if(cnt++==n) {
		for(int i=0; i<cur; i++) {
			if(i&&i%64==0)cout<<endl;
			else if(i&&i%4==0)cout<<" ";
			printf("%c",'A'+s[i]);
		}
		if(n%64)cout<<endl;
		cout<<cur<<endl;
		return 0;
	}
	for(int i=0; i<L; i++) {
		s[cur]=i;
		int ok=1;
		for(int j=1; 2*j<=cur+1; j++) {
			int equal=1;
			for(int k=0; k<j; k++)
				if(s[cur-k]!=s[cur-k-j]) {
					equal=0;
					break;
				}
			if(equal) {
				ok=0;
				break;
			}
		}
		if(ok)if(!dfs(cur+1))return 0;
	}
	return 1;
}
