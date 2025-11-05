#include <stdio.h>
#include <string.h>

int main() {
    char str1[200], str2[100];
    int i, j, choice;

    printf("Enter first string: ");
    fgets(str1, sizeof(str1), stdin);
    str1[strcspn(str1, "\n")] = 0;  // remove trailing newline

    printf("Enter second string: ");
    fgets(str2, sizeof(str2), stdin);
    str2[strcspn(str2, "\n")] = 0;

    printf("\nChoose method to concatenate:\n");
    printf("1. Using strcat()\n");
    printf("2. Using loop\n");
    printf("3. Using pointers\n");
    printf("Enter choice (1-3): ");
    scanf("%d", &choice);

    switch(choice) {
        case 1: // using strcat
            strcat(str1, str2);
            printf("\nConcatenated (Method 1): %s\n", str1);
            break;

        case 2: // using loop
            for(i = 0; str1[i] != '\0'; i++);
            for(j = 0; str2[j] != '\0'; j++, i++)
                str1[i] = str2[j];
            str1[i] = '\0';
            printf("\nConcatenated (Method 2): %s\n", str1);
            break;

        case 3: { // using pointers
            char *p1 = str1;
            char *p2 = str2;
            while(*p1) p1++;      // move to end of str1
            while(*p2) {
                *p1 = *p2;
                p1++;
                p2++;
            }
            *p1 = '\0';
            printf("\nConcatenated (Method 3): %s\n", str1);
            break;
        }

        default:
            printf("Invalid choice.\n");
    }

    return 0;
}


/* 
to compile and run this program:

gcc 11_concat_strings.c -o concat.exe
./concat.exe
*/
