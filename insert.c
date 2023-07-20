#include <stdio.h>
int array[10], n;
void get_array();
void insert_sort(int a[]);
int main()
{
    printf("This program will perform insert sort algorithm\n");

    get_array();
    insert_sort(array);
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
void insert_sort(int arr[])
{
    int key, i;
    for (int j = 1; j < n; j++)
    {
        key = arr[j];
        i = j - 1;
        while (i >= 0 && arr[i] > key)
        {
            arr[i + 1] = arr[i];
            i--;
        }
        arr[i + 1] = key;
        printf("After %d pass array is :\n", j);
        for (int k = 0; k < n; k++)
        {
            printf("%d\t", arr[k]);
        }
        printf("\n");
    }
    printf("Sorted array is as follows:\n");
    for (int i = 0; i < n; i++)
    {
        printf("%d ", arr[i]);
    }
}