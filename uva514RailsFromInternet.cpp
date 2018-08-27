#include "stdio.h"
void ConditionalPermutation(int i,int t,int m,int n);
int OUTPUT[10];
int WAIT[10];
int j;
int main(int argc, char const *argv[]) {

	ConditionalPermutation(1,3,0,0);
	return 0;
}

void ConditionalPermutation(int i,int t,int m,int n) {
	if(n==t&&m==0) {
		printf("Possiblity~");

		for(j=0; j<t; j++) {
			printf("%d",OUTPUT[j]);
		}
		printf("\n");
	}
	//两个选择：1、弹出栈顶元素 2、将x下一个元素压入元素压入栈中
	//i     即将要压入的元素
	//t     条件排列的总数
	//m     栈内元素个数
	//n     "输出队列"中的个数
	if(i<=t) {
		//一种选择：将下一个元素压入
		//保证当前栈未满
		//因为这里使用的是全局变量所以需要对"栈"进行还原操作
		//当前m指向的位置是即将要插入的位置   ！！！
		int x;
		x=WAIT[m];
		WAIT[m]=i;
		ConditionalPermutation(i+1,t,m+1,n);
		WAIT[m]=x;
	}

	if (m>=1) {
		//一种选择：弹出栈顶元素
		//保证，当前的栈内有元素
		OUTPUT[n]=WAIT[m-1];        //这个正好理解到  ！！！，它认为m是即将要插入的位置，所以m-1才是栈顶的元素
		ConditionalPermutation(i,t,m-1,n+1);
	}


}
