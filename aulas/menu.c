#include <stdio.h>

int main() {
	int valor1, valor2;
	int opcao;

	printf("Digite o valor 1: ");
	scanf("%d", &valor1);

	printf("Digite o valor 2: ");
	scanf("%d", &valor2);

	printf("\nEscolha uma opcao:\n");
	printf("1 - Soma\n2 - Subtração\n3 - Multiplicação\nOpçaõ: ");
	scanf("%d",&opcao);

 
	switch (opcao) {
		case 1:
			printf("Você escolheu : Soma\n");
			printf("Soma          :       %d + %d = %d\n",valor1,valor2,valor1 + valor2);
			break;
		case 2:
			printf("Você escolheu : Subtração\n");
			printf("Subtração     :       %d - %d = %d\n",valor1,valor2,valor1 - valor2);
			break;
		case 3:
			printf("Você escolheu : Multiplicação\n");
			printf("Multiplicação :       %d * %d = %d\n",valor1,valor2,valor1 * valor2);
			break;
		default:
			printf("Opção inválida");
	}
	return 0;
}


