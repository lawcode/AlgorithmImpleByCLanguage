/*
	 
    数据结构 定义一个int数组 和 一个int类型的数 
	实现 如下： 
  	            int numberArray[K] = {1,10,2,6,9,78,55,33,11,12};
				int number = 0;
	
    功能 如下：
    输入：10个Int型的数组numberArray 和一个 int型的number 
	输出： 是否找到该数 
    1遍历数组numberArray
        1.1  如果 number 等于 numberArray中的一个数时 return 1
	2. return 0 
	3.对return 的值进行判断：
		3.1 如果是return的值是1则输出找到该数  否则表示没有找到该数 
*/ 
#include<stdio.h>
#define K 10
int searchNumberInArray(int number, int numberArray[]);
int main(){
	
	int numberArray[K] = {1,10,2,6,9,78,55,33,11,12};
	int number = 0;
	
	//输入数字数组 
//	printf("请输入10个数字构成一个数组");
//	for(int i=0;i<K;i++){
//		int temp=0;
//		scanf("%d",&temp);
//	}
	
    // 输入查找的数字 
	printf("请输入要查找的数字: ");
	scanf("%d",&number);

	// 输出是否找到该数字 
	if ( searchNumberInArray(number,numberArray) == 1) {
		printf("该数组中有这个数\n");
	} else {
		printf("该数组中没有这个数\n");
	}
	return 0;
}

/*
  number 要查找的数
  numberArray  int数组
  
  用蛮力法 在numberArray里面查找number 如果找到返回 1 否则返回 0 
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

