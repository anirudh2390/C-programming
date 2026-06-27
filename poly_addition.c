#include <stdio.h>

struct Polynomial {
    int coeff;
    int expo;
};

int main() {
    struct Polynomial p1[10], p2[10], p3[20];
    int t1, t2, i = 0, j = 0, k = 0;

    printf("Enter the number of terms in Polynomial 1: ");
    scanf("%d", &t1);
    printf("Enter coefficients and exponents for Poly 1 (descending order of exponents):\n");
    for (i = 0; i < t1; i++) {
        scanf("%d %d", &p1[i].coeff, &p1[i].expo);
    }

    printf("Enter the number of terms in Polynomial 2: ");
    scanf("%d", &t2);
    printf("Enter coefficients and exponents for Poly 2 (descending order of exponents):\n");
    for (i = 0; i < t2; i++) {
        scanf("%d %d", &p2[i].coeff, &p2[i].expo);
    }

    i = 0;
    while (i < t1 && j < t2) {
        if (p1[i].expo == p2[j].expo) {
            p3[k].coeff = p1[i].coeff + p2[j].coeff;
            p3[k].expo = p1[i].expo;
            i++; j++; k++;
        } else if (p1[i].expo > p2[j].expo) {
            p3[k] = p1[i];
            i++; k++;
        } else {
            p3[k] = p2[j];
            j++; k++;
        }
    }

    while (i < t1) { p3[k++] = p1[i++]; }
    while (j < t2) { p3[k++] = p2[j++]; }

    printf("\nResultant Polynomial:\n");
    for (i = 0; i < k; i++) {
        printf("%dx^%d", p3[i].coeff, p3[i].expo);
        if (i < k - 1) printf(" + ");
    }
    printf("\n");
    return 0;
}