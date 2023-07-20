#include <stdio.h>

int X[20], n, M, W[20], sum;
void selsort(int a[20]);
void SOS(int s, int k, int r);
int main()
{
    printf("Enter the total sum :\n");
    scanf("%d", &M);
    printf("Enter total no of elements:\n");
    scanf("%d", &n);
    printf("Enter the elemnts:\n");
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &W[i]);
    }
    selsort(W);
    for (int i = 0; i < n; i++)
    {
        sum += W[i];
    }
    SOS(0, 0, sum);
    return (0);
}
void selsort(int a[20])
{
    for (int i = 0; i < n; i++)
    {
        int j = i;
        for (int k = i + 1; k < n; k++)
        {
            if (a[k] < a[j])
            {
                j = k;
            }
        }
        int temp = a[i];
        a[i] = a[j];
        a[j] = temp;
    }
}

void SOS(int s, int k, int r)
{
    X[k] = 1;
    if (s + W[k] == M)
    {
        for (int i = 0; i < n; i++)
        {
            printf("%d", X[i]);
        }
        printf("\n");
    }
    else if (s + W[k] + W[k + 1] <= M)
    {
        SOS(s + W[k], k + 1, r - W[k]);
    }
    if ((s + r - W[k] >= M) && (s + W[k + 1] <= M))
    {
        X[k] = 0;
        SOS(s, k + 1, r - W[k]);
    }
}
