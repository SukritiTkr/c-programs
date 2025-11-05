#include <stdio.h>

// function to multiply two matrices
void multiply(int a[10][10], int b[10][10], int c[10][10], int m, int n, int p, int q) {
    int i, j, k;
    for(i = 0; i < m; i++)
        for(j = 0; j < q; j++) {
            c[i][j] = 0;
            for(k = 0; k < n; k++)
                c[i][j] += a[i][k] * b[k][j];
        }
}

int main() {
    int a[10][10], b[10][10], c[10][10];
    int m, n, p, q, i, j;

    printf("Enter size of matrix A: ");
    scanf("%d %d", &m, &n);
    printf("Enter size of matrix B: ");
    scanf("%d %d", &p, &q);

    if(n != p) {
        printf("Matrix multiplication not possible.\n");
        return 0;
    }

    printf("Enter elements of A:\n");
    for(i = 0; i < m; i++)
        for(j = 0; j < n; j++)
            scanf("%d", &a[i][j]);

    printf("Enter elements of B:\n");
    for(i = 0; i < p; i++)
        for(j = 0; j < q; j++)
            scanf("%d", &b[i][j]);

    // Method 1: using nested loops directly
    for(i = 0; i < m; i++)
        for(j = 0; j < q; j++) {
            c[i][j] = 0;
            for(int k = 0; k < n; k++)
                c[i][j] += a[i][k] * b[k][j];
        }
    printf("\n(using nested loops)\n");
    for(i = 0; i < m; i++) {
        for(j = 0; j < q; j++)
            printf("%d ", c[i][j]);
        printf("\n");
    }

    // Method 2: using function
    multiply(a, b, c, m, n, p, q);
    printf("\n(using function)\n");
    for(i = 0; i < m; i++) {
        for(j = 0; j < q; j++)
            printf("%d ", c[i][j]);
        printf("\n");
    }

    return 0;
}


/* 
to compile and run this program:

gcc 07_matrix_multiply.c -o matrix.exe
./matrix.exe
*/
