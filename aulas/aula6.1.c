#include <stdio.h>

int main(){

int num;
printf("\nDigite as dimensões da sua matriz [linha/coluna]: ");
scanf("%d",&num);

int l = 1;

printf("\nMatriz %dX%d:\n",num,num);
while (l<=num){
	int c = 1;
	printf("\n");
	while (c<=num){
		if (l==c) {
			printf("1 ");
		} else{
			printf("0 ");
		}
		c++;
	}
	l++;
}
return 0;
}