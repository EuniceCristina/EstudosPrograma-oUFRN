#include <stdio.h>

int main(){

int valor_a,valor_b,opcao;
int valor;

printf("Digite valores para a operação. [a & b]");
printf("\na: ");
scanf("%d",&valor_a);
printf("\nb: ");
scanf("%d",&valor_b);

if ((valor_a<0) || (valor_b<0)){
	printf("Valores não podem ser negativos");
	return 0;
}

printf("\n\nA operações são: ");
printf("\n1- E bit a bit (&)");
printf("\n2- OU bit a bit (|)");
printf("\n3- OU exclusivo (^)");
printf("\n4- Deslocamento à esquerda (<<)");
printf("\n5- Deslocamento à direita (>>)");

printf("\nDigite o código da operação: ");
scanf("%d",&opcao);


switch (opcao){

	case 1:
		valor = (valor_a & valor_b);
		break;
	case 2:
		valor = (valor_a | valor_b);
		break;
	case 3:
		valor = (valor_a ^ valor_b);
		break;
	case 4:
		valor = (valor_a << valor_b);
		break;
	case 5:
		valor = (valor_a >> valor_b);
		break;
	default:
		printf("\nOpção inválida.");
		return 0;
}
printf("\nResultado [decimal]     : %d",valor);
printf("\nResultado [hexadecimal] : %x",valor);
return 0;

}
