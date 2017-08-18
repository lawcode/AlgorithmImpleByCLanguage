#include<stdio.h>
#define N 50
void gameTable(int k, int array[][50]) {
	int n=1;
	for(int i=0;i<k;i++) {
		n*=2;
	}
	for(int j=0;j<n;j++) {
		array[0][j]=j+1;
	}
	int start=1;
	for(int s=0;s<k;s++) {
		n/=2;
		for(int t=0;t<n;t++) {
			for(int i=start;i<2*start;i++) {
				for(int j=start;j<2*start;j++) {
					array[i][j+t*start*2] = array[i-start][j+t*start*2-start];
					array[i][j+t*start*2-start] = array[i-start][j+t*start*2];
				}
			}
		}
		start*=2;
	}
}

void printGame(int k, int array[][50]) {
	int n=1;
	for(int i=0;i<k;i++) {
		n*=2;
	}
	printf("赛程表如下：\n");
	for(int i=0;i<n;i++) {
		for(int j=0;j<n;j++) {
			printf("%d  ",array[i][j]);
		}
		printf("\n");
	}
}
int main() {
	int a[50][50];
	gameTable(3,a);
	printGame(3,a);
	return 1;
}
