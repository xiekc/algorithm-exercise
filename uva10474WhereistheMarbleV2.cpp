#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;

const int maxn=10000;
int marble[maxn];

int main() {
	int mnum,qnum,que,num,ctr=0;
	int *result;
	while(scanf("%d%d",&mnum,&qnum)==2&&(mnum||qnum)) {
		for(int i=0;i<mnum;i++){
			cin>>num;
			marble[i]=num;
		}
		ctr++;
		sort(marble,marble+mnum);
		cout<<"CASE# "<<ctr<<':'<<endl;
		while(qnum--) {
			cin>>que;
			result=lower_bound(marble,marble+mnum,que);
			if(*result==que)cout<<que<<" found at "<<result-marble+1<<endl;
			else cout<<que<<" not found"<<endl;
		}
	}
	return 0;
}
