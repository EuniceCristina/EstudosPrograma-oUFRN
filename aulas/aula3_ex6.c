#include <stdio.h>

int main(){

	int numero1,numero2;
	printf("Digite dois numeros: ");
	scanf("%d %d", &numero1,&numero2);

	printf("\n a == b : %d\n",numero1 == numero2);
	printf(" a != b : %d\n",numero1 != numero2);
	printf(" a >  b : %d\n",numero1 > numero2);
	printf(" a <  b : %d\n",numero1 < numero2);
	printf(" a >= b : %d\n",numero1 >= numero2);
	printf(" a <= b : %d\n",numero1 <= numero2);

	return 0;
};