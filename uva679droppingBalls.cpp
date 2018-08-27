#include<iostream>
#include<cstring>
using namespace std;

const int maxnd=20;
int node[1<<maxnd];

int main() {
	int times,d,n,cur;
	cin>>times;
	while((times--)&&cin>>d&&d!=-1&&cin>>n) {
		memset(node,0,sizeof(node));
		for(int i=0; i<n; i++) {
			cur=1;
			for(int j=1; j<d; j++) {
				if(node[cur]) {
					node[cur]=0;
					cur=2*cur+1;
				} 
				else {
					node[cur]=1;
					cur=2*cur;
				}
			}
		}
		cout<<cur<<endl;
	}
	return 0;
}
