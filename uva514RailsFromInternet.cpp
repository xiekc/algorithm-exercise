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
	//����ѡ��1������ջ��Ԫ�� 2����x��һ��Ԫ��ѹ��Ԫ��ѹ��ջ��
	//i     ����Ҫѹ���Ԫ��
	//t     �������е�����
	//m     ջ��Ԫ�ظ���
	//n     "�������"�еĸ���
	if(i<=t) {
		//һ��ѡ�񣺽���һ��Ԫ��ѹ��
		//��֤��ǰջδ��
		//��Ϊ����ʹ�õ���ȫ�ֱ���������Ҫ��"ջ"���л�ԭ����
		//��ǰmָ���λ���Ǽ���Ҫ�����λ��   ������
		int x;
		x=WAIT[m];
		WAIT[m]=i;
		ConditionalPermutation(i+1,t,m+1,n);
		WAIT[m]=x;
	}

	if (m>=1) {
		//һ��ѡ�񣺵���ջ��Ԫ��
		//��֤����ǰ��ջ����Ԫ��
		OUTPUT[n]=WAIT[m-1];        //���������⵽  ������������Ϊm�Ǽ���Ҫ�����λ�ã�����m-1����ջ����Ԫ��
		ConditionalPermutation(i,t,m-1,n+1);
	}


}
