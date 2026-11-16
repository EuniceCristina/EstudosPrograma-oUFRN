#include <stdio.h>
#include <stdlib.h>

int main() {

	
int *vet;
int n =3;

vet = (int *) malloc(n * sizeof(int));

if (vet==NULL){
	printf("\nFalha ao alocar na memória");
	return 1;
}

for (int i=0;i<n;i++){
	printf("\nDigite o valor %d: ",i);
	scanf("%d",&vet[i]);
}
for (int i=0;i<n;i++){
	printf("\nValor %d: %d",i+1,vet[i]);
}
n = 5;
vet = realloc(vet,n * sizeof(int));

if (vet==NULL){
	printf("\nFalha ao alocar na memória");
	return 1;
}
printf("\n");
for (int i=3;i<n;i++){
	printf("\nDigite o valor %d: ",i);
	scanf("%d",&vet[i]);
}
for (int i=0;i<n;i++){
	printf("\nValor %d: %d",i+1,vet[i]);
}

free(vet);


}