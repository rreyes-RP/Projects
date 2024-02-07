#include <stdio.h>

char *chartype;

void findchartype( int i ) {
	if (i == 0) {
		chartype = "NULL";
	} else if (i == 7) {
		chartype = "Bell";
	} else if (i == 8) {
		chartype = "BackSpace";
	} else if (i == 9) {
		chartype = "Tab";
	} else if (i == 10) {
		chartype = "LineFeed";
	} else if (i == 13) {
		chartype = "Carriage Return";
	} else if (i == 32) {
		chartype = "Space";
	} else if ((i >= 48) && (i <= 57 )) {
		chartype = "Number";
	} else {
		chartype = "Character";
	}	
}

void showascii() {
	int i;
	char c;
	for( i = 0; i <= 127; i++) {
		findchartype( i );
		printf("%d = %c\t\t[%s]\n", i, i, chartype);
	}
}

int main(int argc, char **argv) {
	showascii();
	return 0;
}
