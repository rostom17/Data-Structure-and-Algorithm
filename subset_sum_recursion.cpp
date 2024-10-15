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

bool subsetSum (vector<int>& nums, int n, int sum)
{
    if(n==0) {
        if(sum==0) return true;
        else return false;
    }
    if(nums[n-1] <= sum) 
    {
        bool pick = subsetSum(nums, n-1, sum - nums[n-1]);
        bool dontPick = subsetSum(nums, n-1, sum);
        return pick || dontPick;
    }
    else{
        return subsetSum(nums, n-1, sum);
    }
}

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
    int sum;
    cin >> sum;

    if(subsetSum(nums, n, sum)) cout << "Possible" << endl;
    else cout << "NOT Possible" << endl;
    return 0;
}