#include<stdio.h>
#include<string.h>

int code[8][1<<8];
int readchar();
int readcode();
int binary(int n);

int main() {
	int len,num;
	while(readcode()) {
		while(len=binary(3)) {
			while((num=binary(len))!=(1<<len)-1) {
				printf("%c",code[len][num]);
			}
		}
		printf("\n");
	}
	return 0;
}

int readchar() {
	int ch;
	while(ch=getchar()) {
		//if(ch==EOF)return -1;
		if(ch!='\n'&&ch!='\r')return ch;
	}
//	return 0;
}

int readcode() {
	int ch;
	memset(code,0,sizeof(code));//initialize!!!
	code[1][0]=ch=readchar();
	for(int len=2; len<8&&ch!='\n'; len++) {
		for(int j=0; j<(1<<len)-1&&ch!='\n'; j++) {
			if(ch==EOF)return 0;
			ch=getchar();
			code[len][j]=ch;
		}
	}
	return 1;
}

int binary(int n) {
	int bina=0;
	while(n--) {
		bina=bina*2+readchar()-'0';
	}
	return bina;
}
