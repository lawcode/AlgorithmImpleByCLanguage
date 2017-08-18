#include<stdio.h> 
#define N 4 
#define W 10

float x[N];

/*
	贪心法解背包问题方案： 把每个物品的单价求出来按从大到小排序，之后最排序之后的重量数组选择能装的物品 
	
	把每个物品的单价求出来按从大到小排序 思路：把物品的单价和 对应的序列数组 传给快排，快排这两个进行排序可知w[index[i]] 就是没排序之前的w[i] 

*/
//快速排序 
int partition(int r[],int index[], int first, int end) {
	int i=first, j=end;
	while(i<j){
		while(i<j&&r[i]>=r[j])j--;
		if(i<j){
			int temp=r[i];r[i]=r[j];r[j]=temp;
			int temp1=index[i];index[i]=index[j];index[j]=temp1;
			i++;
		}
		while(i<j&&r[i]>=r[j]) i++;
		if(i<j) {
			int temp=r[i];
			r[i]=r[j];
			r[j]=temp;
			int temp1=index[i];index[i]=index[j];index[j]=temp1;
			j--;
		}
	}
	return i;
}
void quickSort(int r[],int index[], int first, int end) {
	int pivot;
	if (first<end) {
		pivot = partition(r,index,first,end);
		quickSort(r,index,first, pivot-1);
		quickSort(r,index,pivot+1,end);
	}
}

//对重量和价值数组 根据单价即 values[i]/weights[i] 进行排序 
void sort(int weights[], int values[]) {
	int w[N],v[N], a[N],index[N]; //a存放单价数组 index存放a数组的序号， 
	int max=0;
	for(int i=0;i<N;i++) {
	    a[i]=values[i]/weights[i];
		index[i]=i;
	}
 
	quickSort(a,index,0,N-1);
	
	for(int i=0;i<N;i++) {
		w[i]=weights[index[i]];  //index[i]=没有排序之前的i
		v[i]=values[index[i]];
	}
	for(int i=0;i<N;i++) {
		weights[i]=w[i];
		values[i]=v[i];
	}
	
}
// 背包问题 
void knapsack(int weights[], int values[]) {
	int w=W; 
	float maxValue=0;
	sort(weights,values);

	for(int i=0;i<N;i++) {
		x[i]=0;
	}
	int i=0;
	while(weights[i]<=w) {
		x[i]=1.0;
		maxValue+=values[i]*1.0;
		w=w-weights[i];
		i++;
	}
	x[i]=(w*1.0)/(weights[i]*1.0); // *1.0 是把int转换成float  int只能进行整除 不能进行除法操作 
	maxValue+=x[i]*values[i];
	printf("装入策略是：");
	for(int i=0;i<N;i++) {
		printf("%0.2f ,",x[i]);
	}
	printf("\n价值为：%0.2f",maxValue);
	
	
	
} 

int main() {
	int weights[4] = {7,3,4,5};
	int values[4] = {42,12,40,25};
	knapsack(weights,values);
	return 0;
} 
