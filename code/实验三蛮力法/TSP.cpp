#include <stdio.h> 
#define N 4 
int a[N][N];
int path[N]; 
int minDist = 1000;
/*
ȫ����
���� 123  ��ȡһ��Ԫ�أ�������ȡ1����ʣ��2,3,����ȡ2��ôʣ�¾���3����һ�ֿ���Ϊ123��   

*/
//�������� 
void swap(int *a, int *b) {     
    int m;     
     m = *a;     
    *a = *b;     
    *b = m; 
}  

//˳���s-e��ȡ��һ��Ԫ�غ�s���� 
void perm(int list[], int s, int e) {          
    if(s > e) { //ʣ�༯��Ϊ�գ���Ϊ������Ӽ��� �����ǰĳһ·��        
        if(list[0]==1) {
        	int dist=0; //��ǰ·���Ĵ�С 
        	for(int i=0;i<N-1;i++) {
        		int r=list[i]-1; //-1 ����Ϊ���Ǵ�1��ʼ����Ȩֵ����ĵ��Ǵ�0��ʼ 
        		int c=list[i+1]-1;
        		dist+=a[r][c];
			}
			dist+=a[list[N-1]-1][0];//�ص�ԭ��
			if(dist<minDist) {
				for(int i=0;i<N;i++) {
					path[i]=list[i];
				}
				minDist = dist;
			}
			printf("·����");
			for(int i=0;i<N;i++) {
				printf("%d-",list[i]);
			}
			printf("�����ǣ�%d\n",dist);
		} 
		       
           
     }     
    else {         
        for(int i = s; i <= e; i++) {             
             swap(&list[s], &list[i]);   //����          
             perm(list, s + 1, e);             
             swap(&list[s], &list[i]);  //��ȱ�������ʱ ��֮ǰ�����Ľ�������    
         }     
     } 
} 

//��������ͼ 
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
     
    printf("\n���·����");
	for(int i=0;i<N;i++) {
		printf("%d-",path[i]);
	}
    printf("\n���·�������ǣ�%d",minDist); 
    
    return 0; 
}
