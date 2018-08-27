#include <stdio.h>
#include <string.h>

int main() {
	int t;
	scanf("%d",&t);
	while(t--) {
		char a[105];
		char min[105],cur[105];
		scanf("%s",a);
		strcpy(min,a);
		for (int i=1; i<strlen(a); i++) {

			strcpy(cur,a+i);
			strncpy(cur+strlen(cur),a,i);
			cur[strlen(a)]='\0';/*特别注意复制'\0'*/

			if(strcmp(cur, min)< 0) {
				strcpy(min,cur);
			}
		}
		printf("%s\n",min);
	}
	return 0;
}

