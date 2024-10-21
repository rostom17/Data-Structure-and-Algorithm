#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    int sum = 0;
    cin >> n;
    int nums[n];
    for (int i = 0; i < n; i++)
    {
        cin >> nums[i];
        sum += nums[i];
    }

    bool dp[n + 1][sum + 1];
    dp[0][0] = true;
    for (int j = 1; j <= sum; j++)
    {
        dp[0][j] = false;
    }

    for (int i = 1; i <= n; i++)
    {
        for (int j = 0; j <= sum; j++)
        {
            if (j >= nums[i - 1])
            {
                dp[i][j] = dp[i - 1][j - nums[i - 1]] || dp[i - 1][j];
            }
            else
            {
                dp[i][j] = dp[i - 1][j];
            }
        }
    }
    vector<int> possibleSums;
    for (int j = 0; j <= sum; j++)
    {
        if(dp[n][j]) possibleSums.push_back(j);
    }
    int difference = INT_MAX;

    for(int i : possibleSums)
    {
        int s1 = i;
        int s2 = sum - s1;
        difference = min(difference, abs(s1-s2));

    }
    cout << difference << endl;

    return 0;
}