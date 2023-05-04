#include<stdio.h>
int fibonacci(int n, int current, int next) {
    if (n == 0) {
        return current;
    } else {
        return fibonacci(n-1, next, current+next);
    }
}
int main()
{
    int n;
    printf("enter the number: ");
    scanf("%d",&n);
    int result=fibonacci(n,0,1);
    printf("the result is %d",result);
    return 0;

}
