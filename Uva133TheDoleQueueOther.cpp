#include<stdio.h>
int n,k,m,book[30],cnt,pos1,pos2;
int empty(){
	for(int i=1;i<=n;i++){
		if (book[i]==1) return 0;	
	}
	return 1;
}
int main(){
	
	while(scanf("%d%d%d",&n,&k,&m)){
		if (!n&&!k&&!m) break;
		for(int i=1;i<=n;i++) book[i]=1;
		pos1=0;
		pos2=n+1;
		int fir=0;
		while(!empty()){
			cnt=0;
			while (cnt<k) {
				pos1++;
				pos1=(pos1-1+n)%n+1;
				while (!book[pos1]) {
					pos1++;
					pos1=(pos1-1+n)%n+1;
				}
				cnt++;
			}
			cnt=0;
			while (cnt<m){
				pos2--;
				pos2=(pos2-1+n)%n+1;
				while(!book[pos2]) {
					pos2--;
					pos2=(pos2-1+n)%n+1;
				}
				cnt++;
			}
			

			if (!fir){
				if (pos1==pos2) {
					printf("%3d",pos1);
					book[pos1]=0;
				}
				else {
					printf("%3d%3d",pos1,pos2);
					book[pos1]=0;
					book[pos2]=0;
				}
				fir++;
			}
			else{
				
				if (pos1==pos2) {
					printf(",%3d",pos1);
					book[pos1]=0;
				}
				else {
					printf(",%3d%3d",pos1,pos2);
					book[pos1]=0;
					book[pos2]=0;
				}
			
			}
		}
		printf("\n");
	}
	return 0;
} 

