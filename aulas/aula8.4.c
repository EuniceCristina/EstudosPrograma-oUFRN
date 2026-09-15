#include <stdio.h>
#include <string.h>

int main(){
char *caminho;
char url[20];

printf("\nDigite sua url: ");
scanf("%s",&url);

char *tent = strstr(url,"https");

if (tent){
	printf("\nSeguro");
	char *caminho = strtok(url,"/");
	caminho = strtok(NULL,"/");

	printf("\nDomínio principal: %s",caminho);
}


return 0;

}
