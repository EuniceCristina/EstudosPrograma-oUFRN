#include <stdio.h>


int main(){

int vetor[8];

for (int i=0;i<8;i++){
	printf("\nDigite o %d: ",i+1);
	scanf("%d",&vetor[i]);
}

int aux=vetor[7];
printf("\nVetor original: ");
for (int i=0;i<8;i++){
	printf("%d ",vetor[i]);
}
for (int i=0;i<4;i++){
	aux = vetor[7-i];
	vetor[7-i] = vetor[i];
	vetor[i] = aux;
	
}
printf("\nNovo vetor: ");
for (int i=0;i<8;i++){
	printf("%d ",vetor[i]);
}
return 0;

}
