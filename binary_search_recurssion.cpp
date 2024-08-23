#include<bits/stdc++.h>
using namespace std;

int binary_search(vector<int> a, int findValue, int left, int right)
{
    if(left <= right)
    {
        int mid = (left + right) / 2;
        if(a[mid] == findValue)
        {
            return mid;
        }
        else if(a[mid] > findValue)
        {   
            return binary_search(a, findValue, left, mid - 1);
        }
        else
        {
            return binary_search(a, findValue, mid + 1, right);
        }
        
    }
    return -1;
    
}

int main ()
{
    int n;
    cin >> n;
    vector<int> a(n);
    for(int i=0; i<n; i++)
        cin >> a[i];
    
    int findValue;
    cin >> findValue;

    int valueIndex = binary_search(a, findValue, 0, n-1);

    if(valueIndex != -1)
    {
        cout << "Value found at Index : " << valueIndex << endl;
    }
    else
    {
        cout << "Value not Found" << endl;
    }
    return 0;
}