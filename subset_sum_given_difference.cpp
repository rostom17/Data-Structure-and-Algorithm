#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <stack>
#include <queue>
#include <map>
#include <set>
#include <list>
#include <unordered_map>
#include <unordered_set>

using namespace std;

int main ()
{
    int n;
    cin >> n;
    int nums[n];
    int sum = 0;
    for(int i=0; i<n; i++)
    {
        cin >> nums[i];
        sum += nums[i];
    }
    int diff;
    cin >> diff;
    if(diff >= sum)
    {
        cout << "ImPossible" << endl;
    }
    else if((sum+ abs(diff)) % 2 == 0)
    {
        int target = (sum+diff) / 2;
        bool dp[n+1][target+1];
        dp[0][0] = true;
        for(int j=1; j<=target; j++)
        {
            dp[0][j] = false;
        }

        for(int i=1; i<=n; i++)
        {
            for(int j=0; j<= target; j++)
            {
                if(j >= nums[i-1])
                {
                    dp[i][j] = dp[i-1][j-nums[i-1]] || dp[i-1][j];
                }
                else 
                {
                    dp[i][j] = dp[i-1][j];
                }
            }
        }
        if(dp[n][target]) cout << "Possible" << endl;
        else cout << "Not Possible" << endl;

    }
    else 
    {
        cout << "NOT POSSIBLE" << endl;
    }
    return 0;
}