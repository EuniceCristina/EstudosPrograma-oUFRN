#include <stdio.h>

int fibonacci(int n){

if (n==0){
		return 0;
}
if (n==1){
		return 1;
}
int soma = fibonacci(n-1) + fibonacci(n-2);

return fibonacci(n-1) + fibonacci(n-2);


}

int main(){
int numero = 10;

for (int i = 0; i <= numero; i++) {
        printf("%d ", fibonacci(i));
    }
}
