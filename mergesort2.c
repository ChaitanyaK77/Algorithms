#include <stdio.h>
#include <math.h>
int arr[20], b[20], l, h, n, count;
void MergeSort(int l, int h);
void Merge(int l, int m, int h);
void getarr();
int main()
{
    getarr();
    l = 0;
    h = n - 1;
    MergeSort(l, h);
    printf("Array after sorting is :\n");
    for (int i = 0; i < n; i++)
    {
        printf("%d ", arr[i]);
    }
    printf("\nTotal Merge Sort calls = %d\n", count);
}
void getarr()
{
    printf("Enter total number of elements in the array:\n");
    scanf("%d", &n);
    printf("Enter the array elements\n");
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &arr[i]);
    }
}
void MergeSort(int l, int h)
{
    count++;
    int mid;
    if (l < h)
    {
        mid = floor((float)(l + h) / 2);
        MergeSort(l, mid);
        MergeSort(mid + 1, h);
        Merge(l, mid, h);
    }
}
void Merge(int low, int mid, int high)
{
    int h, i, j;
    h = low;
    i = low;
    j = mid + 1;

    while (h <= mid && j <= high)
    {
        b[i++] = arr[h] <= arr[j] ? arr[h++] : arr[j++];
    }
    if (h > mid)
        for (int k = j; k <= high; k++)
        {
            b[i++] = arr[k];
        }
    if (j > high)
    {
        for (int k = h; k <= mid; k++)
        {
            b[i++] = arr[k];
        }
    }
    for (int k = low; k <= high; k++)
    {
        arr[k] = b[k];
    }
}