#include<stdio.h>
#define N 11

int activeManager(int s[],int f[],int b[], int n) {
	int i,j,count;
	b[0]=1,j=0,count=1;
	for(i=1;i<n;i++) {
		if(s[i]>=f[j]) {
			b[i]=1;
			j=i;
			count++;
		} else {
			b[i]=0;
		}
	} 
	return count;
}

int main() {
	int s[N]={1,3,0,5,3,5,6,8,8,2,12};
	int f[N]={4,5,6,7,8,9,10,11,12,13,14};
	int b[N];
	int count=0;
	count=activeManager(s,f,b,N);
	printf("选定的活动个数为:%d个\n",count);
	printf("选定的活动集合为{");
	for(int i=0;i<N;i++) {
		if(b[i]==1) {
			printf("%d,",i+1);
		} 
		
	}
	 printf("}");

	
	return 0;
}
