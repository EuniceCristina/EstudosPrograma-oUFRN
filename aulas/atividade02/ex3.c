#include <stdio.h>

int main(){

int N, pacientesFebre=0;
float temperatura, temperaturaMedia=0, maiorTemperatura,menorTemperatura;

printf("Digite a quantidade de temperaturas que deseja medir: ");
scanf("%d",&N);


for (int i=N;i>0;i--){
	printf("\nTemperatura : ");
	scanf("%f",&temperatura);
	
	if (temperatura<30){
		printf("\nTemperatura inválida! Ignorando");
		i++;
		continue;
	} 
	if (i==N){
		maiorTemperatura = temperatura;
		menorTemperatura = temperatura;
	} else {
		if (temperatura>maiorTemperatura){
			maiorTemperatura = temperatura;
		}
		if (temperatura<menorTemperatura){
			menorTemperatura = temperatura;
		} 
	}
	temperaturaMedia += temperatura;
	float febre = 37.5;
	if (temperatura>=febre){
		pacientesFebre+=1;
	}

}

printf("\n\nRelátorio de medições : ");
printf("\nMédia : %.2f",(temperaturaMedia/N));
printf("\nMaior : %.2f",maiorTemperatura);
printf("\nMenor : %.2f", menorTemperatura);
printf("\nPacientes com febre : %d",pacientesFebre);
return 0;
}