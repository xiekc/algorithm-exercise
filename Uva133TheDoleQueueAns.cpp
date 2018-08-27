#include<iostream>
using namespace std;

#define maxn 25
int loop[maxn];
int n,k,m,t;

int go(int p,int d,int t) {
	while(t--) {
		do {
			p=(p+d-1+n)%n+1;
		} while(loop[p]==0);
	}
	return p;
}

int main() {
	int left;
	while(scanf("%d%d%d",&n,&k,&m)==3&&n) {
		for(int i=1; i<=n; i++) {
			loop[i]=i;
		}
		int startk=n;
		int startm=1;
		left=n;
		while(left--) {//==for(int i=n;i>0;i--) 
			startk=go(startk,1,k);
			startm=go(startm,-1,m);
			printf("%3d",startk);
			if(startm!=startk) {
				printf("%3d",startm);
				left--;
			}
			loop[startk]=loop[startm]=0;
			if(left)printf(",");
		}
		printf("\n");
	}
	return 0;
}
