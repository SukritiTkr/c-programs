#include <stdio.h>
#include <string.h>

int main() {
    FILE *fp;
    char data[200];
    int choice;

    printf("Choose file operation method:\n");
    printf("1. Write and Read using fputs() / fgets()\n");
    printf("2. Write and Read using fprintf() / fscanf()\n");
    printf("3. Write and Read character-by-character using fputc() / fgetc()\n");
    printf("Enter choice (1-3): ");
    scanf("%d", &choice);
    getchar(); // clear input buffer

    switch(choice) {
        case 1:
            fp = fopen("sample.txt", "w");
            printf("\nEnter text to write: ");
            fgets(data, sizeof(data), stdin);
            data[strcspn(data, "\n")] = 0;  // remove newline
            fputs(data, fp);
            fclose(fp);

            fp = fopen("sample.txt", "r");
            printf("\nData in file:\n");
            while(fgets(data, sizeof(data), fp))
                printf("%s\n", data);  // print each line
            fclose(fp);

            fp = fopen("sample.txt", "a");
            printf("\nEnter text to append: ");
            fgets(data, sizeof(data), stdin);
            data[strcspn(data, "\n")] = 0;
            fputs(data, fp);
            fclose(fp);
            break;

        case 2:
            fp = fopen("sample.txt", "w");
            printf("\nEnter text to write: ");
            fgets(data, sizeof(data), stdin);
            data[strcspn(data, "\n")] = 0;
            fprintf(fp, "%s", data);
            fclose(fp);

            fp = fopen("sample.txt", "r");
            printf("\nData in file:\n");
            while(fscanf(fp, " %[^\n]", data) != EOF)  // space before %[^\n] skips leftover newline
                printf("%s\n", data);
            fclose(fp);

            fp = fopen("sample.txt", "a");
            printf("\nEnter text to append: ");
            fgets(data, sizeof(data), stdin);
            data[strcspn(data, "\n")] = 0;
            fprintf(fp, "%s", data);
            fclose(fp);
            break;

        case 3:
            fp = fopen("sample.txt", "w");
            printf("\nEnter text to write: ");
            fgets(data, sizeof(data), stdin);
            data[strcspn(data, "\n")] = 0;
            for(int i = 0; data[i] != '\0'; i++)
                fputc(data[i], fp);
            fclose(fp);

            fp = fopen("sample.txt", "r");
            printf("\nData in file:\n");
            char ch;
            while((ch = fgetc(fp)) != EOF)
                putchar(ch);
            fclose(fp);

            fp = fopen("sample.txt", "a");
            printf("\nEnter text to append: ");
            fgets(data, sizeof(data), stdin);
            data[strcspn(data, "\n")] = 0;
            for(int i = 0; data[i] != '\0'; i++)
                fputc(data[i], fp);
            fclose(fp);
            break;

        default:
            printf("Invalid choice.\n");
    }

    printf("\n\nFile updated successfully.\n");
    return 0;
}


/* 
to compile and run this program:

gcc 12_file_operations.c -o fileops.exe
./fileops.exe
*/
