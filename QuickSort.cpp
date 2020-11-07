#include <iostream>
using namespace std;

void quickSort(int[], int, int);
int partition(int[], int, int);
//void swap(int, int);

int main()
{
    int a[50], n, i;
    cout << "Enter the number of rectangles :: ";
    cin >> n;
    cout << "\nEnter the heights of rectangles :: " << endl;

    for (i = 0; i < n; i++)
    {
        cin >> a[i];
    }

    quickSort(a, 0, n - 1);
    cout << "Array after sorting :: " << endl;

    for (i = 0; i < n; i++)
    {
        cout << a[i] << "\t";
    }

    return 0;
}

void quickSort(int a[], int l, int u)
{
    if (l < u)
    {
        int Index = partition(a, l, u);
        quickSort(a, l, Index - 1);
        quickSort(a, Index + 1, u);
    }
}

int partition(int a[], int l, int u)
{
    int pivot = a[l];
    int start = l;
    int end = u;
    while (start < end)
    {
        while (a[start] <= pivot)
        {
            start++;
        }
        while (a[end] > pivot)
        {
            end--;
        }
        if (start < end)
        {
            int temp = a[start];
            a[start] = a[end];
            a[end] = temp;
        }
    }
    //swap(a[l], a[end]);
    int tem = a[l];
    a[l] = a[end];
    a[end] = tem;

    return end;
}
