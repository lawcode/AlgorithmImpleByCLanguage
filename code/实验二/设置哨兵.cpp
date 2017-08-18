#include<stdio.h>

int seqSearch(int r[], int n, int k) {
	int i=0;
	int e=r[n];
	r[n]=k;
	
	while(r[i] !=k ) {
		i++;
	}
	
	if(i==n) {
		if(e==k) {
			return i;
		} else {
			return 0;
		}
	} else {
		return i;
	}
	
}

int main() {
	
	int r[5]={1,5,6,9,11};
	printf("%d",seqSearch(r,4,11));
	return 0;
} 
