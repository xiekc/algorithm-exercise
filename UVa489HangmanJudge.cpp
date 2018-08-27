#include<iostream>
#include<cstring>
#include<algorithm>//sort()
using namespace std;
//This program is not perfect\
input 1 cheese chesabcdhijkl\
output lose. But should win
  
int judge(char ans[100],char gue[100]) {
	int ctr=0,flag,mark[100]= {0};
	sort(ans,ans+strlen(ans));
	sort(gue,gue+strlen(gue));//can don't use sort()
	for(int j=0; j<strlen(ans); j++)//pretreat
		if((j!=0&&ans[j]==ans[j-1])) mark[j]=1;
	for(int i=0; i<strlen(gue); i++)//pretreat
		if((i!=0&&gue[i]==gue[i-1])) ctr++;
	for(int i=0; i<strlen(gue)&&ctr<7; i++) {//should search gue in ans
		flag=0;
		for(int j=0; j<strlen(ans); j++) {
			if(ans[j]==gue[i]) {
				flag=1;
				mark[j]=1;
				break;
			}
		}
		if(flag==0) ctr++;
	}
	if(ctr>=7)return -1;
	for(int j=0; j<strlen(ans); j++)
		if(mark[j]==0)return 0;
	return 1;
}

int main() {
	int times;
	char ans[100],gue[100];
	scanf("%d",&times);
	while(times!=-1) {
		scanf("%s",ans);
		scanf("%s",gue);
		printf("Round %d\n",times);
		switch(judge(ans,gue)) {
			case 1:
				printf("You win.\n");
				break;
			case -1:
				printf("You lose.\n");
				break;
			case 0:
				printf("You chickened out.\n");
				break;
		}
		scanf("%d",&times);
	}
	return 0;
}

