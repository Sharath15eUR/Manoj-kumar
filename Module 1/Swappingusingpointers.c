#include <stdio.h>

void swap(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

int main() {
    int num1, num2;
    printf("Enter two numbers: ");
    scanf("%d %d", &num1, &num2);

    void (*swapPtr)(int *, int *) = &swap;

    (*swapPtr)(&num1, &num2);

    printf("After swapping: %d %d\n", num1, num2);

    return 0;
}

