#include <stdio.h>

int main(){
int id_produto, qnt_vendas;

float valor_total;

while (qnt_vendas>=0){
float venda;
printf("\nVenda %d",qnt_vendas+1);
printf("\nId do produto: ");
scanf("%d",&id_produto);
if (id_produto==-1){
	printf("\nFim do programa!");
	break;
	}
printf("Valor: ");
scanf("%f",&venda);
if (venda<0){
	printf("\nValor inválido! Venda ignorada.\n");
	continue;
	}
valor_total +=venda;
qnt_vendas+=1;

}
printf("\nValor total : %.2f R$",valor_total);
printf("\nQuantidade de vendas: %d",qnt_vendas);
if (qnt_vendas>0){
	printf("\nValor médio de vendas : %.2f R$",(valor_total/qnt_vendas));
	}else{
	printf("\nNenhuma venda realizada.");
	}

return 0;
}