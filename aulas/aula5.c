#include <stdio.h>

int main(){

int a,b;
printf("\nDIgite dois valos inteiro: ");
scanf("%d %d",&a,&b);

while (a<b){
	a++;
	printf("\n%d",a);
	}
printf("\nFim do programa!");
return 0;
}