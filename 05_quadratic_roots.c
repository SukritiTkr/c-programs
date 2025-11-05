#include <stdio.h>
#include <math.h>

int main() {
    float a, b, c, d, r1, r2, real, imag;

    printf("Enter coefficients a, b, c: ");
    scanf("%f %f %f", &a, &b, &c);

    d = b*b - 4*a*c;

    // method 1: using if-else ladder
    if(d > 0) {
        r1 = (-b + sqrt(d)) / (2*a);
        r2 = (-b - sqrt(d)) / (2*a);
        printf("(using if-else) Roots are real and different: %.2f , %.2f\n", r1, r2);
    } 
    else if(d == 0) {
        r1 = -b / (2*a);
        printf("(using if-else) Roots are real and equal: %.2f\n", r1);
    } 
    else {
        real = -b / (2*a);
        imag = sqrt(-d) / (2*a);
        printf("(using if-else) Roots are imaginary: %.2f + %.2fi , %.2f - %.2fi\n", real, imag, real, imag);
    }

    // method 2: using switch on condition type
    int type;
    if(d > 0)
        type = 1;
    else if(d == 0)
        type = 2;
    else
        type = 3;

    switch(type) {
        case 1:
            r1 = (-b + sqrt(d)) / (2*a);
            r2 = (-b - sqrt(d)) / (2*a);
            printf("(using switch) Roots are real and different: %.2f , %.2f\n", r1, r2);
            break;
        case 2:
            r1 = -b / (2*a);
            printf("(using switch) Roots are real and equal: %.2f\n", r1);
            break;
        case 3:
            real = -b / (2*a);
            imag = sqrt(-d) / (2*a);
            printf("(using switch) Roots are imaginary: %.2f + %.2fi , %.2f - %.2fi\n", real, imag, real, imag);
            break;
        default:
            printf("Invalid case");
    }

    // method 3: using ternary (only to show type of roots)
    (d > 0) ? printf("(using ternary) Roots are real and distinct\n") :
    (d == 0) ? printf("(using ternary) Roots are real and equal\n") :
    printf("(using ternary) Roots are imaginary\n");

    return 0;
}


/* 
to compile and run this program:

gcc 05_quadratic_roots.c -o quadratic.exe
./quadratic.exe
*/
