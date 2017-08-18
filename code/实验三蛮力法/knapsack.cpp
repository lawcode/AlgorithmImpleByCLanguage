#include<stdio.h>
#define W 10
/*
  求子集 
  子集        序号        对应的二进制 
  {0}   	   1   		 001
  {1}   	   2    	010
  {0，1}  	   3  		011
  {2}		   4		100
  {0，2}       5  		101
  {1，2}	   6		110
  {0，1，2}    7        111

  发现一个规律 二进制里面的1 对应一个子集的元素如 010 代表 1 
  所以通过辗转相除法从低位到高位转换成二进制，
  再对二进制除2取模，每次取模时K++， 进行找1，找到1，则该K就是子集中的元素 ，

*/

void knapsack(int weights[], int values[], int n) {
	int weight=0,value=0,maxValue=0;
	int t[n];//存放背包最大值的子集 
	int length=0;//所求子集的长度 
	int m=1;//子集个数  m=2^n -1 
	
	//求m 
	for(int i=0;i<n;i++) {
		m*=2;
	}
	m--;
	printf("所有子集如下：\n"); 
	//求子集 ：子集的个数 
	for(int i=1;i<=m;i++) { //获得每个子集 
		printf("%d{",i);
		int j=i,k=0,a[n],l=0;//a存放当前的子集，l是a集合的长度，k是子集中的元素， 
		while(j!=0){//求子集元素 
			if(j%2==1){
				printf("%d",weights[k]);
				if(weight+weights[k]<=W){//看是否装的下 
					weight+=weights[k];
					value+=values[k];
					a[l]=weights[k];
					l++;
				} 
				if(j!=1) {
					printf(",");
				}
			}
			k++;
			j/=2;
		}
		if(maxValue<value) {
			maxValue=value;
			length=l;
			for(int i=0;i<length;i++) {//把当前最大值的子集复制到最大值子集的集合中 
				t[i]=a[i];
			}
		} 
		weight=0;
		value=0;
		printf("}\n");
	}
	printf("\n所求子集为：{");
	for(int i=0;i<length;i++) {
		printf("%d",t[i]);
		if(i!=length-1) {
			printf(",");
		}
	}
	printf("}\n");
	printf("\n背包所能装的最大价值为： %d",maxValue);
}
//求子集 
void a() {
	int n=4,m=1,j=0,k;
	for(int i=0;i<n;i++)m*=2;	
	m--;
	for(int i=1;i<=m;i++){
		printf("{"); 
		j=i;
		k=0;
		while(j!=0){
			if(j%2==1)printf("%d",k);
			k++;
			j/=2;
		}
		printf("}"); 
	}
}

int main() {
	int weights[4] = {7,3,4,5};
	int values[4] = {42,24,40,25};//{42,12,40,25};
	knapsack(weights,values,4);
	return 0;
} 
