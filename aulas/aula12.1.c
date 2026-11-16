#include <stdio.h>
#include <stdlib.h>

int main() {

	float *temp;
	int n;

	printf("\nDigite a quantidade de temperaturas que deseja armazenar: ");
	scanf("%d",&n);
	
	
	temp= (float *) malloc(n * sizeof(float));
	if (temp==NULL) {
		printf("Falha ao alocar na memória\n");
		return 1;

	}

	for (int i=0; i<n;i++){
		printf("\nDigite a temperatura %d: ",i+1);
		scanf("%f",&temp[i]);
			}
	
	for (int i=0;i<n;i++){
		printf("\n%.2f",temp[i]);
	}
	free(temp);
	temp = NULL;
	
	int numero = 10;
	int *vet = (int *) calloc(numero, sizeof(int));

	if (vet==NULL) {
		printf("\nFalha ao alocar na memória");
		return 1;
	}

	for (int i = 0;i<numero;i++){
		printf("\nvet[%d} = %d",i,vet[i]);
	}
	free(vet);

	return 0;



}