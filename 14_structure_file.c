#include <stdio.h>
#include <string.h>

struct Student {
    int roll;
    char name[50];
    float marks;
};

int main() {
    FILE *fp;
    struct Student s;
    int choice;

    do {
        printf("\n1. Write record\n2. Read records\n3. Update record\n4. Exit\n");
        printf("Enter choice: ");
        scanf("%d", &choice);
        getchar();

        switch(choice) {
            case 1:
                fp = fopen("student.dat", "a");
                printf("Enter Roll No: ");
                scanf("%d", &s.roll);
                getchar();
                printf("Enter Name: ");
                gets(s.name);
                printf("Enter Marks: ");
                scanf("%f", &s.marks);
                fwrite(&s, sizeof(s), 1, fp);
                fclose(fp);
                printf("Record saved.\n");
                break;

            case 2:
                fp = fopen("student.dat", "r");
                printf("\nRecords in file:\n");
                while(fread(&s, sizeof(s), 1, fp))
                    printf("Roll: %d | Name: %s | Marks: %.2f\n", s.roll, s.name, s.marks);
                fclose(fp);
                break;

            case 3:
                {
                    FILE *temp;
                    int roll, found = 0;
                    fp = fopen("student.dat", "r");
                    temp = fopen("temp.dat", "w");
                    printf("Enter roll no to update: ");
                    scanf("%d", &roll);

                    while(fread(&s, sizeof(s), 1, fp)) {
                        if(s.roll == roll) {
                            found = 1;
                            printf("Enter new name: ");
                            getchar();
                            gets(s.name);
                            printf("Enter new marks: ");
                            scanf("%f", &s.marks);
                        }
                        fwrite(&s, sizeof(s), 1, temp);
                    }
                    fclose(fp);
                    fclose(temp);
                    remove("student.dat");
                    rename("temp.dat", "student.dat");
                    if(found)
                        printf("Record updated successfully.\n");
                    else
                        printf("Record not found.\n");
                }
                break;

            case 4:
                printf("Exiting...\n");
                break;

            default:
                printf("Invalid choice.\n");
        }
    } while(choice != 4);

    return 0;
}


/* 
to compile and run this program:

gcc 14_structure_file.c -o struct.exe
./struct.exe
*/
