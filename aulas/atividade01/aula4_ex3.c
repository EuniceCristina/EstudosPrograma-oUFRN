#include <stdio.h>

int main(){
float valor;
int consumo;

printf("Digite o seu consumo de energia (em kwh): ");
scanf("%d",&consumo);

if (consumo<0){
	printf("\nConsumo inválido");
	return 0;
}else if (consumo<=100){
	valor = consumo*0.5;

} else if ((consumo>100) && (consumo<200)){
	valor = consumo*0.75;
} else{
	valor = consumo*1.2;
}
if (consumo>500){
	float taxa = valor*0.15;
	valor = valor+taxa;
}



printf("Valor total : %.2f R$",valor);

if ((consumo&7)==0){
	printf("\nConsumo múltiplo de 8");
}
return 0;
}