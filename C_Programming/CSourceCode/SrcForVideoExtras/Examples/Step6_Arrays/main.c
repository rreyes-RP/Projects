#include <stdio.h>

int intarray[5];


int main(int argc, char **argv) {
	int i;
	
	intarray[0] = 1;
	intarray[1] = 11;
	intarray[2] = 21;
	intarray[3] = 31;
	intarray[4] = 41;

	for (i = 0; i < 5; i++) {
		printf("%d\n", intarray[i]);
	}
	printf( "The integer at intarray[3] is: %d\n", intarray[3]);
}
