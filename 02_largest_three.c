#include <stdio.h>

int main() {
    int a, b, c, max;

    printf("Enter three numbers: ");
    scanf("%d %d %d", &a, &b, &c);

    // method 1: using only if
    max = a;
    if(b > max)
        max = b;
    if(c > max)
        max = c;
    printf("(using only if) %d is largest\n", max);

    // method 2: using if else if
    if(a > b && a > c)
        printf("(using if else if) %d is largest\n", a);
    else if(b > c)
        printf("(using if else if) %d is largest\n", b);
    else
        printf("(using if else if) %d is largest\n", c);

    // method 3: using ternary operator
    max = (a > b && a > c) ? a : (b > c ? b : c);
    printf("(using ternary) %d is largest\n", max);

    return 0;
}


/* 
to compile and run this program:

gcc 02_largest_three.c -o largest3.exe
./largest3.exe
*/
