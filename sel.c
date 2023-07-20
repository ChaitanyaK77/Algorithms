#include <stdio.h>
int array[10], n;
void get_array();
void select_sort(int a[]);
int main()
{
    printf("This program will perform selection sort algorithm\n");

    get_array();
    select_sort(array);
    return (0);
}
void get_array()
{
    printf("Enter total number of elements in the array:\n");
    scanf("%d", &n);
    printf("Enter array elemnts:\n");
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &array[i]);
    }
}
void select_sort(int arr[])
{
    for (int i = 0; i < n; i++)
    {
        int j;
        j = i;
        for (int k = i + 1; k < n; k++)
        {
            if (arr[k] < arr[j])
                j = k;
        }
        int temp = arr[i];
        arr[i] = arr[j];
        arr[j] = temp;
        printf("After %d pass,array becomes:\n", i + 1);
        for (int w = 0; w < n; w++)
        {
            printf("%d\t", arr[w]);
        }
        printf("\n");
    }
    printf("Sorted array is as follows:\n");
    for (int i = 0; i < n; i++)
    {
        printf("%d ", arr[i]);
    }
}