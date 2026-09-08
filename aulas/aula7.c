#include <stdio.h>


int main(){

int idade;

printf("\nDigite sua idade: ");
scanf("%d",&idade);

if (idade<0){
	goto erro;
}

printf("\nSua idade é %d",idade);


return 0;

erro:
	printf("\nDigite um valor válido");
	return -1;
}
