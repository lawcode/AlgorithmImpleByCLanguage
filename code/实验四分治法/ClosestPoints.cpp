#include<stdio.h>
int closestPoint(int x[], int n) {
	int index1,index2,i=0;
	int d, minDist = 1000;
	while(i<n-1) {
			d = x[i+1] - x[i]>0 ? x[i+1] - x[i] : x[i] - x[i+1];
			if (d<minDist) {
				minDist=d;
				index1=i;
				index2=i+1;
	        }
	        i++;
	        printf("%d\t%d",x[i],x[i+1]);
	        printf("\n");
	}
	printf("最近点对是：%d\t%d\n",x[index1],x[index2]);
	return minDist;
}

int closestPoint(int x[], int left, int right) {
	int minDist=1000,midDist=1000,leftDist=1000,rightDist=1000;
	int center;
	if(right - left<=2) {
		if(right-left==2) { // 3个点的情况 
		int s1 = x[left+1]-x[left] > 0 ? x[left+1]-x[left] : x[left]-x[left+1]; 
		int s2 = x[right]-x[left+1] > 0? x[right]-x[left+1] : x[left+1]-x[right];
			minDist = s1 < s2 ? s1 : s2;
		} else {//2个点的情况 
			minDist = x[right] - x[left];
		}
		
	} else {
		center = (left + right)/2;
		if (center>left) { //避免出现一个点 
			leftDist = closestPoint(x,left, center);
			rightDist = closestPoint(x,center+1, right);
			printf("leftDist： %d\n",leftDist);
			printf("rightDist： %d\n",rightDist);
			if(leftDist<rightDist) {
				minDist = leftDist;
			} else {
				minDist = rightDist;
			}
			midDist = x[center+1] - x[center] > 0 ? x[center+1] - x[center] : x[center] - x[center+1];
			printf("midDist： %d\n",midDist);
			if(midDist<minDist) {
				minDist = midDist;
			} 
			
		} 
			
		
	}
	return minDist;
}
int main() {
	int points[6] = {1,5,7,13,23,30};//{1,7,5,3,16,6};//{1,5,7,13,23,30};// {1,3,9,10,15,30}; // {1,7,13,10,16,30}; 
	//closestPoint(points,6);
	printf("最短距离%d\n\n\n",closestPoint(points,6));
	printf("最短距离%d\n",closestPoint(points,0,5));
} 
