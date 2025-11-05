#include <stdio.h>

int main() {
    int n, i, gender;
    float height;
    float sumM = 0, sumF = 0;
    int countM = 0, countF = 0;
    float avgM, avgF;

    printf("Enter number of students: ");
    scanf("%d", &n);

    for(i = 0; i < n; i++) {
        printf("Enter gender (1=Male, 2=Female) and height: ");
        scanf("%d %f", &gender, &height);

        if(gender == 1) {
            sumM += height;
            countM++;
        } else if(gender == 2) {
            sumF += height;
            countF++;
        } else {
            printf("Invalid gender! Skipping entry.\n");
        }
    }

    // Method 1: Simple if
    if(countM > 0)
        avgM = sumM / countM;
    else
        avgM = 0;

    if(countF > 0)
        avgF = sumF / countF;
    else
        avgF = 0;

    printf("\n(using if) Average male height: %.2f\n", avgM);
    printf("(using if) Average female height: %.2f\n", avgF);

    // Method 2: Using conditional (?:) operator
    avgM = (countM > 0) ? (sumM / countM) : 0;
    avgF = (countF > 0) ? (sumF / countF) : 0;

    printf("\n(using ternary) Average male height: %.2f\n", avgM);
    printf("(using ternary) Average female height: %.2f\n", avgF);

    return 0;
}


/* 
to compile and run this program:

gcc 04_avg_height.c -o avgheight.exe
./avgheight.exe
*/
