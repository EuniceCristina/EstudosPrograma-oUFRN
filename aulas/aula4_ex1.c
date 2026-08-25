#include <stdio.h>

int main() {
	int lado1, lado2, lado3;

	printf("Digite o lado 1: ");
	scanf("%d",&lado1);
	printf("\nDigite o lado 2: ");
	scanf("%d",&lado2);
	printf("\nDigite o lado 3: ");
	scanf("%d",&lado3);
	
	
	if ((lado1+lado2 > lado3) && (lado2+lado3>lado1) && (lado1+lado3 > lado2)) {
		printf("\n%d",lado1 & 3);
		printf("\n%d",lado2 & 3);
		printf("\n%d\n",lado3 & 3);
		printf("%d\n",(((lado1 & 3) == 0) || ((lado2 & 3) == 0)));

		if (((lado1 & 3) == 0) || ((lado2 & 3) == 0) || ((lado3 & 3) == 0)){
			printf("Pelo menos um é par. \n ");
		} else{
			printf("Nenhum deles é par");
		}		

		if ((lado1==lado2) && (lado2==lado3)){
			printf("\nEsse é um triângulo : Equilátero");
		} else if ((lado1==lado2) || (lado1==lado3) || (lado2==lado3)){
			printf("\nEsse é um triângulo : Isósceles");
		} else if ((lado1!=lado2) && (lado2!=lado3)) {
			printf("\nEsse é um triângulo : Escaleno");
		}
	} else {
		printf("Valores não formam um triângulo.");
	}
	return 0;
}