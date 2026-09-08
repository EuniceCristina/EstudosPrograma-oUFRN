#include <stdio.h>

int main(){

int opcao;

do{

	printf("\n====SUPERMERCADO=====");
	printf("\n1 - Adicionar produtos");
	printf("\n2 - Listar produtos");
	printf("\n3 - Calcular valor total do estoque");
	printf("\n4 - Sair");
	printf("\n: ");
	scanf("%d",&opcao);
	printf("");

	char produto[20];
	float valor_produto,valor_total=0;
	int estoque;

	switch (opcao){
	case 1: 
		printf("\nDigite o nome do produto: ");
		scanf("%s",&produto);
		printf("\nDigite o valor do produto: ");
		scanf("%f",&valor_produto);
		printf("\nDigite a quantidade do produto no estoque: ");
		scanf("%d",&estoque);
		printf("\n\nProduto cadastrado!\n");
		valor_total+=(valor_produto*estoque);
		break;
	case 2:
		int qnt_produtos;
		printf("\nListagem de produtos");
		printf("\nQuantos produtos deseja listar: ");
		scanf("%d",&qnt_produtos);
		for (int i=qnt_produtos;i!=0;i--){
			printf("\nDigite o nome do produto: ");
			scanf("%s",&produto);
			printf("\nDigite o valor do produto: ");
			scanf("%f",&valor_produto);
			printf("\nDigite a quantidade do produto no estoque: ");
			scanf("%d",&estoque);
			
			printf("\n\nProduto : %s",produto);
			printf("\nValor     : %.2f",valor_produto);
			printf("\nEstoque   : %d\n\n",estoque);


		}
		break;	
	case 3:
		if (valor_total==0){
			printf("\nNenhum produto cadastrado no estoque\n");
		} else {
			printf("\nValor total do estoque : %.2f R$\n",valor_total);
		}
		break;
	
	case 4:
		printf("\nEncerrando o sistema...");
		return 0;
	default:
		printf("Opção inválida.\n");
		break;
	}
} while (opcao);

return 0;
}