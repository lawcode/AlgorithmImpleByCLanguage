#include<stdio.h>
#define N 6
int a[N];
/*
쳲���������: 1��1��2��3��5��8��13��21��34 �� F(n)=F(n-1)+F(n-2)
*/

//�ײ����������� 
int bottomToTop(int n) {
	
	if(n<=2) {
		return 1;
	} else {
		a[n-1]= bottomToTop(n-1);
		a[n-2]= bottomToTop(n-2);
		return  a[n-1] + a[n-2];
	}
}

//�������ײ��ĵݹ��� 
int topToBottom(int n) {
	if(a[n-1]!=-1&&a[n-2]!=-1) {
		a[n]=a[n-1] + a[n-2];
	} else {
		a[n] = topToBottom(n-1) + topToBottom(n-2);
	}
	return a[n];
}
int main() {
	int result=0; 
	//��ʼ��������к͵����� 
	for(int i=0;i<N;i++) {
		a[i]=-1;
	}
	//��ʼ�����к͵ĵ�һ�͵ڶ��� 
//	a[0]=1;
//	a[1]=1;
//	result=topToBottom(N-1);
//	printf("��%d����쳲��������к�Ϊ%d\n",N,result);
	
	result=bottomToTop(N);
	printf("��%d����쳲��������к�Ϊ%d\n",N,result);
	return 0;
} 
