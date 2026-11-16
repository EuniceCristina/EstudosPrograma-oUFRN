#include <stdio.h>
#include <stdlib.h>

int main() {

	int *p;
	int n = 5;
	
	p= (int *) malloc(n * sizeof(int));
	if (p==NULL) {
		printf("Falha ao alocar na memória\n");
		return 1;

	}

	for (int i=0; i<n;i++){
		p[i] = (i+1) * 10;
		printf("%.2f\n",p[i]);
	}
	free(p);
	return 0;

}