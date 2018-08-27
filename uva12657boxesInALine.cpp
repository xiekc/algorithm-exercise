#include<iostream>
using namespace std;

const int maxn = 100000 + 5;
int rig[maxn],lef[maxn];
int *rPtr,*lPtr,*t;

void link(int a,int b);
//void show(int n);

int main() {
	int n,times,ope,a,b,kase=1;
	int la,ra,lb,rb;
	while(cin>>n>>times) {
		long long sum=0;
		rPtr=rig;
		lPtr=lef;
		for(int i=0; i<n; i++) {
			link(i,i+1);
		}
		lPtr[0]=n;
		rPtr[n]=0;
		while(times--) {
			cin>>ope;
			if(ope!=4) {
				cin>>a>>b;
				la=lPtr[a];
				ra=rPtr[a];
				lb=lPtr[b];
				rb=rPtr[b];
			}
			switch(ope) {
				case 1:
					if(rPtr[a]!=b) {
						link(la,ra);
						link(lb,a);
						link(a,b);
					}
//					show(n);
					break;
				case 2:
					if(lPtr[a]!=b) {
						link(la,ra);
						link(a,rb);
						link(b,a);
					}
//					show(n);
					break;
				case 3:
					if(rPtr[a]==b) {
						link(la,b);
						link(b,a);
						link(a,rb);
					} else if(rPtr[b]==a) {
						link(lb,a);
						link(a,b);
						link(b,ra);
					} else {
						link(la,b);
						link(b,ra);
						link(lb,a);
						link(a,rb);
					}
//					show(n);
					break;
				case 4:
					t=lPtr;
					lPtr=rPtr;
					rPtr=t;
//					show(n);
					break;
			}
		}
		for(int i=rPtr[0],j=1; j<=n; i=rPtr[i],j++) {
			if((j%2)==1)sum+=i;
		}
		cout<<"Case "<<kase<<": "<<sum<<endl;
		kase++;
	}
	return 0;
}

void link(int a,int b) {
	rPtr[a]=b;
	lPtr[b]=a;
}
/*
void show(int n){
	for(int i=0;i<=n;i++){
		cout<<rPtr[i]<<"  ";
	}
	cout<<endl;
}*/
