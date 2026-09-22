#include <stdio.h>

int menu(){
	int opcao;
	
	do {
		printf("\n\nEscolha uma opção: ");
		printf("\n(1) Soma");
		printf("\n(2) Subtração");
		printf("\n(3) Multiplicação");
		printf("\n(4) Divisão");
		printf("\n(5) Sair\n: ");
		scanf("%d",&opcao);
		} while ((opcao<1)||(opcao>5));
		return opcao;	
	
}

int soma(float a,float b){
	float somaValores = a+b;
	return somaValores;
}
int subtracao(float a,float b){
	float subtracaoValores = a-b;
		
	return subtracaoValores;
		
}
int multiplicacao(float a,float b){
	float multiplicacaoValores = a*b;
	return multiplicacaoValores;
}
int divisao(float a,float b){
	float divisaoValores = 0;
	if (b!=0){
		divisaoValores = a/b;
	} 	
	return divisaoValores;
		
}

int main(){
	int opcao;
	do {

	float resultado = 0;
	float valor1;
	float valor2;

	opcao = menu();
	if (opcao==5){
		printf("\nFim do programa!");
		return 0;
		}

	printf("\nDigite o primeiro valor: ");
	scanf("%f",&valor1);
	printf("\nDigite o segundo valor: ");
	scanf("%f",&valor2);
	
	
	switch (opcao){
	
	case 1:
		resultado = soma(valor1,valor2);
		printf("\nSoma %.2f + %.2f = %.2f",valor1,valor2,resultado);
		break;
	case 2:
		resultado = subtracao(valor1,valor2);
		printf("\nSubtração %.2f - %.2f = %.2f",valor1,valor2,resultado);
		break;
	case 3:
		resultado = multiplicacao(valor1,valor2);
		printf("\nMultiplicação %.2f x %.2f = %.2f",valor1,valor2,resultado);
		break;
	case 4:
		resultado = divisao(valor1,valor2);
		if (resultado==0){
			printf("\nNão é possivél realizar divisão por 0");
		} else{
			printf("\nDivisão %.2f / %.2f = %.2f",valor1,valor2,resultado);
		}
		break;
	case 5:
		printf("\nFim do programa!");
		return 0;
				
			
	}
	} while(opcao);
	
return 0;
}
	
