/*
	 
    ���ݽṹ ����һ��int���� �� һ��int���͵��� 
	ʵ�� ���£� 
  	            int numberArray[K] = {1,10,2,6,9,78,55,33,11,12};
				int number = 0;
	
    ���� ���£�
    ���룺10��Int�͵�����numberArray ��һ�� int�͵�number 
	����� �Ƿ��ҵ����� 
    1��������numberArray
        1.1  ��� number ���� numberArray�е�һ����ʱ return 1
	2. return 0 
	3.��return ��ֵ�����жϣ�
		3.1 �����return��ֵ��1������ҵ�����  �����ʾû���ҵ����� 
*/ 
#include<stdio.h>
#define K 10
int searchNumberInArray(int number, int numberArray[]);
int main(){
	
	int numberArray[K] = {1,10,2,6,9,78,55,33,11,12};
	int number = 0;
	
	//������������ 
//	printf("������10�����ֹ���һ������");
//	for(int i=0;i<K;i++){
//		int temp=0;
//		scanf("%d",&temp);
//	}
	
    // ������ҵ����� 
	printf("������Ҫ���ҵ�����: ");
	scanf("%d",&number);

	// ����Ƿ��ҵ������� 
	if ( searchNumberInArray(number,numberArray) == 1) {
		printf("���������������\n");
	} else {
		printf("��������û�������\n");
	}
	return 0;
}

/*
  number Ҫ���ҵ���
  numberArray  int����
  
  �������� ��numberArray�������number ����ҵ����� 1 ���򷵻� 0 
*/
int searchNumberInArray(int number, int numberArray[]){
	for (int i=0;i<K;i++) {
		if (number == numberArray[i]) {
			return 1;
		}
	}
	return 0;
}

int mpSort(int numberArrray[]){
	for(int i=0;i<K;i++){
		
	}
} 

