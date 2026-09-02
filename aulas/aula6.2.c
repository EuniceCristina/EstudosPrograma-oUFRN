#include <stdio.h>

int main(){

int senha = 3565;
int emergencia = 9999;
int tentativas = 0;


while (tentativas>=0) {
	int aposta;
	printf("\nDigite sua %d° tentativa : ",tentativas);
	scanf("%d",&aposta);
	
	if (aposta==senha){
		printf("\nVocê acertou, parabéns");
		break;
	} else if (tentativas==2){
		printf("\nFim de jogo! Você perdeu.");
		break;
	} else if (aposta==emergencia){
		printf("Você digitou um código de emergência! Iremos pedir ajuda.");
		break;
	}
	
	tentativas++;
}
return 0;
}