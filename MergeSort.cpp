#include <iostream>
#define MAX 6
void merge(int a[], int low, int mid, int high)
{
    int i = low;
    int j = mid + 1;
    int k = 0;
    int b[1000];
    while (i <= mid && j <= high)
    {
        if (a[i] <= a[j])
        {
            b[k] = a[i];
            i++;
            k++;
        }
        else
        {
            b[k] = a[j];
            j++;
            k++;
        }
    }
    while (i <= mid)
    {
        b[k] = a[i];
        k++;
        i++;
    }
    while (j <= high)
    {
        b[k] = a[j];
        k++;
        j++;
    }
    k--;
    while (k >= 0)
    {
        a[low + k] = b[k];
        k--;
    }
}
void mergesort(int a[], int low, int high)
{
    if (low < high)
    {
        int m = (low + high) / 2;
        mergesort(a, low, m);
        mergesort(a, m + 1, high);
        merge(a, low, m, high);
    }
    else
    {
        return;
    }
}

int main(void)
{
    int a[MAX] = {20, 10, 70, 80, 40, 90};

    printf("\n정렬 전\n");
    for (int i = 0; i < MAX; i++)
    {
        printf(" %d", a[i]);
    }
    mergesort(a, 0, MAX - 1);
    printf("\n정렬 후\n");
    for (int i = 0; i < MAX; i++)
    {
        printf(" %d", a[i]);
    }
    return 0;
}