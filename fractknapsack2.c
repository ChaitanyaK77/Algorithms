#include <stdio.h>
int M, n;
float x[20];
void knap(int m, int n);

struct item_information
{
    float weight;
    float profit;
    float PbyW;
};

struct item_information info[20];

struct item_information temp[20];

int main()
{
    printf("Enter knap weight\n");
    scanf("%d", &M);
    printf("Enter total items:\n");
    scanf("%d", &n);

    printf("Enter items' weight and profit respectively\n");
    for (int i = 0; i < n; i++)
    {
        printf("Enter Item %d weight and Profit:\n", i + 1);
        scanf("%f %f", &info[i].weight, &info[i].profit);
        info[i].PbyW = info[i].profit / info[i].weight;
    }

    for (int i = 0; i < n - 1; i++)
    {
        for (int j = 0; j < n - i - 1; j++)
        {
            if (info[j].PbyW < info[j + 1].PbyW)
            {
                temp[j] = info[j];
                info[j] = info[j + 1];
                info[j + 1] = temp[j];
            }
        }
    }
    for (int i = 0; i < n; i++)
    {
        printf("Enter Item\t Weight\t and Profit\tP/w:\n");
        printf("%d\t%.2f\t%.2f\t%.2f\n", i + 1, info[i].weight, info[i].profit, info[i].PbyW);
    }
    knap(M, n);
    return (0);
}
void knap(int m, int n)
{
    int i, Prof = 0;
    for (int i = 0; i < n; i++)
    {
        x[i] = 0;
    }
    int rem = m;
    for (i = 0; i < n; i++)
    {
        if (info[i].weight > rem)
            break;
        x[i] = 1;
        rem -= info[i].weight;
    }
    if (i <= n)
    {
        x[i] = rem / info[i].weight;
    }
    printf("Solution Vector is as follows:\n");
    for (int j = 0; j < n; j++)
    {
        printf("{%.2f\t}", x[j]);
    }
    for (int j = 0; j < n; j++)
    {
        Prof += info[j].profit * x[j];
    }
    printf("Total Profit = %d\n", Prof);
}
