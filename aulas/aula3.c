#include <stdio.h>

int main() {
	int valor1, valor2;
	printf("Digite o valor 1: ");
	scanf("%d", &valor1);

	printf("Digite o valor 2: ");
	scanf("%d", &valor2);

	printf("Resultados: \n");

	printf("Soma          :       %d + %d = %d\n",valor1,valor2,valor1 + valor2);
	printf("Subtração     :       %d - %d = %d\n",valor1,valor2,valor1 - valor2);
	printf("Multiplicação :       %d * %d = %d\n",valor1,valor2,valor1 * valor2);

	if (valor2!=0){
		printf("Divisão       :       %d / %d = %d\n",valor1,valor2,valor1 / valor2);
		printf("Resto         :       %d\n",valor1 % valor2);
	} else{
		printf("Divisão       :       Não existe divisão por 0\n");
		printf("Resto         :       Não existe rsto de divisão por 0");
	}
	
	return 0;









	 
};