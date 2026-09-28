#include <stdio.h>

int main(){

float temperatura = 75.0;
float *p;

p = &temperatura;

printf("Temperatura : %.1f °C\n",temperatura);
printf("\nEndereço de temperatura: %p",&temperatura);
printf("\nEndereço de armazenamento em p: %p",*p);

*p +=5.0;

printf("\nNova temperatura : %.1f °C",temperatura);

return 0;

}