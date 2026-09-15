#include <stdio.h>


int main(){

int usu;

printf("\nDigite a quantidade de usuários a serem cadastrados: ");
scanf("%d",&usu);

if (usu>10){
	printf("\nO limite são 10 usuários.");
	return 0;
}
int matriz[usu][4];
for (int l=0;l<usu;l++){
	int id;
	printf("\nInformações do usuário %d. Digite ",l+1);
	printf("\nID: ");
	scanf("%d",&id);	
	int busca = 0;
	for (int i=0;i<usu;i++){
		if (matriz[i][0]==id)	{
		busca = 1;	
	}

	}
	if (busca==1){
		printf("\nUsuário já cadastrado");
		l--;
		continue;
	}
	matriz[l][0]=id;
	printf("\nIdade: ");
	scanf("%d",&matriz[l][1]);
	printf("\nNúmeros de dependentes: ");
	scanf("%d",&matriz[l][2]);
	printf("\nRenda mensal: ");
	scanf("%d",&matriz[l][3]);
}

int id_busca;
int busca = 0;
printf("\nDigite o ID do usuário que está buscando: ");
scanf("%d",&id_busca);

for (int i=0;i<usu;i++){
	if (matriz[i][0]==id_busca)	{
		busca = 1;	
}
}
if (busca==1){
	printf("\nUsuário encontrado.");
	printf("\nID : %d",matriz[id_busca][0]);
	printf("\nIdade: %d ",matriz[id_busca][1]);
	printf("\nNúmeros de dependentes: %d",matriz[id_busca][2]);
	printf("\nRenda mensal: %d",matriz[id_busca][3]);
} else{
	printf("\nUsuário não cadastrado");
}


return 0;

}
