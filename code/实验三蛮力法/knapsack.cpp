#include<stdio.h>
#define W 10
/*
  ���Ӽ� 
  �Ӽ�        ���        ��Ӧ�Ķ����� 
  {0}   	   1   		 001
  {1}   	   2    	010
  {0��1}  	   3  		011
  {2}		   4		100
  {0��2}       5  		101
  {1��2}	   6		110
  {0��1��2}    7        111

  ����һ������ �����������1 ��Ӧһ���Ӽ���Ԫ���� 010 ���� 1 
  ����ͨ��շת������ӵ�λ����λת���ɶ����ƣ�
  �ٶԶ����Ƴ�2ȡģ��ÿ��ȡģʱK++�� ������1���ҵ�1�����K�����Ӽ��е�Ԫ�� ��

*/

void knapsack(int weights[], int values[], int n) {
	int weight=0,value=0,maxValue=0;
	int t[n];//��ű������ֵ���Ӽ� 
	int length=0;//�����Ӽ��ĳ��� 
	int m=1;//�Ӽ�����  m=2^n -1 
	
	//��m 
	for(int i=0;i<n;i++) {
		m*=2;
	}
	m--;
	printf("�����Ӽ����£�\n"); 
	//���Ӽ� ���Ӽ��ĸ��� 
	for(int i=1;i<=m;i++) { //���ÿ���Ӽ� 
		printf("%d{",i);
		int j=i,k=0,a[n],l=0;//a��ŵ�ǰ���Ӽ���l��a���ϵĳ��ȣ�k���Ӽ��е�Ԫ�أ� 
		while(j!=0){//���Ӽ�Ԫ�� 
			if(j%2==1){
				printf("%d",weights[k]);
				if(weight+weights[k]<=W){//���Ƿ�װ���� 
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
			for(int i=0;i<length;i++) {//�ѵ�ǰ���ֵ���Ӽ����Ƶ����ֵ�Ӽ��ļ����� 
				t[i]=a[i];
			}
		} 
		weight=0;
		value=0;
		printf("}\n");
	}
	printf("\n�����Ӽ�Ϊ��{");
	for(int i=0;i<length;i++) {
		printf("%d",t[i]);
		if(i!=length-1) {
			printf(",");
		}
	}
	printf("}\n");
	printf("\n��������װ������ֵΪ�� %d",maxValue);
}
//���Ӽ� 
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
