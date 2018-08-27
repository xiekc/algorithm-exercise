#include<iostream>
#include<queue>
#include<set>
using namespace std;

typedef long long LL;
const int coff[3]={2,3,5};

int main(){
	priority_queue<LL,vector<LL>,greater<LL> >pq;
	set<LL>s;
	pq.push(1);
	s.insert(1);
	LL x;
	for(int i=0;i<1500;i++){
		x=pq.top();
		pq.pop();
		for(int j=0;j<3;j++){
			LL x2=x*coff[j];
			if(!s.count(x2)){
				pq.push(x2);
				s.insert(x2);
			}
		}
	}
	cout<<"The 1500'th ugly number is "<<x<<"."<<endl;
	return 0;
}
