#include <stdio.h>

int main(int argc, char **argv) {
	char agestring[10];
	int age;
	int bonus;

	printf("Enter your age : ");
	gets(agestring);
	age = atoi(agestring);
	if (age == 0) {
		printf("You entered an invalid age, so your bonus cannot be calculated.\n");
	} else {
		if (age > 45) {
			bonus = 1000;
		} else {
			bonus = 500;
		}
		printf("Your age is %d, so your bonus is %d.\n", age, bonus);
	}

	return(0);
}
