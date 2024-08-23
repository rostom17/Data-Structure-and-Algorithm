#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; i++)
        cin >> a[i];

    int findValue;
    cin >> findValue;

    int left = 0, right = n - 1;
    int valueIndex = -1;

    while (left <= right)
    {
        int mid = (left + right) / 2;
        if (a[mid] == findValue)
        {
            valueIndex = mid;
            break;
        }
        else if (a[mid] > findValue)
        {
            right = mid - 1;
        }
        else
        {
            left = mid + 1;
        }
    }
    if (valueIndex != -1)
    {
        cout << "We find the value in index : " <<valueIndex << endl;
    }
    else
    {
        cout << "Value not found" << endl;
    }
    return 0;
}