#include <stdio.h>
#define n 10  //顶点个数
const int MAX = 1000;//权值最大
int arc[n][n];
int cost[n];
int path[n];
int GreatGraph(){

    for(int i=0;i<n;i++) {
    	for(int j=0;j<n;j++) {
    		arc[i][j]=MAX;
		}
	}

	arc[0][1]=4;arc[0][2]=2;arc[0][3]=3;
	arc[1][4]=9;arc[1][5]=8;
	arc[2][4]=6;arc[2][5]=7;arc[2][6]=8;
	arc[3][5]=4;arc[3][6]=7;
	arc[4][7]=5;arc[4][8]=6;
	arc[5][7]=8;arc[5][8]=6;
	arc[6][7]=6;arc[6][8]=5;
	arc[7][9]=7;arc[8][9]=3;
}
int Backpath(){
	int i,j;  
	for(i=1;i<n;i++){
		cost[i]=MAX;
		path[i]=-1; 
	}
	cost[0]=0;
	path[0]=-1;
	for(j=1;j<n;j++){
		for(i=j-1;i>=0;i--){
			if(arc[i][j]+cost[i]<cost[j]){
				cost[j]=arc[i][j]+cost[i];
				path[j]=i;
			}
		}
	}
	printf("终点是%d-",n-1);
	i=n-1;
	while(path[i]>=0){
		printf("%d-",path[i]);
		i=path[i];
	}
	return cost[n-1];
	 
	
}

	 
int main() {
	 GreatGraph();
	Backpath();
	//printf("%d",cost[n-1]);
}

