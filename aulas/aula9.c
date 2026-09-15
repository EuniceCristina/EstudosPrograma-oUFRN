#include <stdio.h>
#include <string.h>

union LeituraSensor {
	short int valor_completo;
	unsigned char bytes[2];
};

int main(){
	union LeituraSensor valor;
	
	printf("\nDigite o byte baixo: ");
	scanf("%d",&valor.bytes[0]);
	printf("\nDigite o byte alto: ");
	scanf("%d",&valor.bytes[1]);

	printf("\nValor completo: %d",valor.valor_completo);

return 0;
}