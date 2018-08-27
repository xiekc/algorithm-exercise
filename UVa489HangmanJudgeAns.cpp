#include<stdio.h>
#include<string.h>

#define maxn 100
char ans[maxn],gue[maxn];
int left,chance;//left is the same with left in std
int win,lose;

void guess(char ch) {
	int fail=1;
	for(int j=0; j<strlen(ans)&&left; j++) {
		if(ch==ans[j]) {
			left--;
			ans[j]=' ';
			fail=0;
		}
	}
	if(fail)chance--;
	if(!chance)lose=1;
	else if(!left)win=1;
}

int main() {
	int times;
	scanf("%d",&times);
	while(times!=-1) {
		scanf("%s%s",ans,gue);
		left=strlen(ans);
		chance=7;
		printf("Round %d\n",times);
		win=lose=0;
		for(int i=0; i<strlen(gue); i++) {
			guess(gue[i]);
			if(win||lose) {
				break;
			}
		}
		if(lose)printf("You lose.\n");
		else if(win)printf("You win.\n");
		else printf("You chickened out.\n");
		scanf("%d",&times);
	}
	return 0;
}

