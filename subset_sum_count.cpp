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
    vector<int> nums;
    for(int i=0; i<n; i++) {
        int val; 
        cin >> val;
        nums.push_back(val);
    }
    int target;
    cin >> target;

    int dp[n+1][target+1];

    dp[0][0] = 1;

    for(int j=1; j<=target; j++) {
        dp[0][j] = 0;
    }
    
    for(int i=1; i<=n; i++) {
        for(int j=0; j<= target; j++) {
            if(j >= nums[i-1]) {
                dp[i][j] = dp[i-1][j-nums[i-1]] + dp[i-1][j];
            }
            else  {
                dp[i][j] = dp[i-1][j];
            }

        }
    }
    cout << dp[n][target] << endl;

    return 0;
}