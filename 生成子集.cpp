#include<iostream>
using namespace std;

void subsetAdd(int n,int*a,int cur);
void subsetLocation(int n,int*a,int cur);
void subsetBit(int n,int s);

int main() {
	const int maxn=100+5;
	int a[maxn];
	int n=4;
	subsetAdd(n,a,0);
	cout<<endl;
	subsetLocation(n,a,0);
	cout<<endl;
	for(int s=0; s<(1<<n); s++)
		subsetBit(n,s);
	return 0;
}

void subsetAdd(int n,int *a,int cur) {//增量构造法 
	cout<<'{';
	if(cur) {
		int i;
		for(i=0; i<cur-1; i++)
			cout<<a[i]<<',';
		cout<<a[i];
	}
	cout<<'}'<<endl;
	for(int j=cur?a[cur-1]+1:0; j<n; j++) {
		a[cur]=j;
		subsetAdd(n,a,cur+1);
	}
}
void subsetLocation(int n,int*a,int cur) {//位向量法 
	if(cur==n) {
		cout<<'{';
		int i;
		for(i=0; i<n; i++) {
			if(a[i]) {
				cout<<i;
				break;
			}
		}
		for(i++; i<n; i++) {
			if(a[i])cout<<","<<i;
		}
		cout<<"}"<<endl;
		return;
	}
	a[cur]=0;
	subsetLocation(n,a,cur+1);
	a[cur]=1;
	subsetLocation(n,a,cur+1);
}

void subsetBit(int n,int s) {//二进制法 
	cout<<"{";
	if(s) {
		int i;
		for(i=0; i<n; i++) {
			if(s&(1<<i)) {
				cout<<i;
				break;
			}
		}
		for(i++; i<n; i++) {
			if(s&(1<<i))
				cout<<","<<i;
		}
	}
	cout<<"}"<<endl;
}

