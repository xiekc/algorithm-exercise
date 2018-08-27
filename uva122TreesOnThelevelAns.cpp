#include<iostream>
#include<cstring>
#include<vector>
#include<queue>
using namespace std;

const int maxn=500;
struct Node {
	bool haveValue;
	int v;
	Node*left,*right;
	Node():haveValue(false),left(NULL),right(NULL) {
	}
};
Node *root;
char s[maxn];
bool fail;

void addNode(int v,char*s);
bool readIn();
bool bfs(vector<int>&ans);

int main() {
	//freopen("uva122.in","r",stdin);
	//freopen("uva122.out","w",stdout);

	vector<int>ans;
	while(readIn()) {
		if(fail)cout<<"not complete\n";
		else if(bfs(ans)) {
			for(int i=0; i<ans.size()-1; i++)
				cout<<ans[i]<<" ";
			cout<<*--ans.end()<<endl;
		} else cout<<"not complete\n";
	}
	return 0;
}

bool readIn() {
	root=new Node();
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
	Node*t=root;
	for(int i=0; i<len; i++) {
		if(s[i]=='L') {
			if(t->left==NULL)
				t->left=new Node();
			t=t->left;
		} else if(s[i]=='R') {
			if(t->right==NULL)
				t->right=new Node();
			t=t->right;
		}
	}
	if(t->haveValue==true)fail=true;
	t->haveValue=true;
	t->v=v;
}

bool bfs(vector<int>&ans) {
	queue<Node*>q;
	ans.clear();
	q.push(root);
	while(!q.empty()) {
		Node*t=q.front();
		q.pop();
		if(t->haveValue==false)return false;
		ans.push_back(t->v);
		if(t->left!=NULL)q.push(t->left);
		if(t->right!=NULL)q.push(t->right);
	}
	return true;
}
