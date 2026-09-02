#include <stdio.h>

int main(){
int consumo;
float valor;

printf("Digite o consumo de energia elétrica (em kwh): ");
scanf("%d",&consumo);

if (consumo<0){
	printf("\nVálor inválido");
	return 0;
} else if (consumo<=100){
	valor = consumo*0.5;

}else if ((consumo>100) && (consumo<=200)){
 	valor = consumo*0.75;
} else if (consumo>200){
	valor = consumo*1.20;
}
if (consumo>500){
	int taxa = valor*0.15;
	valor = valor+taxa;
}


printf("\nO valor consumido foi de %.2f R$",valor);

if ((consumo & 7)==0){
	printf("\nConsumo multiplo de 8");
}
return 0;	
}