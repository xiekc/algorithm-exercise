#include <stdio.h>

bool read(int str1[105][2],int str2[105][2],int& ctr) {
	char ch;
	if((ch=getchar())!=EOF) {
		for(int i=0; i<105; i++) {
			for(int j=0; j<2; j++) {
				str1[i][j]=0;
				str2[i][j]=0;
			}
		}
		ctr=0;
		str1[ch-30][0]++;
		ctr++;
		while((ch=getchar())!='\n') {
			str1[ch-30][0]++;
			ctr++;
		}
		while((ch=getchar())!='\n') {
			str2[ch-30][0]++;
		}
		return true;
	} else return false;
}

bool isAns(int str1[105][2],int str2[105][2],int& ctr) {//int&!
	int flag;//be careful of flag!
	for(int i=0; i<105&&ctr; i++) {
		flag=0;
		if(str1[i][0]!=0) {
			for(int j=0; j<105; j++) {
				if(str2[j][0]==str1[i][0]&&(!str2[j][1])) {
					str2[j][1]=1;
					flag=1;
					ctr-=str1[i][0];//false:ctr--;
					break;
				}
			}
			if(!flag)return false;
		}
	}
	return true;
}

int main() {
	int str1[105][2],str2[105][2];
	int ctr;
	while(read(str1,str2,ctr)) {
		printf(isAns(str1,str2,ctr)?"YES\n":"NO\n");
	}//make progarm more readable
	return 0;
}

