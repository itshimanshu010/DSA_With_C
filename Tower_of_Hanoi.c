#include<stdio.h>

void tower(int n, char first_rod, char last_rod,
                  char ex_rod)
{
    if (n == 0) {
        return;
    }
    tower(n-1, first_rod, ex_rod, last_rod);
    printf("Move disk %d from rod %c to rod %c \n",n,first_rod,last_rod);
    tower(n-1, ex_rod, last_rod, first_rod);
}
  

int main()
{
    int n ;
    printf("Enter number of disk :");
    scanf("%d",&n);
    tower(n, 'A', 'C', 'B');
    return 0;
}
