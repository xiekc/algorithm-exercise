#include <stdio.h>
#include <string.h>

int main() {
	int str1[105][2],str2[105][2];
	char ch;
	int flag=0,i,j,ctr;
	while((ch=getchar())!=EOF) {
		for(i=0; i<105; i++) {//initialize!!!
			for(j=0; j<2; j++) {
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
		for(i=0; i<105&&ctr; i++) {
			flag=0;
			if(str1[i][0]!=0) {
				for(j=0; j<105; j++) {
					if(str2[j][0]==str1[i][0]&&(!str2[j][1])) {
						str2[j][1]=1;
						flag=1;
						ctr-=str1[i][0];//false:ctr--; 
						break;
					}
				}
				if(!flag) {
					printf("NO\n");
					break;
				}
			}
		}
		if(flag)
			printf("YES\n");
	}
	return 0;
}

