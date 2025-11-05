#include <stdio.h>

int main() {
    int a[100], n, i, j, temp;

    printf("Enter number of elements: ");
    scanf("%d", &n);
    printf("Enter all the elements: ");

    for(i = 0; i < n; i++)
        scanf("%d", &a[i]);

    // Method 1: using Bubble Sort
    for(i = 0; i < n - 1; i++)
        for(j = 0; j < n - i - 1; j++)
            if(a[j] > a[j + 1]) {
                temp = a[j];
                a[j] = a[j + 1];
                a[j + 1] = temp;
            }

    printf("(using bubble sort)\n");
    for(i = 0; i < n; i++)
        printf("%d ", a[i]);
    printf("\n");

    // Method 2: using Selection Sort
    int min;
    for(i = 0; i < n - 1; i++) {
        min = i;
        for(j = i + 1; j < n; j++)
            if(a[j] < a[min])
                min = j;

        if(min != i) {
            temp = a[i];
            a[i] = a[min];
            a[min] = temp;
        }
    }

    printf("(using selection sort)\n");
    for(i = 0; i < n; i++)
        printf("%d ", a[i]);

    return 0;
}


/* 
to compile and run this program:

gcc 08_sort_numbers.c -o sort.exe
./sort.exe
*/
