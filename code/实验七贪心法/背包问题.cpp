#include<stdio.h> 
#define N 4 
#define W 10

float x[N];

/*
	̰�ķ��ⱳ�����ⷽ���� ��ÿ����Ʒ�ĵ�����������Ӵ�С����֮��������֮�����������ѡ����װ����Ʒ 
	
	��ÿ����Ʒ�ĵ�����������Ӵ�С���� ˼·������Ʒ�ĵ��ۺ� ��Ӧ���������� �������ţ��������������������֪w[index[i]] ����û����֮ǰ��w[i] 

*/
//�������� 
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

//�������ͼ�ֵ���� ���ݵ��ۼ� values[i]/weights[i] �������� 
void sort(int weights[], int values[]) {
	int w[N],v[N], a[N],index[N]; //a��ŵ������� index���a�������ţ� 
	int max=0;
	for(int i=0;i<N;i++) {
	    a[i]=values[i]/weights[i];
		index[i]=i;
	}
 
	quickSort(a,index,0,N-1);
	
	for(int i=0;i<N;i++) {
		w[i]=weights[index[i]];  //index[i]=û������֮ǰ��i
		v[i]=values[index[i]];
	}
	for(int i=0;i<N;i++) {
		weights[i]=w[i];
		values[i]=v[i];
	}
	
}
// �������� 
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
	x[i]=(w*1.0)/(weights[i]*1.0); // *1.0 �ǰ�intת����float  intֻ�ܽ������� ���ܽ��г������� 
	maxValue+=x[i]*values[i];
	printf("װ������ǣ�");
	for(int i=0;i<N;i++) {
		printf("%0.2f ,",x[i]);
	}
	printf("\n��ֵΪ��%0.2f",maxValue);
	
	
	
} 

int main() {
	int weights[4] = {7,3,4,5};
	int values[4] = {42,12,40,25};
	knapsack(weights,values);
	return 0;
} 
