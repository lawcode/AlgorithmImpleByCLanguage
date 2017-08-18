#include<stdio.h>
#define N 6

//Ã°ÅİÅÅĞò 
void mp(int array[]) {
	
	for(int i=0;i<N;i++) {
		for(int j=0;j<N-i-1;j++) {
			if(array[j]>array[j+1]) {
				int temp = array[j];
				array[j] = array[j+1];
				array[j+1]=temp;
			}
		}
	} 
}
main() {
	
	int array[N] = {1,6,5,11,3,4};
	mp(array);
	
	for(int i=0;i<N;i++) {
		printf("%d\t",array[i]);
	}
	return 0;
} 
