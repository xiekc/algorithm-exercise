#include<iostream>
using namespace std;

bool fail;

int isBalanced();

int main() {
	freopen("uva839.in","r",stdin);
	freopen("uva839.out","w",stdout);
	
	int t;
	cin>>t;
	while(t--) {
		fail=false;
		isBalanced();
		if(fail)cout<<"NO\n";
		else cout<<"YES\n";
		if(t)cout<<endl;
	}
	return 0;
}

int isBalanced() {
	int wl,dl,wr,dr;
	cin>>wl>>dl>>wr>>dr;
	wl=(wl)?wl:isBalanced();
	wr=(wr)?wr:isBalanced();
	if(wl*dl!=wr*dr)fail=true;
	return wl+wr;
}
