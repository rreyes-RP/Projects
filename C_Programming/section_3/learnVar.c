#include <stdio.h>

int main(int argc, char **argv) {
    double pettyCash;
    double grandTotal = 500.50;

    //grandTotal = 500.50;
    pettyCash = 10.5;
    printf("pettyCash = %.2f\n", pettyCash);
    pettyCash = 100.25;
    printf("pettyCash = %.2f\n", pettyCash);
    printf("grandtotal = %.2f\n", grandTotal);
    return 0;
}