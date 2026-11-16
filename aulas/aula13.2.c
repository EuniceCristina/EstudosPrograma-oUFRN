#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main(){
int x1;
int x2;
int y1;
int y2;

printf("\nDigite x1: ");
scanf("%d",&x1);

printf("\nDigite y1: ");
scanf("%d",&y1);

printf("\nDigite x2: ");
scanf("%d",&x2);

printf("\nDigite y2: ");
scanf("%d",&y2);

int deltaX = abs(x2-x1);
int deltaY = abs(y2-y1);
float D = pow(deltaX, 2) + pow(deltaY, 2);
float d = sqrt(D);

printf("\nA distância Euclidiana final é de : %.2f",d);

return 0;
}