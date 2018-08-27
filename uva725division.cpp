#include<cstdio>
using namespace std;

bool isUnique(int i);
bool isUnique(int a,int b);

int main() {
	int n,t,cnt;
	scanf("%d",&n);
	while(n) {
		cnt=0;
		for(int i=1234; i<100000; i++) {
			if(isUnique(i)) {
				t=i*n;
				if(t>=1234&&t<100000&&isUnique(i,t)){
					printf("%05d / %05d = %d\n",t,i,n);
					cnt++;
				}
			}
		}
		if(!cnt)printf("There are no solutions for %d.\n",n);
		if(scanf("%d",&n)&&n)printf("\n");
	}
	return 0;
}

bool isUnique(int n) {
	int t[11]= {0};
	while(n) {
		if(t[n%10])return false;
		t[n%10]=1;
		n/=10;
	}
	return true;
}

bool isUnique(int a,int b){
	int t[11]= {0};
	if(a<10000&&b<10000)return false;
	if(a<10000||b<10000)t[0]=1;
	while(a) {
		if(t[a%10])return false;
		t[a%10]=1;
		a/=10;
	}
	while(b) {
		if(t[b%10])return false;
		t[b%10]=1;
		b/=10;
	}
	return true;
}
