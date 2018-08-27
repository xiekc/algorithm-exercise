#include<iostream>
#include<stack>
#include<string>
using namespace std;

struct Matrix {
	int a,b;
	Matrix(int a=0,int b=0):a(a),b(b) {
	}
};

int main() {
	Matrix m[26];
	int n,result,flag;
	string s;
	cin>>n;
	for(int i=0; i<n; i++) {
		char c;
		cin>>c;
		cin>>m[c-'A'].a>>m[c-'A'].b;
	}
	while(cin>>s) {
		result=0;
		flag=1;
		stack<Matrix>open;
		for(int i=0; i<s.size(); i++) {
			if(s[i]=='(') {
			} else if(s[i]==')') {
				if(!open.empty()) {
					Matrix x,y;
					y=open.top();
					open.pop();
					x=open.top();
					open.pop();
					if(x.b!=y.a) {
						flag=0;
						cout<<"error\n";
						break;
					}
					result+=x.a*x.b*y.b;
					open.push(Matrix(x.a,y.b));
				}
			} else {
				open.push(Matrix(m[s[i]-'A'].a,m[s[i]-'A'].b));
			}
		}
		if(flag)cout<<result<<endl;
	}
	return 0;
}
