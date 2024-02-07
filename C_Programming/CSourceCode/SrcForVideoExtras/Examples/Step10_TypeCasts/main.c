#include <stdio.h>

int main( int argc, char **argv ) {
	int x = 13;
	int y = 3;
	double result;
	result = (double) x / y;
	printf( "result=%f, %d", result, (int) result );
	return 0;
}
