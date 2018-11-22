// コンパイルはcc Prime.c -lm

#include <stdio.h>
#include <math.h>

int main(void) {
	int i, j, k;
	int input;
	printf("Input number -> ");
	scanf("%d", &input);
	printf("2\t");
	
	for(i = 3; i < input; i += 2) {
		k = 0;
		for(j = 3; j <= sqrt(i); j += 2) {
			if(i % j == 0) {
				k = 1;
				break;
			}
		}
		if(k == 0) printf("%d\t", i);
	}
	printf("\n");
	return 0;
}
