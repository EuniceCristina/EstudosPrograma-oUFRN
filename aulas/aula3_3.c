#include <stdio.h>

int main(){
	int idade = 22;
	
	const char *resultado = 
	 (idade >= 18) ? 
		"Maior de idade" : 
		"Menor de idade";
	printf("%s\n",resultado);
	return 0;

}
	
