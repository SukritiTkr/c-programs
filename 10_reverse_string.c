#include <stdio.h>
#include <string.h>

// recursion method
void reverseRec(char str[], int start, int end) {
    if (start >= end)
        return;
    char temp = str[start];
    str[start] = str[end];
    str[end] = temp;
    reverseRec(str, start + 1, end - 1);
}

int main() {
    char str[100], rev[100], temp;
    int i, len, choice;

    printf("Enter string: ");
    fgets(str, sizeof(str), stdin);
    str[strcspn(str, "\n")] = 0;  // remove trailing newline

    printf("\nChoose method to reverse:\n");
    printf("1. Using second array\n");
    printf("2. In place swap\n");
    printf("3. Recursion\n");
    printf("Enter choice (1-3): ");
    scanf("%d", &choice);

    len = strlen(str);

    switch(choice) {
        case 1:  // using another array
            for(i = 0; i < len; i++)
                rev[i] = str[len - i - 1];
            rev[len] = '\0';
            printf("\nReversed (Method 1): %s\n", rev);
            break;

        case 2:  // in-place swap
            for(i = 0; i < len / 2; i++) {
                temp = str[i];
                str[i] = str[len - i - 1];
                str[len - i - 1] = temp;
            }
            printf("\nReversed (Method 2): %s\n", str);
            break;

        case 3:  // recursion
            reverseRec(str, 0, len - 1);
            printf("\nReversed (Method 3): %s\n", str);
            break;

        default:
            printf("Invalid choice.\n");
    }

    return 0;
}


/* 
to compile and run this program:

gcc 10_reverse_string.c -o reverse.exe
./reverse.exe
*/

