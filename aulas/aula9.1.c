#include <stdio.h>
#include <string.h>

enum StatusPedido {Pendente,Processando,Enviado,Entregue,Cancelado};

int main(){
enum StatusPedido pedido = Pendente;

pedido++;

switch (pedido){

case 0:
	printf("\nPedente");
	break;
case 1:
	printf("\nProcessando");
	break;

case 2:
	printf("\nEnviado");
	break;
case 3:
	printf("\nEntregue");
	break;
case 4:
	printf("\nCancelado");
	break;
}
return 0;
}


