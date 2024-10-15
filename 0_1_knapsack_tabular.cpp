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
    vector<int> value;
    vector<int> weight;
    int capacity;
    cin >> n;
    for(int i=0; i<n; i++) {
        int x;
        cin >> x;
        value.push_back(x);
    }
    for(int i=0; i<n; i++) {
        int x;
        cin >> x;
        weight.push_back(x);
    }
    cin >> capacity;

    int dp[n+1][capacity+1];

    for(int j=0; j<=capacity;j++) {
        dp[0][j] = 0;
    }
    for(int i=0; i<=n; i++) {
        dp[i][0] = 0;
    }

    for(int i=1; i<=n; i++) {
        for(int j=1; j<=capacity; j++) {
            if(j >= weight[i-1]) {
                dp[i][j] = max (dp[i-1][j], dp[i-1][j-weight[i-1]] + value[i-1]);
            }
            else 
            {
                dp[i][j] = dp[i-1][j];
            }
        }
    }
    cout << dp[n][capacity] << endl;
    return 0;
}