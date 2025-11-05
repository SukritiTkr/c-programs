#include <stdio.h>

int main() {
    int a[50], n, i, largest, second, temp;

    printf("Enter number of elements: ");
    scanf("%d", &n);

    printf("Enter all the elements: ");
    for(i = 0; i < n; i++)
        scanf("%d", &a[i]);


    // Method 1: using only if
    largest = a[0];
    second = a[1];
    if(second > largest) {
        temp = largest;
        largest = second;
        second = temp;
    }

    for(i = 2; i < n; i++) {
        if(a[i] > largest) {
            second = largest;
            largest = a[i];
        } else if(a[i] > second && a[i] < largest)
            second = a[i];
    }
    printf("(using only if) Largest = %d, Second Largest = %d\n", largest, second);

    // Method 2: using sorting (bubble sort)
    for(i = 0; i < n - 1; i++) {
        for(int j = 0; j < n - i - 1; j++) {
            if(a[j] > a[j + 1]) {
                temp = a[j];
                a[j] = a[j + 1];
                a[j + 1] = temp;
            }
        }
    }
    printf("(using sorting) Largest = %d, Second Largest = %d\n", a[n - 1], a[n - 2]);

    return 0;
}


/* 
to compile and run this program:

gcc 06_second_largest.c -o secondlargest.exe
./secondlargest.exe
*/
