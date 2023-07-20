#include <stdio.h>
int X[20], W[20], M, n, sum;
void sos(int s, int k, int r);
int main()
{
    printf("Enter the total sum:\n");
    scanf("%d", &M);
    printf("Enter total elemnts:\n");
    scanf("%d", &n);
    printf("Enter the elem:\n");
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &W[i]);
    }
    for (int i = 0; i < n; i++)
    {
        sum += W[i];
    }
    sos(0, 0, sum);
    return (0);
}
void sos(int s, int k, int r)
{
    X[k] = 1;
    if (s + W[k] == M)
    {
        for (int i = 0; i < n; i++)
        {
            printf("%d\t", X[i]);
        }
        printf("\n");
    }
    else if (s + W[k] + W[k + 1] <= M)
    {
        sos(s + W[k], k + 1, r - W[k]);
    }
    if ((s + r - W[k] >= M) && (s + W[k + 1] <= M))
    {
        X[k] = 0;
        sos(s, k + 1, r - W[k]);
    }
}