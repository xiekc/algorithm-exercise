#include<stdio.h>
#include<string.h>

int code[8][1<<8];
int readchar();
int readcode();
int binary(int n);

int main() {
	int len,num;
	while(readcode()) {
		while(1) {
			len=binary(3);
			if(!len)break;
			while(1) {
				num=binary(len);
				if(num==(1<<len)-1)break;
				printf("%c",code[len][num]);
			}
		}
		printf("\n");
	}
	return 0;
}

int readchar() {
	int ch;
	while(1) {
		ch=getchar();
		//if(ch==EOF)return -1;
		if(ch!='\n'&&ch!='\r')return ch;
	}
//	return 0;
}

int readcode() {
	int ch;
	memset(code,0,sizeof(code));//initialize!!!
	code[1][0]=ch=readchar();
	for(int len=2; len<8&&ch!='\n'&&ch!='\r'; len++) {
		for(int j=0; j<(1<<len)-1&&ch!='\n'&&ch!='\r'; j++) {
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
