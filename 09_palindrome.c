#include <stdio.h>
#include <string.h>

// Safe strrev implementation
void my_strrev(char *str) {
    int i, len = strlen(str);
    for(i = 0; i < len / 2; i++) {
        char temp = str[i];
        str[i] = str[len - i - 1];
        str[len - i - 1] = temp;
    }
}

// METHOD 1: Using strrev
void palindrome_strrev() {
    char str[100], rev[100];
    printf("\n[Method 1: strrev()]\nEnter string: ");
    fgets(str, sizeof(str), stdin);
    str[strcspn(str, "\n")] = 0;  // remove newline

    strcpy(rev, str);
    my_strrev(rev);

    if(strcmp(str, rev) == 0)
        printf("Palindrome\n");
    else
        printf("Not palindrome\n");
}

// METHOD 2: Manual reverse and compare
void palindrome_manual() {
    char str[100], rev[100];
    int i, len;
    printf("\n[Method 2: Manual reverse]\nEnter string: ");
    fgets(str, sizeof(str), stdin);
    str[strcspn(str, "\n")] = 0;

    len = strlen(str);
    for(i = 0; i < len; i++)
        rev[i] = str[len - i - 1];
    rev[len] = '\0';

    if(strcmp(str, rev) == 0)
        printf("Palindrome\n");
    else
        printf("Not palindrome\n");
}

// METHOD 3: Using pointers
void palindrome_pointer() {
    char str[100];
    char *start, *end;
    int flag = 0;
    printf("\n[Method 3: Pointer method]\nEnter string: ");
    fgets(str, sizeof(str), stdin);
    str[strcspn(str, "\n")] = 0;

    start = str;
    end = str + strlen(str) - 1;

    while(start < end) {
        if(*start != *end) {
            flag = 1;
            break;
        }
        start++;
        end--;
    }

    if(flag == 0)
        printf("Palindrome\n");
    else
        printf("Not palindrome\n");
}

int main() {
    int choice;
    do {
        printf("\n--- PALINDROME CHECKER MENU ---\n");
        printf("1. Using strrev()\n");
        printf("2. Manual reverse\n");
        printf("3. Pointer method\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        getchar(); // consume newline left by scanf

        switch(choice) {
            case 1: palindrome_strrev(); break;
            case 2: palindrome_manual(); break;
            case 3: palindrome_pointer(); break;
            case 4: printf("Exiting...\n"); break;
            default: printf("Invalid choice!\n");
        }
    } while(choice != 4);

    return 0;
}


/* 
to compile and run this program:

gcc 09_palindrome.c -o palindrome.exe
./palindrome.exe
*/