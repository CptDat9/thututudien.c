
#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
 
unsigned long gt[13];
 
void tinhgt() {
    gt[0] = 1;
    for (unsigned long i = 1; i < 13; i++)
        gt[i] = gt[i - 1] * i;
}
 
unsigned long thutu(int* a, int n) {
    unsigned long s = 0, i, j, k;
    for (i = 1; i <= n; i++) {
        j = 0;
        for (k = i + 1; k <= n; k++)
            if (a[k] < a[i]) j++;
        s += gt[n - i] * j;
    }
    return s + 1;
}
 
int* timday(unsigned long s, int n) {
    int* a = (int*)malloc(sizeof(int) * (n + 1));
    int* cx = (int*)malloc(sizeof(int) * (n + 1));
    int i, j, t;
    for (i = 1; i <= n; i++) cx[i] = 1;
    for (i = 1; i <= n; i++) {
        t = (s - 1) / gt[n - i] + 1;
        for (j = 1; j <= n; j++)
            if (cx[j]) {
                t--;
                if (t == 0) {
                    a[i] = j;
                    cx[j] = 0;
                    break;
                }
            }
        s = (s - 1) % gt[n - i] + 1;
    }
    return a;
}
 
void main() {
    tinhgt();
    clrscr();
 
    int i, n, a[13];
 
    printf("Nhap so nguyen duong <= 12, n = ");
    scanf("%d", &n);
    printf("\nCau a:\n");
    for (i = 1; i <= n; i++) {
        printf("Nhap a[%d] = ", i);
        scanf("%d", &a[i]);
    }
    printf("Ket qua = %lu", thutu(a, n));
 
    unsigned long s;
    printf("\n\nCau b:\n");
    printf("Nhap so nguyen duong <= %lu, s = ", gt[n]);
    scanf("%lu", &s);
    printf("Ket qua: ");
    int* b;
    b = timday(s, n);
    for (i = 1; i <= n; i++)
        printf("%d ", b[i]);
 
    getch();
}
