#include <stdio.h>
#define INF 999
int adj[20][20], v, P[20][20], D[20][20];
void getadj();
void MakeD(int a[20][20]);
void MakeP(int a[20][20]);
void FloydWarshall();
void PrintPath(int a, int b);
int main()
{
    getadj();
    MakeD(adj);
    MakeP(adj);
    FloydWarshall();
    for (int i = 0; i < v; i++)
    {
        for (int j = 0; j < v; j++)
        {

            if (i == j)
            {
                continue;
            }
            printf("Path from %d to %d is ", i, j);
            PrintPath(i, j);
            printf("\n");
        }
    }
    return (0);
}
void getadj()
{
    printf("Enter total number of vertices:\n");
    scanf("%d", &v);
    printf("Enter the adjacency matrix for the graph:\n");
    for (int i = 0; i < v; i++)
    {
        for (int j = 0; j < v; j++)
        {
            scanf("%d", &adj[i][j]);
        }
    }
}

void MakeD(int a[20][20])
{
    for (int i = 0; i < v; i++)
    {
        for (int j = 0; j < v; j++)
        {
            if (i != j)
            {
                D[i][j] = adj[i][j];
                if (D[i][j] == 0)
                {
                    D[i][j] = INF;
                }
            }
        }
    }
    printf("The current D matrix is :\n");
    for (int i = 0; i < v; i++)
    {
        for (int j = 0; j < v; j++)
        {
            printf("%d\t", D[i][j]);
        }
        printf("\n");
    }
}
void MakeP(int a[20][20])
{
    for (int i = 0; i < v; i++)
    {
        for (int j = 0; j < v; j++)
        {
            P[i][j] = adj[i][j];
            if (P[i][j] == 0)
            {
                P[i][j] = -1;
            }
            else
            {
                P[i][j] = i;
            }
        }
    }
    printf("The current P matrix is :\n");
    for (int i = 0; i < v; i++)
    {
        for (int j = 0; j < v; j++)
        {
            printf("%d\t", P[i][j]);
        }
        printf("\n");
    }
}
void FloydWarshall()
{
    for (int k = 0; k < v; k++)
    {
        for (int i = 0; i < v; i++)
        {
            for (int j = 0; j < v; j++)
            {
                if (D[i][j] <= D[i][k] + D[k][j])
                {
                    continue;
                }
                else
                {
                    D[i][j] = D[i][k] + D[k][j];
                    P[i][j] = P[k][j];
                }
            }
        }
    }
}
void PrintPath(int a, int b)
{
    if (b == a)
    {
        printf(" %d ", a);
    }
    else if (P[a][b] == -1)
    {
        printf("No path Exists\n");
    }
    else
    {
        PrintPath(a, P[a][b]);
        printf("--->");
        printf(" %d ", b);
    }
}
