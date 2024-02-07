#include <stdio.h>

int main(int argc, char **argv) {
    double subTotal;
    double tax;
    double grandTotal;
    double taxRate;

    taxRate = 0.175;
    subTotal = 200;
    tax = subTotal * taxRate;
    grandTotal = subTotal + tax;

    printf("The tax on %.2f is %.2f, so the grand total is %.2f. \n", subTotal, tax, grandTotal );

    return 0;
}