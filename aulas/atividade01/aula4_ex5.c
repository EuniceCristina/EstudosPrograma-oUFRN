#include <stdio.h>

int main(){
float saldo = 1000;
int opcao, stop=0;

printf("===CAIXA ELETRÔNICO======");
printf("\n1 - Concultar saldo");
printf("\n2 - Depositar ");
printf("\n3 - Sacar");
printf("\n4 - Verificar limite");
printf("\n5 - Encerrar");



while (stop==0){
printf("\n\nDigite sua opção: ");
scanf("%d",&opcao);
switch (opcao){
	case 1:
		printf("\nSeu saldo atual é de %.2f",saldo);
		break;
	case 2:
		float deposito;
		printf("\nDigite o valor do deposito: ");
		scanf("%f",&deposito);
		if (deposito>0){
			saldo += deposito;
			printf("\nValor depositado!");
		} else{
			printf("\nValor inválido");
		}
		break;
	case 3:
		float saque;
		printf("\nDigite o valor do seu saque: ");
		scanf("%f",&saque);
		if (saque > saldo){
			printf("\nSaldo indisponivél");
		} else if (saque<0){
			printf("\nValor inválido");
		} else{
			saldo -=saque;
			printf("\nValor sacado!");

		}
		break;
	case 4:
		float limite = saldo*0.3;
		printf("\nLImite disponivél para saque : %.2f R$",limite);
		break;

	case 5:
		printf("\nOperação encerrada");
		stop = 1;
	default:
		printf("\nOpção inválida");
		break;
		return 0;
	}
}

return 0;
}



