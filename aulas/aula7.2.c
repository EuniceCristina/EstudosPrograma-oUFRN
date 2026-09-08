#include <stdio.h>


int main(){

int vetor[5] = {5,2,12,15,8};
int soma=0;
int maior=vetor[0];
int menor=vetor[0];
for (int i=0;i<5;i++){
	soma+=vetor[i];
	if (vetor[i]>maior){
		maior = vetor[i];
	}
	if (vetor[i]<menor){
	menor=vetor[i];
	}
}
float media = soma/5.0;
printf("\nSoma  : %d",soma);
printf("\nMaior : %d",maior);
printf("\nMenor : %d",menor);
printf("\nMédia : %.2f",media);

return 0;
}
