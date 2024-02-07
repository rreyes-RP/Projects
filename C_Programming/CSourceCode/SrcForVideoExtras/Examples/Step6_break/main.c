#include <stdio.h>

int main(int argc, char **argv) {
	int i;
	i = 0;
	while( i < 10 ) {
		if( i == 5 ) {
			break;
		}
		printf("i = %d\n", i);
		i++;
	}
	return 0;
}
