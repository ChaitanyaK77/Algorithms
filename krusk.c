#include <stdio.h>
int adj[20][20], v, temparr[20][20], count, cost;
int p[20], r[20];
void get_adj();
void put_adj();
void edge();
void makeset(int x);
void link(int x, int y);
int findset(int x);
void union1(int x, int y);
int main()
{
    printf("Enter total number of vertices:\n");
    scanf("%d", &v);
    get_adj();
    for (int i = 0; i < v; i++)
    {
        makeset(i);
    }
    put_adj();
    edge();

    for (int i = 0; i < count; i++)
    {
        if (findset(temparr[i][0]) != findset(temparr[i][1]))
        {
            union1(temparr[i][0], temparr[i][1]);
            cost += temparr[i][2];
            printf("EDGE %d  (%d,%d)=>%d\n", i + 1, temparr[i][0], temparr[i][1], temparr[i][2]);
        }
    }
    printf("\n\nTotal cost on minspantree = %d\n", cost);
    return (0);
}
void get_adj()
{
    printf("Enter the upper tr matrix:\n");
    for (int i = 0; i < v; i++)
    {
        for (int j = 0; j < v; j++)
        {
            if (i == j)
            {
                adj[i][j] = 0;
            }
        }
    }
    for (int i = 0; i < v; i++)
    {
        for (int j = 0; j < v; j++)
        {
            if (i < j)
            {
                scanf("%d", &adj[i][j]);
            }
        }
    }
    for (int i = 0; i < v; i++)
    {
        for (int j = 0; j < v; j++)
        {
            adj[j][i] = adj[i][j];
        }
    }
}
void put_adj()
{
    printf("The adjacency matrix is as follows:\n");
    for (int i = 0; i < v; i++)
    {
        for (int j = 0; j < v; j++)
        {
            printf("%d\t", adj[i][j]);
        }
        printf("\n");
    }
    for (int i = 0; i < v; i++)
    {
        for (int j = 0; j < v; j++)

            if (i < j && adj[i][j] != 0)
            {
                count++;
            }
    }
    printf("Total number of edges in the original graph = %d\n", count);
}
void edge()
{
    int temp = 0;
    for (int i = 0; i < v; i++)
    {
        for (int j = 0; j < v; j++)
        {
            if (i < j && adj[i][j] != 0)
            {
                temparr[temp][0] = i;
                temparr[temp][1] = j;
                temparr[temp][2] = adj[i][j];
                temp++;
            }
        }
    }
    for (int i = 0; i < count; i++)
    {

        printf("%d---->%d = %d\n", temparr[i][0], temparr[i][1], temparr[i][2]);
    }
    printf("After sorting,the edge table is as follows:\n");

    for (int i = 0; i < count - 1; i++)
    {
        for (int j = 0; j < count - i - 1; j++)
        {
            if (temparr[j][2] > temparr[j + 1][2])
            {
                int temp1 = temparr[j][0];
                temparr[j][0] = temparr[j + 1][0];
                temparr[j + 1][0] = temp1;
                temp1 = temparr[j][1];
                temparr[j][1] = temparr[j + 1][1];
                temparr[j + 1][1] = temp1;
                temp1 = temparr[j][2];
                temparr[j][2] = temparr[j + 1][2];
                temparr[j + 1][2] = temp1;
            }
        }
    }
    printf("\n");
    for (int i = 0; i < count; i++)
    {

        printf("%d---->%d = %d\n", temparr[i][0], temparr[i][1], temparr[i][2]);
    }
}
void makeset(int x)
{
    p[x] = x;
    r[x] = 0;
}
int findset(int x)
{
    if (p[x] != x)
    {
        p[x] = findset(p[x]);
    }
    return p[x];
}
void union1(int x, int y)
{
    link(findset(x), findset(y));
}
void link(int x, int y)
{
    if (r[x] > r[y])
    {
        p[y] = x;
    }
    else
    {
        p[x] = y;
        if (r[x] == r[y])
        {
            r[y]++;
        }
    }
}