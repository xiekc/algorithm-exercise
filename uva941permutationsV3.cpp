#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
ll fact[21];
void perm(string&s,int i,ll result);

int main() {
	string s;
	int times;
	ll result;
	fact[0]=1;
	for(int i=1; i<21; i++) {
		fact[i]=fact[i-1]*i;
	}
	cin>>times;
	while(times--) {
		cin>>s>>result;
		perm(s,0,result);
		cout<<s<<endl;
	}
	return 0;
}

void perm(string&s,int i,ll result) { //the thought of recursion
	sort(s.begin()+i,s.end());
	if(result==0)return;
	int pos=i+result/fact[s.size()-i-1];
	swap(s[i],s[pos]);
	result%=fact[s.size()-i-1];//or result-=pos*fact[s.size()-i-1];
	perm(s,i+1,result);
}
