#include <stdio.h>
#include <math.h>
char pattern[100], text[100];
int m, n, match = 0;
void Rabin_Karp(char t[], char p[], int d, int q);
int main()
{
    int d;
    printf("Enter the length of the text string:\n");
    scanf("%d", &n);
    printf("Enter the length of the pattern string:\n");
    scanf("%d", &m);
    printf("Enter the text string:\n");
    scanf("%s", text);
    printf("Enter Radix:\n");
    scanf("%d", &d);
    printf("Enter the pattern string:\n");
    scanf("%s", pattern);
    Rabin_Karp(text, pattern, d, 13);
    printf("Total number of matches:%d", match);
    return (0);
}

void Rabin_Karp(char t[], char p[], int d, int q)
{
    int h = 1;
    int P = 0, to = 0;
    for (int i = 0; i < m - 1; i++)
    {
        h = (h * d) % q;
    }

    for (int i = 0; i < m; i++)
    {
        P = (d * P + p[i]) % q;
        to = (d * to + t[i]) % q;
    }

    for (int s = 0; s < n - m + 1; s++)
    {
        if (P == to)
        {
            int j = 0;
            for (j = 0; j < m; j++)
            {
                if (t[s + j] != p[j])
                {
                    break;
                }
            }
            if (j == m)
            {
                printf("Pattern found at shift %d with hash value %d\n", s, h);
                match++;
            }
        }
        if (s < n - m)
        {
            to = (d * (to - t[s] * h) + t[s + m]) % q;
        }
        if (to < 0)
            to = (to + q);
    }
}