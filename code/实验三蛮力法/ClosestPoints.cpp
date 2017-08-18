#include<stdio.h>

int closestPoints(int x[], int y[], int n) {
	int index1=0,index2=0;
	int d,minDist=1000;
	for(int i=0;i<n-1;i++) {
		for(int j=i+1;j<n;j++) {
			d=(x[i]-x[j]) * (x[i]-x[j]) + (y[i]-y[j]) * (y[i]-y[j]);
			if(d<minDist) {
				minDist = d;
				index1=i;
				index2=j;
			}
		}
	}
	printf("最近点对是： (%d,%d)和(%d,%d)",x[index1],y[index1],x[index2],y[index2]);
	return minDist;
}
int main() {
	int x[5] = {1,3,4,7,8};
	int y[5] = {0,0,1,0,0};
	closestPoints(x,y,5);
	return 0;
}
