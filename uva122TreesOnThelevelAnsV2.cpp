#include<cstdio>
#include<cstring>
#include<vector>
#include<queue>
using namespace std;
//array fulfil tree
const int maxn=500;
const int root=1;//0 for NULL
int cnt;
char s[maxn];
int node[maxn],right[maxn],left[maxn];
bool fail,haveValue[maxn];

int newNode();
void addNode(int v,char*s);
bool readIn();
bool bfs(vector<int>&ans);

int main() {
	freopen("uva122.in","r",stdin);
	freopen("uva122.out","w",stdout);

	vector<int>ans;
	while(readIn()) {
		if(fail)printf("not complete\n");
		else if(bfs(ans)) {
			for(int i=0; i<ans.size()-1; i++)
				printf("%d ",ans[i]);
			printf("%d\n",*--ans.end());
		} else printf("not complete\n");
	}
	return 0;
}

bool readIn() {
	cnt=1;
	newNode();
	fail=false;
	while(1) {
		if(scanf("%s",s)!=1)return false;
		if(!strcmp(s,"()"))return true;
		int v;
		sscanf(&s[1],"%d",&v);
		addNode(v,strchr(s,',')+1);
	}
}

void addNode(int v,char*s) {
	int len=strlen(s);
	int t=root;
	for(int i=0; i<len; i++) {
		if(s[i]=='L') {
			if(left[t]==0)
				left[t]=newNode();
			t=left[t];
		} else if(s[i]=='R') {
			if(right[t]==0)
				right[t]=newNode();
			t=right[t];
		}
	}
	if(haveValue[t]==true)fail=true;
	haveValue[t]=true;
	node[t]=v;
}

bool bfs(vector<int>&ans) {
	queue<int>q;
	ans.clear();
	q.push(root);
	while(!q.empty()) {
		int t=q.front();
		q.pop();
		if(haveValue[t]==false)return false;
		ans.push_back(node[t]);
		if(left[t]!=0)q.push(left[t]);
		if(right[t]!=0)q.push(right[t]);
	}
	return true;
}

int newNode() {
	int t=cnt++;
	left[t]=right[t]=0;
	haveValue[t]=false;
	return t;
}
