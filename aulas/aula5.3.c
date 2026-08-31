#include <stdio.h>

int main(){

int valor,i,soma=0;
printf("Digite um valor: ");
scanf("%d",&valor);
printf("\n0 ");
for (i=1;i<=valor;i++){
	if (i%2==0){
		soma+=i;
		printf("+ %d ",i);

	}
}
printf("= %d",soma);
return 0;
}