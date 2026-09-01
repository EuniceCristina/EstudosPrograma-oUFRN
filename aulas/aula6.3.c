#include <stdio.h>

int main(){

float saque = 0;
float total=0;
while (saque>=0){

	printf("\nDigite o valor que deseja sacar: ");
	scanf("%d",saque);
	
	if (saque<0){
		printf("\nO valor é nulo ou negativo. Tente novamente");
		continue;
	} else if ((saque/10)!=0){
		printf("\nO valor digitado não pode ser entregue deveido a células disponivéis. Tente um valor fechado.");
		continue;
	} else if (saque == 999){
		printf("Fim do programa!");
		break;
	}
}
return 0;
}