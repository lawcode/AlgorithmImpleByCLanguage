#include<stdio.h>
#define N 8
void increaseOrder(int a[]) {
	int index=0;
	int l[N],x[N][N];
	for(int i=0;i<N;i++) {
		l[i]=1;
		x[i][0]=a[i];
	} 
	for(int i=1;i<N;i++) {
		int max =1;
		for(int j=i-1; j>=0;j--) {
			if((a[j]<a[i]) && (max<l[j]+1)) {
				max=l[j]+1;
				l[i]=max;
				for(int k=0;k<max-1;k++) {
					x[i][k]=x[j][k];
				}
				x[i][max-1]=a[i];
			}
		}
	}
	
	for(int i=1;i<N;i++) {
		if(l[index]<l[i]) index=i;
	}
	
	printf("最长递增子序列为：");
	for(int i=0;i<l[index];i++) {
		printf("%d ,",x[index][i]);
	}
	
}
int main() {
	int a[N]={5,2,8,6,3,6,9,8};
	increaseOrder(a);
	return 0;
} 
