#include<stdio.h> 
#define N 5
void hamiton(int x[],int arc[][N], int n) {
	int v[N],k=1;
	for(int i=0;i<n;i++) {
		x[i]=0;
		v[i]=0;
	}
	x[0]=0;
	v[0]=1;
	while(k>=1) {
		x[k]+=1;
		while(x[k]<n) {
			if(v[x[k]]==0 && arc[x[k-1]][x[k]]==1) {	
				break;
			} else {
				x[k]+=1;
			}
		}
		if(x[k]<n && k==n-1 && arc[x[k]][0]==1) {
			printf("一个哈密顿回路路径："); 
			for(int j=0;j<n;j++) {
				printf("%d ",x[j]+1);
			}
			return ;
		}
		if(x[k]<n && k<n-1) {
			v[x[k]]=1;
			k=k+1;
		} else {
			v[x[k-1]]=0;
			x[k--]=0;
						
		}
		
	}	
}
int main() {
	int arc[N][N]={0},x[N]={0};

	arc[0][1]=1;
	arc[1][0]=1;
	arc[0][3]=1;
	arc[3][0]=1;
	arc[1][2]=1;
	arc[2][1]=1;
	arc[1][4]=1;
	arc[4][1]=1;
	arc[2][3]=1;
	arc[3][2]=1;
	arc[2][4]=1;
	arc[4][2]=1;
	arc[3][4]=1;
	arc[4][3]=1;
//
//	arc[1][2]=1;
//	arc[2][1]=1;
//	arc[1][4]=1;
//	arc[4][1]=1;
//	arc[2][3]=1;
//	arc[3][2]=1;
//	arc[2][5]=1;
//	arc[5][2]=1;
//	arc[3][4]=1;
//	arc[4][3]=1;
//	arc[3][5]=1;
//	arc[5][3]=1;
//	arc[4][5]=1;
//	arc[5][4]=1;
	
	hamiton(x,arc,N);
	return 0;
} 
