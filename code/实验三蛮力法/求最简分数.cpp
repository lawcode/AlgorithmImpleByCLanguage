#include<stdio.h>
//ͨ��շת����� ���������:
int f(int a, int b) {
	if(a==0||b==0) {
		printf("���ӷ�ĸ����Ϊ��\n");
		return 0; 
	}
	int c = a % b;
	if(c==0) {
		return b;
	}
	return f(b,c);
}

int main() {
	int i=6,j=0;
	int a = f(i,j) == 0 ? 1: f(i,j);
	printf("���Լ��Ϊ�� %d\n\n",a);
	printf("%d / %d ��������Ϊ��",i,j); 
	printf("%d / %d",i/a,j/a);
} 
