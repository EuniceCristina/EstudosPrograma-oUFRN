#include <stdio.h>

int main(){
int opcao = 1;
do {
int altura;

printf("\nDigite a altura da sua pirâmide: ");
scanf("%d",&altura);

if ((altura<1) || (altura>20)){
	printf("\nAltura inválida. Tente novamente.\n");
	continue;
}

for (int i = 0;i<altura;i++){
	printf("\n");
	for (int l = 0;l<=i;l++){
		printf("*");
	}
}
printf("\n\nDeseja continuar impremindo? [0-Não/1-Sim]\n ");
scanf("%d",&opcao);
if ((opcao!=0) && (opcao!=1)){
	continue;
}

} while (opcao==1);
return 0;
}