#include <stdio.h>

int main() {
    FILE *fp;
    char text[200];

    fp = fopen("data.txt", "w");
    if(fp == NULL) {
        printf("Error opening file!");
        return 0;
    }

    printf("Enter text to write into file:\n");
    gets(text);
    fputs(text, fp);
    fclose(fp);

    printf("\nData written successfully.\n");

    // reading back
    fp = fopen("data.txt", "r");
    printf("Reading from file:\n");
    while(fgets(text, 200, fp))
        printf("%s", text);
    fclose(fp);

    return 0;
}


/* 
to compile and run this program:

gcc 13_create_file.c -o create.exe
./create.exe
*/
