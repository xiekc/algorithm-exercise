#include<iostream>
#include<cstring>
using namespace std;

int b[10],cnt,I,J;
void addQueen(int n,int cur);

int main() {
	int n=8,times;
	cin>>times;
	while(times--) {
		cnt=0;
		memset(b,100,sizeof(b));//用'\100'初始化不用0,否则判断ok会失误
		cin>>I>>J;
		b[J]=I;
		cout<<"SOLN       COLUMN\n #      1 2 3 4 5 6 7 8\n\n";
		addQueen(n,1);
		if(times)cout<<endl;
	}
	return 0;
}

void addQueen(int n,int cur) {
	if(cur>n) {
		printf("%2d      ",++cnt);
		for(int i=1; i<n; i++) {
			cout<<b[i]<<" ";
		}
		cout<<b[n]<<endl;
		return;
	}
	if(cur==J) {
		addQueen(n,cur+1);
		return;
	}
	for(int i=1; i<=n; i++) {
		int ok=1;
		for(int j=1; j<=n; j++)//not j<cur
			if(i==b[j]||cur-i==j-b[j]||cur+i==j+b[j]) {
				ok=0;
				break;
			}
		if(ok) {
			b[cur]=i;
			addQueen(n,cur+1);
			b[cur]=100;
		}
	}
}
