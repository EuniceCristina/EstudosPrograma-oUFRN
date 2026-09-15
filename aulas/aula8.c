#include <stdio.h>


int main(){

int matriz[3][3];
int soma=0;
for (int l = 0;l<3;l++){
	for (int c=0;c<3;c++){
		printf("\nValor %d: ",l+c+1);
		scanf("%d",&matriz[l][c]);
		soma +=matriz[l][c];
	}
}
printf("\nSoma : %d",soma);
		
return 0;

}
