#include<iostream>
#include<stack>
using namespace std;

int output[105];
void trainOut(stack<int> train,int in,int i,int f,int n);

int main() {
	int n;
	while(cin>>n&&n!=0) {
		stack<int> train;
		trainOut(train,1,0,1,n);
	}
	return 0;
}
//f=0 popStack;f=1 pushStack
void trainOut(stack<int> train,int in,int i,int f,int n) {
	if(f==1) {
		train.push(in);
		in++;
	}
	if(f==0) {
		if(train.empty())return;
		else output[i++]=train.top();
		train.pop();
	}
	if(in>n) {
		while(!train.empty()){
			output[i++]=train.top();
			train.pop();
		}
		cout<<output[0];
		for(int j=1; j<n; j++) {
			cout<<' '<<output[j];
		}
		cout<<endl;
		return;
	}
	trainOut(train,in,i,0,n);
	trainOut(train,in,i,1,n);
}

