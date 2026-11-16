#include <stdio.h>

int fatorial(int n){

if (n==1){
	return 1;
}

return n * fatorial(n-1);

}

int main(){
int numero = 5;

printf("\nFatorial de %d: %d",numero,fatorial(numero));
}