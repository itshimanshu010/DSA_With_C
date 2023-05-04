#include <stdio.h>

int fib_tail(int n, int current, int next) {
    if (n == 0) {
        return current;
    } else {
        return fib_tail(n-1, next, current+next);
    }
}

int fibonacci(int n) {
    return fib_tail(n, 0, 1);
}

int main() {
    int n, i;
    printf("Enter the number of terms: ");
    scanf("%d", &n);
    printf("Fibonacci series:\n");
    for (i = 0; i < n; i++) {
        printf("%d, ", fibonacci(i));
    }
    return 0;
}
