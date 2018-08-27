#include<iostream>
#include<stack>
using namespace std;

int result[1005]= {0};

int main() {
	int n,num;
	while(cin>>n&&n) {
		while(cin>>num&&num) {
			int j,pos;
			stack<int>train;
			result[0]=num;
			for(int i=1; i<n; i++) {
				cin>>num;
				result[i]=num;
			}
			for(j=1,pos=0; j<=n&&pos<n; j++) {
				train.push(j);
				while(!train.empty()&&train.top()==result[pos]) {
					train.pop();
					pos++;
				}
			}
			if(pos>=n) cout<<"Yes\n";
			else cout<<"No\n";
		}
		cout<<endl;
	}
	return 0;
}
