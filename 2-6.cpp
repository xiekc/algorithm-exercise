#include <iostream>
using namespace std;

int main () {
	int n,a,min,max,sum,coun=1;
	double aver;
	scanf("%d",&n);
	while(n) {
		scanf("%d",&a);
		sum=min=max=a;
		for(int i=0; i<n-1; i++) {
			scanf("%d",&a);
			sum+=a;
			if(min>a)min=a;
			if(max<a)max=a;
			//	printf("Case %d: %d %d %.3f\n",coun,min,max,aver);
			//	system("pause");
		}
		aver=(double)sum/n;
		printf("Case %d: %d %d %.3f\n",coun,min,max,aver);
		coun++;
		scanf("%d",&n);
		if(n)printf("\n");
	}
	return 0;
}


