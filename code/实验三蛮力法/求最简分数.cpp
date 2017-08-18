#include<stdio.h>
//通过辗转相除法 求最大公因子:
int f(int a, int b) {
	if(a==0||b==0) {
		printf("分子分母不能为零\n");
		return 0; 
	}
	int c = a % b;
	if(c==0) {
		return b;
	}
	return f(b,c);
}

int main() {
	int i=6,j=0;
	int a = f(i,j) == 0 ? 1: f(i,j);
	printf("最大公约数为： %d\n\n",a);
	printf("%d / %d 的最简分数为：",i,j); 
	printf("%d / %d",i/a,j/a);
} 
