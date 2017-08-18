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

void egyptFraction(int a, int b) {
	int e = b/a + 1;
	printf("1/%d + ",e);
	a=a*e-b;
	b=b*e;
	int r = f(a,b);
	if(r != 1) {
		a=a/r;
		b=b/r;
	}
	if(a==1) {
		printf("1/%d",b);
	} else {
		egyptFraction(a,b);
	}
}

int main() {
	printf("%d/%d 的埃及分数为：",7,8);
	egyptFraction(7,8); 
	return 0;
} 
