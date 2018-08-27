#include<iostream>
using namespace std;

#define maxn 25
int loop[maxn];
int startk,startm;

bool isEmpty(int n) {
	for(int i=1; i<=n; i++) {
		if(loop[i])
			return false;
	}
	return true;
}

int getnum(int n,int start,int apart,int mark) {
	if(!isEmpty(n)) {
		int i=start;
		if(mark) {
			while(!loop[i]) i=(i+n-1)%n+1;
			i=start+apart-1;//wrong thought!\
			can not promise each element \
			between start and start+apart\
			is not 0!
			while(1) {
				i=(i+n)%n;
				if(loop[i]) {//序号和下标不可混
					loop[i]=0;
					startk=i+1;
					return i;
				} else i++;
			}
		} else {
			while (!loop[i-1]) i=(i+n-1)%n+1;
			i=start-apart+1;
			while(1) {
				i=(i+n)%n;
				if(loop[i]) {
					loop[i]=0;
					startm=i-1;
					return i;
				} else i--;
			}
		}
	} else return 0;
}

int main() {
	int n,k,m,t;
	while(scanf("%d%d%d",&n,&k,&m)==3&&(n||k||m)) {
		startk=1;
		startm=n;
		for(int i=1; i<=n; i++) {
			loop[i]=i;
		}
		while(!isEmpty(n)) {
			if(t=getnum(n,startk,k,1))printf("%3d",t);
			else printf("\n");//每一轮非分步出局
			if(t=getnum(n,startm,m,0))printf("%3d,",t);
			else printf("\n");
		}
	}
	return 0;
}
