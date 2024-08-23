#include <iostream>
using namespace std;

void MERGE(int *a, int left, int q, int right)
{
    int n1 = q - left + 1;
    int n2 = (right - q);
    int L[n1];
    int R[n2];
    for (int i = 0; i < n1; i++)
    {
        L[i] = a[left + i];
    }
    for (int j = 0; j < n2; j++)
    {
        R[j] = a[q + 1 + j];
    }
    int i = 0, j = 0;
    int k = left;
    while (i < n1 && j < n2)
    {
        if (L[i] <= R[j])
        {
            a[k] = L[i];
            i++;
            k++;
        }
        else
        {
            a[k] = R[j];
            j++;
            k++;
        }
    }
    while (i < n1)
    {
        a[k] = L[i];
        i++;
        k++;
    }
    while (j < n2)
    {
        a[k] = R[j];
        j++;
        k++;
    }
}

void merge_sort(int *a, int left, int right)
{
    if (right == left)
    {
        return;
    }
    int q = (left + right) / 2;
    merge_sort(a, left, q);
    merge_sort(a, q + 1, right);
    MERGE(a, left, q, right);
}

int main()
{
    int n;
    cin >> n;
    int a[n];
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    merge_sort(a, 0, n - 1);
    for (int i = 0; i < n; i++)
    {
        cout << a[i] << " ";
    }
    return 0;
}