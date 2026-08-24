#include <stdio.h>
int main(){
	int a = 5, b = 3;

	int r = a & b;
	int o = a | b;
	int x = a ^ b;
	int n = -a;
	int esq = a >> 1;
	int dir = a<<1;

	printf("%d\n",r);
	printf("%d\n",o);
	printf("%d\n",x);
	printf("%d\n",n);

	printf("%d\n",esq);
	printf("%d\n",dir);

	
	return 0;
}