#include <stdio.h>

int main(){
int numero;
double valorX, novo_valorX;

printf("\nDigite um valor: ");
scanf("%d",&numero);

valorX = 1;
novo_valorX=(valorX + (numero/valorX))/2;

double erro = novo_valorX-valorX;

while (erro > 0.0001){
	valorX = novo_valorX;
	novo_valorX = (valorX + (numero/valorX))/2;

	

	erro = novo_valorX-valorX;
	if (erro<0){
		erro*=-1;
	}
	printf("\n%d",erro);
	

}
printf("\nA raiz de %d é %.2f",numero,novo_valorX);
return 0;
}