#include<stdio.h>
#define N 6
int a[N];
/*
斐波那契数列: 1、1、2、3、5、8、13、21、34 即 F(n)=F(n-1)+F(n-2)
*/

//底部到顶部递推 
int bottomToTop(int n) {
	
	if(n<=2) {
		return 1;
	} else {
		a[n-1]= bottomToTop(n-1);
		a[n-2]= bottomToTop(n-2);
		return  a[n-1] + a[n-2];
	}
}

//顶部到底部的递归推 
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
	//初始化存放数列和的数组 
	for(int i=0;i<N;i++) {
		a[i]=-1;
	}
	//初始化数列和的第一和第二项 
//	a[0]=1;
//	a[1]=1;
//	result=topToBottom(N-1);
//	printf("第%d个的斐波拉契数列和为%d\n",N,result);
	
	result=bottomToTop(N);
	printf("第%d个的斐波拉契数列和为%d\n",N,result);
	return 0;
} 
