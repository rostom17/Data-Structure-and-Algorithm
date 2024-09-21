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
    vector<int> nums = {3,6,5,7,4,1,8,2};
    vector<int> prefixSum(nums.size());
    prefixSum[0] = nums[0];
    for(int i=1; i<nums.size(); i++) {
        prefixSum[i] = prefixSum[i-1] + nums[i];
    }
    int left = 2, right = 7;
    int rangeSum = prefixSum[right] - prefixSum[left-1];
    cout << rangeSum << endl;
    for(int i : prefixSum) cout << i << " ";
    return 0;
}