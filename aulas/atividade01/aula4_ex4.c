#include <stdio.h>
#include <string.h>

int main(){

int codigo, quantidade, sobremesa;
float valor,valor_produto;
float valor_sobremesa=0,desconto=0;
char pedido[30];

printf("\n===========MENU==============");
printf("\n1 - Hambúrguer ....... R$ 18,00");
printf("\n2 - X-Salada ......... R$ 22,00");
printf("\n3 - X-Bacon  ......... R$ 25,00");
printf("\n4 - Batata Frita ..... R$ 12,00");
printf("\n5 - Refrigerante ..... R$  7,00");

printf("\n\nDigite o código do produto que deseja consumir: ");
scanf("%d",&codigo);
printf("\nDigite a quantidade que deseja : ");
scanf("%d",&quantidade);
printf("\nDeseja pedir sobremesa? [1-Sim/0-Não] : ");
scanf("%d",&sobremesa);

switch (codigo){
	case 1:
		strcpy(pedido,"Hambúrguer");
		valor_produto=18;
		break;
	case 2:
		strcpy(pedido,"X-Salada");
		valor_produto=22;
		break;
	case 3:
		strcpy(pedido,"X-Bacon");
		valor_produto=25;
		break;
	case 4:
		strcpy(pedido,"Batata Frita");
		valor_produto=12;
		break;
	case 5:
		strcpy(pedido,"Refrigerante");
		valor_produto=7;
		break;

	
	default:
		printf("\nProduto inválido");
		return 0;
}
	if (sobremesa==1){
		valor_sobremesa += 8;
	}

	valor = (valor_produto*quantidade)+valor_sobremesa;

	if (valor>100){
		desconto = valor*0.1;
		valor -= desconto;
		
	} else if ((valor>50) && (valor<=100)){
		desconto = valor*0.05;
		valor -=desconto;
	}
		
printf("\nProduto escolhido     : %s",pedido);
printf("\nUnidades              : %d",quantidade);
printf("\nValor do produto      : %.2f R$",valor_produto);
printf("\nValor sobremesa       : %.2f R$",valor_sobremesa);
printf("\nValor de desconto     : %.2f R$",desconto);
printf("\nValor total do pedido : %.2f R$",valor);
return 0;

}