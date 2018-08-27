#include<iostream>
#include<cstring>
using namespace std;

const int maxnd=20;
int node[1<<maxnd];

int main() {
	int times,d,n,cur;
	cin>>times;
	while(cin>>d&&d!=-1&&(times--)&&cin>>n) {
			cur=1;
		for(int i=0; i<d-1; i++) {
			if(n%2==1){
				cur=cur*2;
				n=(n+1)/2;
			}
			else {
				cur=cur*2+1;
				n=n/2;
			}
		}
		cout<<cur<<endl;
	}
	return 0;
}
