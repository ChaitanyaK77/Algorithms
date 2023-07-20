#include <stdio.h>
int arr[20], n, q, x, count;
void getarr();
void QuickSort(int arr[], int p, int r);
int Partition(int arr[], int p, int r);
int main()
{
    getarr();
    int p = 0;
    int r = n - 1;
    QuickSort(arr, p, r);
    printf("After sorting the array is:\n");
    for (int i = 0; i < n; i++)
    {
        printf("%d ", arr[i]);
    }
    printf("Total calls to quickSort = %d\n", count);
    return (0);
}

void getarr()
{
    printf("Enter total number of elements in the array:\n");
    scanf("%d", &n);
    printf("Enter the array elements:\n");
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &arr[i]);
    }
}

void QuickSort(int arr[], int p, int r)
{
    count++;
    if (p < r)
    {

        q = Partition(arr, p, r);
        QuickSort(arr, p, q - 1);
        QuickSort(arr, q + 1, r);
    }
}
int Partition(int arr[], int p, int r)
{
    x = arr[r];
    int i = p - 1;
    for (int j = p; j <= r - 1; j++)
    {
        if (arr[j] <= x)
        {
            i++;
            int temp = arr[i];
            arr[i] = arr[j];
            arr[j] = temp;
        }
    }
    int temp = arr[i + 1];
    arr[i + 1] = arr[r];
    arr[r] = temp;
    return i + 1;
}