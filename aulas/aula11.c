#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>


union LeituraSensor {
	uint8_t bytes[2];
	uint16_t valor_completo;
} ;

typedef struct {
	char nome[50];
	int idade;
} Pessoa;
int main(){
	Pessoa p = {"Ana",30};
	Pessoa *ptr = &p;

	printf("\nNome : %s",(*ptr).nome);
	printf("\nIdade : %d",(*ptr).idade);

	union LeituraSensor sensor;

	sensor.bytes[0] = 0x2C;
	sensor.bytes[1] = 0x01;
}

