#include <stdio.h> 
#define N 4 
int a[N][N];
int path[N]; 
int minDist = 1000;
/*
全排序
例如 123  先取一个元素，例如是取1，则还剩下2,3,例如取2那么剩下就是3。即一种可能为123。   

*/
//交换数字 
void swap(int *a, int *b) {     
    int m;     
     m = *a;     
    *a = *b;     
    *b = m; 
}  

//顺序从s-e中取出一个元素和s交换 
void perm(int list[], int s, int e) {          
    if(s > e) { //剩余集合为空（即为所求的子集） 输出当前某一路径        
        if(list[0]==1) {
        	int dist=0; //当前路径的大小 
        	for(int i=0;i<N-1;i++) {
        		int r=list[i]-1; //-1 是因为点是从1开始，而权值数组的点是从0开始 
        		int c=list[i+1]-1;
        		dist+=a[r][c];
			}
			dist+=a[list[N-1]-1][0];//回到原处
			if(dist<minDist) {
				for(int i=0;i<N;i++) {
					path[i]=list[i];
				}
				minDist = dist;
			}
			printf("路径：");
			for(int i=0;i<N;i++) {
				printf("%d-",list[i]);
			}
			printf("距离是：%d\n",dist);
		} 
		       
           
     }     
    else {         
        for(int i = s; i <= e; i++) {             
             swap(&list[s], &list[i]);   //交换          
             perm(list, s + 1, e);             
             swap(&list[s], &list[i]);  //深度遍历返回时 把之前交换的交换回来    
         }     
     } 
} 

//创建无向图 
void creatArray() {
	for(int i=0;i<N;i++) {
		for(int j=0;j<N;j++) {
			a[i][j]=0;
		}
	} 
	a[0][1]=a[1][0]=2;
	a[0][2]=a[2][0]=7;
	a[0][3]=a[3][0]=5;
	a[1][2]=a[2][1]=3;
	a[1][3]=a[3][1]=8;
	a[2][3]=a[3][2]=1;
}

int main() {  
   
    int list[] = {1, 2, 3, 4};
    int a[N][N];
    creatArray();
    perm(list, 0, N-1);  
     
    printf("\n最短路径：");
	for(int i=0;i<N;i++) {
		printf("%d-",path[i]);
	}
    printf("\n最短路径距离是：%d",minDist); 
    
    return 0; 
}
