#include <stdio.h>
#include <string.h>

typedef struct {
	char nome[20];
	float preco;
	int quantidade;
}Estoque;

int main(){

Estoque estoque;
printf("\nDigite o nome do seu prouto: ");
scanf("%s",&estoque.nome);
printf("\nDigite o preço: ");
scanf("%f",&estoque.preco);
printf("\nQuantidade no estoque: ");
scanf("%d",&estoque.quantidade);

printf("\n%f",estoque.preco*estoque.quantidade);

return 0;

}
