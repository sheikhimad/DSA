#include<stdio.h>

int fibo(int n)
{
    if(n==0)
        return 0;
    else if (n==1)
        return 1;
    else
        return fibo(n-1) + fibo(n-2);
}

int main()
{
    int t,i;
    printf("Enter the number of terms you want:");
    scanf("%d", &t);
    printf("\nFibonacci Series:");
    for(i=0;i<t;i++)
    {
        printf("%d ",fibo(i));
    }
    return 0;
}
