#include <stdio.h>

int main() {
    int n, i, num, largest;

    // method 1: using loop and variable
    printf("Enter 10 numbers:\n");
    scanf("%d", &largest);
    for(i = 1; i < 10; i++) {
        scanf("%d", &num);
        if(num > largest)
            largest = num;
    }
    printf("(using loop + variable) Largest = %d\n", largest);


    // method 2: using array
    int arr[10];
    printf("\nEnter 10 numbers again:\n\n");
    for(i = 0; i < 10; i++)
        scanf("%d", &arr[i]);

    largest = arr[0];
    for(i = 1; i < 10; i++) {
        if(arr[i] > largest)
            largest = arr[i];
    }
    printf("\n(using array) Largest = %d\n\n", largest);


    // method 3: using array + ternary
    printf("Enter 10 numbers again:\n");
    for(i = 0; i < 10; i++)
        scanf("%d", &arr[i]);

    largest = arr[0];
    for(i = 1; i < 10; i++)
        largest = (arr[i] > largest) ? arr[i] : largest;

    printf("(using array + ternary) Largest = %d\n", largest);

    return 0;
}


/* 
to compile and run this program:

gcc 03_largest_ten.c -o largest10.exe
./largest10.exe
*/