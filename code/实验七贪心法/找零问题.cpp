#include<stdio.h>
#define N 3

void charge(int a[],int t) {
	int i=0,count=0;
	int j=t;
	for(int i=0;i<N;i++) {
		while(t>=a[i]) {
			t-=a[i];
			count++;
		}
	}
	printf("%dԪ����������Ҫ%döӲ��",j,count);
}
int main() {
	int a[N]={5,3,1};
	charge(a,18);
	return 0;
} 
