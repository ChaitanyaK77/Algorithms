#include <stdio.h>
#include <stdlib.h>
int n, x[20], count = 1, soln;
void NQ(int k, int n);
int place(int k, int i);
void printsoln();

int main()
{
    printf("Enter total queens:\n");
    scanf("%d", &n);
    NQ(1, n);
    return (0);
}
int place(int k, int i)
{
    for (int j = 1; j <= k - 1; j++)
    {
        if ((x[j] == i) || (abs(x[j] - i) == abs(j - k)))
            return 0;
    }
    return (1);
}
void printsoln()
{
    printf("SOLUTION %d", soln);
    for (int i = 1; i <= n; i++)
    {
        printf("\n");
        for (int j = 1; j <= n; j++)
        {
            if (x[i] == j)
            {
                printf("Q\t");
            }
            else
            {
                printf("-\t");
            }
        }
    }
}
void NQ(int k, int n)
{
    count++;
    for (int i = 1; i <= n; i++)
    {
        if (place(k, i))
        {
            x[k] = i;
            if (k == n)
            {
                soln++;
                printsoln();
                printf("\n\n");
                for (int i = 1; i <= n; i++)
                {
                    printf("%d\t", x[i]);
                }
                printf("\n");
            }
            else
            {
                NQ(k + 1, n);
            }
        }
    }
}