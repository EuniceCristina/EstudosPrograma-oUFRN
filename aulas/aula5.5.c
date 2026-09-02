#include <stdio.h>

int main(){

int num,fatorial=1,i=1;

printf("\nDigite um número: ");
scanf("%d",&num);

for (i;i<=num;i++){
	fatorial*=i;
}
printf("Fatorial : %d",fatorial);
return 0;
}