#include<iostream>
#include<map>
#include<queue>
using namespace std;

class Q{
	public:
	queue<int> que;
	queue<que>q;
	int a[1005];
}; 
/*自定义类*/ 
/*未完成*/
int main() {
	int t,kase=1;//case是关键词 
	while(scanf("%d",&t)==1&&t) {
		cout<<"Scenario #"<<kase<<endl;
		kase++;
		map<int,int>team;
		for(int i=1; t>0; t--,i++) {
			int n,member;
			cin>>n;
			while(n--) {
				cin>>member;
				team[member]=i;
			}
		}
		Q q();
		while(1) {
			int x;
			char cmd[10];
			cin>>cmd;
			if(cmd[0]=='E') {
				cin>>x;
				if(!q.que.found(team[x]))
					q.que.push(team[x]);
				q2[team[x]].push(x);
			} else if(cmd[0]=='D') {
				cout<<q2[q.front()].front()<<endl;
				q2[q.front()].pop();
				if(q2[q.front()].empty())q.pop();
			} else if(cmd[0]=='S')break;
		}
		cout<<endl;
	}
	return 0;
}
