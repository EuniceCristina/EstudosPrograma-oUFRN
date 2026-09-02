#include <stdio.h>

int main(){

int ano;

printf("Digite seu ano : ");
scanf("%d",&ano);

if ( (((ano & 4) == 0) && ((ano % 100) != 0)) || ((ano % 400) == 0) ){
	printf("Ano bissexto");
} else {
	printf("Não é bisexto");
}

if ((ano&3)==0){
printf("\nÉ par");

} else{
	printf("\nÉ ímpar");
}
}