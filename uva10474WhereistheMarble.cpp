#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;

int main() {
	int mnum,qnum,que,num,ctr=0;
	vector<int> marble;
	vector<int>::iterator result;
	while(scanf("%d%d",&mnum,&qnum)==2&&(mnum||qnum)) {
		marble.clear();
		while(mnum--) {
			cin>>num;
			marble.push_back(num);
		}
		ctr++;
		sort(marble.begin(),marble.end());
		cout<<"CASE# "<<ctr<<':'<<endl;
		while(qnum--) {
			cin>>que;
			result=find(marble.begin(),marble.end(),que);
			if(*result==que)cout<<que<<" found at "<<result-marble.begin()+1<<endl;
			else cout<<que<<" not found"<<endl;
		}
	}
	return 0;
}
