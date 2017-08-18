#include<stdio.h>
#include<math.h>
#define N 20
int a[N];
//判断整数X是否是素数 
int prime(int x) {
	int n;
	n = (int)sqrt(x);
	for(int i=2;i<=n;i++) {
		if(x%i==0) return 0;
	}
	return 1;
}

//判断位置x填写的是否满足约束条件 
int check(int k,int n) {
	int flag = 0;
	for(int i=0;i<k;i++) {
		if(a[i]==a[k]) {
			return 0;
		}
	}
	flag=prime(a[k]+a[k-1]);
	if(flag==1 && k==n-1) {
		flag=prime(a[k]+a[0]);
	}
	return flag;
	
} 

void primeCircle(int n) {
	int k=1;
	for(int i=0;i<n;i++) {
		a[i]=i;
	}
	a[0]=1;
	while(k>=1) {
		a[k]=a[k]+1;
		while(a[k]<=n) {
			if(check(k,n)==1) break;
			else a[k]=a[k]+1;
		}
		if(a[k]<=n && k==n-1) {
			for(int i=0;i<n;i++) {
				printf("%d ",a[i]);
			}
			return ;
		}
		if(a[k]<=n && k<n-1) {
			k=k+1;
		} else {
			a[k--]=0;
		}
	}
}

int main() {
	primeCircle(N);
	return 0;
} 
