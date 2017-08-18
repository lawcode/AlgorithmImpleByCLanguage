#include<stdio.h>
#define N 6
int binSearch(int r[], int low,int hight, int k) {
	if(low==hight) {
		if(r[low]==k) return low;
		else return -1;
	} else {
		int mid = (low + hight) / 2;
		if(k<r[mid]) binSearch(r,low,mid-1,k);
		else if(k>r[mid]) binSearch(r,mid+1,hight,k);
		else return mid;
	}

}
int main() {
	
	int a[N] = {1,3,4,6,8,10};
	printf("%d",binSearch(a,0,N-1,4));
	return 0;
}
