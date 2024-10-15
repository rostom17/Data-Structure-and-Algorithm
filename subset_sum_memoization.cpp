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

const int range = 1e3 + 1;
int dpTable [range][range];

bool subsetSum (vector<int>& nums, int n, int sum)
{
    if(n==0) {
        if(sum==0) return true;
        else return false;
    }
    if(dpTable[n][sum] != -1) return dpTable[n][sum];
    if(nums[n-1] <= sum) 
    {
        bool pick = subsetSum(nums, n-1, sum - nums[n-1]);
        bool dontPick = subsetSum(nums, n-1, sum);
        return dpTable[n][sum] = pick || dontPick;
    }
    else{
        return dpTable[n][sum] = subsetSum(nums, n-1, sum);
    }
}

int main ()
{
    for(int i=0; i<range; i++){
        for(int j=0; j<range; j++) {
            dpTable[i][j] = -1;
        }
    }
    int n;
    cin >> n;
    vector<int> nums;
    for(int i=0; i<n; i++) {
        int val; 
        cin >> val;
        nums.push_back(val);
    }
    int sum;
    cin >> sum;

    if(subsetSum(nums, n, sum)) cout << "Possible" << endl;
    else cout << "NOT Possible" << endl;
    return 0;
}