#include<bits/stdc++.h>
using namespace std;

void merge(vector<int> &v, int left, int mid, int right)
{
    int leftSubArraySize = mid - left + 1;
    int rightSubArraySize = right - mid;

    int leftSubArray[leftSubArraySize];
    int rightSubArray[rightSubArraySize];

    for(int i=0; i<leftSubArraySize; i++)
    {
        leftSubArray[i] = v[i + left] ;
    }
    for(int i=0; i<rightSubArraySize; i++)
    {
        rightSubArray[i] = v[i + mid + 1];
    }

    int i=0, j=0, k = left;
    while(i<leftSubArraySize && j < rightSubArraySize)
    {
        if(leftSubArray[i] <= rightSubArray[j])
        {
            v[k] = leftSubArray[i];
            i++, k++;
        }
        else
        {
            v[k] = rightSubArray[j];
            j++, k++;
        }
    }

    while(i < leftSubArraySize)
    {
        v[k] = leftSubArray[i];
        i++, k++; 
    }
    while (j < rightSubArraySize)
    {
        v[k] = rightSubArray[j];
        j++, k++;
    }
    
}

void merge_sort(vector<int> &v, int left, int right)
{
    if(left == right) return;

    int mid = (left + right) / 2;
    merge_sort(v, left, mid);
    merge_sort(v, mid+1, right);

    merge(v, left, mid, right);
}

void print_sorted_array (vector<int> v, int n)
{
    for(int i=0; i<n; i++)
    {
        cout << v[i] << " ";
    }
    cout << endl;
}

int main ()
{
    int n;
    cin >> n;
    vector<int> v(n);
    for(int i=0; i<n; i++)
    {
        cin >> v[i];
    }
    
    merge_sort(v, 0, n-1);

    print_sorted_array(v, n);

    return 0;
}