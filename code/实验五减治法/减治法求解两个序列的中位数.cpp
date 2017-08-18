#include<stdio.h> 
#define N 5
int searchMid(int a[], int b[], int s1, int e1, int s2, int e2) {
	if(s1<e1&&s2<e2) {
		int mid1=(s1+e1)/2;
		int mid2=(s2+e2)/2;
		if(a[mid1]==b[mid2]) return a[mid1];
		else if(a[mid1]<b[mid2]) {
			if((s1+e1)%2==0) s1=mid1;
			else s1=mid1+1;
			e2=mid2;
			return searchMid(a,b,s1,e1,s2,e2);
		} else {
			if((s2+e2)%2==0) s2=mid2;
			else s2=mid2+1;
			e1=mid1;
			return searchMid(a,b,s1,e1,s2,e2);
		}
	} else {
		if(a[s1]<b[s2]) return a[s1];
		else return b[s2];
	}
	
}

int main() {
	int a[N]={11,13,15,17,19};
	int b[N]={2,4,10,15,20};
	printf("%d",searchMid(a,b,0,N-1,0,N-1));
	return 0;
} 
