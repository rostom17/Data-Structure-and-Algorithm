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
    cin>> n;
    vector<int> nums;
    for(int i=0; i<n; i++) {
        int x;
        cin >> x;
        nums.push_back(x);
    }
    int k;
    cin >> k;
    int sum = 0;
    int maxSum = 0;
    for(int i=0; i<k; i++) {
        sum += nums[i];
    }
    maxSum = sum;
    int startIdx = 0;
    int endIdx = k-1;
    for(int i = k; i<n; i++) {
        sum+=nums[i];
        sum-=nums[i-k];
        if(sum > maxSum) {
            maxSum = sum;
            startIdx = i-k;
            endIdx = i;
        }
    }
    cout << maxSum << endl;
    for(int i=startIdx; i<endIdx; i++) {
        cout << nums[i] <<" ";
    }
    return 0;
}