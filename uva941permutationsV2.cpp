#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
ll fact[21];
void factorial();

int main() {
	string s;
	int times;
	ll result;
	factorial();
	cin>>times;
	while(times--) {
		cin>>s>>result;
		sort(s.begin(),s.end());
		for(int i=0; i<s.size(); i++) {//repeat consuming result
			sort(s.begin()+i,s.end());//the thought of recursion
			if(result==0)break;
			int pos=i+result/fact[s.size()-i-1];
			swap(s[i],s[pos]);
			result%=fact[s.size()-i-1];//or result-=pos*fact[s.size()-i-1];
		}
		cout<<s<<endl;
	}
	return 0;
}

void factorial() {
	fact[0]=1;
	for(int i=1; i<21; i++) {
		fact[i]=fact[i-1]*i;
	}
}

