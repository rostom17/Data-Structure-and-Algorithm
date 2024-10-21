#include<bits/stdc++.h>

using namespace std;

int main ()
{
    int n;
    cin >> n;
    int a[n];
    int sum = 0;
    for(int i=0; i<n; i++)
    {
        cin >> a[i];
        sum += a[i];
    }

    if(sum % 2 == 0)
    {
        int target = sum / 2;
        bool dp[n+1][target+1];
        dp[0][0] = true;
        for(int j=1; j<=target; j++)
        {
            dp[0][j] = false;
        }
        for(int i=1; i<=n; i++)
        {
            for(int j=0; j<=target; j++)
            {
                if(j >= a[i-1])
                {
                    dp[i][j] = dp[i-1][j] || dp[i-1][j-a[i-1]];
                }
                else
                {
                    dp[i][j] = dp[i-1][j];
                }
            }
        }
        if(dp[n][target]) cout << "Possible" << endl;
        else cout << "Not Possbile" << endl;
    }
    else
    {
        cout << "NOT POSSIBLE" << endl;
    }

    return 0;
}