#include<stdio.h>
//πÈ≤¢≈≈–Ú 
void merge(int r[], int r1[], int s, int m, int t){
	int i=s,j=m+1,k=s;
	while(i<=m && j<=t) {
		if(r[i]<=r[j]) {
			r1[k++]=r[i++];
		} else {
			r1[k++] = r[j++];
		}
	}
	
	while(i<=m) {
		r1[k++]=r[i++];
	}
	while(j<=t) {
		r1[k++]=r[j++];
	}
}
void mergeSort(int r[], int s, int t) {
	int m,r1[1000];
	if(s==t) {
		return;
	} else {
		m = (s+t)/2;
		mergeSort(r,s,m);
		mergeSort(r,m+1,t);
		merge(r,r1,s,m,t);
		for(int i=s;i<=t;i++) {
			r[i]=r1[i];
		}
	}
}

//øÏÀŸ≈≈–Ú 
int partition(int r[], int first, int end) {
	int i=first, j=end;
	while(i<j){
		while(i<j&&r[i]<=r[j])j--;
		if(i<j){
			int temp=r[i];r[i]=r[j];r[j]=temp;
			i++;
		}
		while(i<j&&r[i]<=r[j]) i++;
		if(i<j) {
			int temp=r[i];
			r[i]=r[j];
			r[j]=temp;
			j--;
		}
	}
	return i;
}
void quickSort(int r[], int first, int end) {
	int pivot;
	if (first<end) {
		pivot = partition(r,first,end);
		quickSort(r,first, pivot-1);
		quickSort(r,pivot+1,end);
	}
}
int main() {
	int r[9] = {1,5,6,7,27,32,2,11,20};
	mergeSort(r,0,8);
	//quickSort(r,0,8);
	for(int i=0;i<9;i++) {
		printf("%d\t",r[i]);
	}
}
