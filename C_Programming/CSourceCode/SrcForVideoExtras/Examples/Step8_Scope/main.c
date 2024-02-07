#include <stdio.h>

// int num; // uncomment this

void func1(){
	int num;
	num = 100;
	printf("%d\n", num);
}

void func2(){
	num = 200; 	// This is an error!
	printf("%d\n", num);
}


int main(int argc, char **argv) {
	func1();
	func2();
	return 0;
}
