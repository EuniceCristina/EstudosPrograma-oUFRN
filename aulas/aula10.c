#include <stidio.h>

int main(){
int *v = (int *)malloc(5 * sizeof(int));

if (v == NULL) {

	printf("Erro ao alocar memória!"\n);
	return 1;

}

for (int i = 0; i < 5; i++) {

	v[i] = i*10;
}

free(v);
}