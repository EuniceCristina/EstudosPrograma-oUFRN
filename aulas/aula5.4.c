#include <stdio.h>

int main(){

int N, atual=1, anterior=0, i=1, res=0;

printf("\nDigite a quantidade de elementos da sequência que deseja imprimir: ");
scanf("%d",&N);
printf("%d %d ",anterior,atual);
for (i;i<=N; i++){
	res = atual + anterior;
	anterior = atual;
	atual = res;

	printf("%d ",res);
	}
return 0;
}