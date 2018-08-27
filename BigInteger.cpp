#include<iostream>
#include<vector>
#include<string>
#include<cstring>
using namespace std;

struct BigInteger{
	static const int BASE=100000000;
	static const int WIDTH=8;
	vector<int> s;
	
	BigInteger(long long num=0){
		*this =num;//have overloaded =
	}
	
	BigInteger operator =(long long num){
		s.clear();
		do{
			s.push_back(num%BASE);
			num/=BASE;
			}while(num>0);
			return *this;
	}
	
	BigInteger operator =(const string& str){
		s.clear();
		int x,len=(str.length()-1)/WIDTH+1;
		for(int i=0;i<len;i++){
			int end =str.length()-i*WIDTH;
			int start=max(0,end-WIDTH);
			sscanf(str.substr(start,end-start).c_str(),"%d",&x);
			s.push_back(x);
		}
		return *this;
	}
};
	
	ostream&operator <<( ostream& out,const BigInteger&x){
		out<<x.s.back();
		for(int i=x.s.size()-2;i>=0;i--){
			char buf[20];
			sprintf(buf,"%08d",x.s[i]);
			for(int j=0;j<strlen(buf);j++)
			out<<buf[j];
		}
		return out;
	}

int main(){
	BigInteger b;
	b="123465489765463412348";
	cout<<b;
	return 0;
}
