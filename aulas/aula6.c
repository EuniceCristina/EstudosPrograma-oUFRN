#include <stdio.h>

int main(){


for (int l = 1 ;l<=5;l++){
	printf("\n\nTabuada do  %d",l);
	
	for (int c = 1;c<=10;c++){
		printf("\n%d x %d = %d",l,c,l*c);

	}
}
return 0;
}