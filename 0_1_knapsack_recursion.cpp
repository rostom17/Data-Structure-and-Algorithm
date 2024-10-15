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

int knapsack(vector<int> &value, vector<int> &weight, int capacity, int n)
{
    if(n == 0 || capacity == 0) return 0;
    if (capacity >= weight[n - 1])
    {
        int pick = knapsack(value, weight, capacity - weight[n - 1], n - 1) + value[n - 1];
        int dontPick = knapsack(value, weight, capacity, n - 1);
        return max(pick, dontPick);
    }
    else 
    {
        return knapsack(value, weight, capacity, n-1);
    }
}

int main()
{
    int n;
    cin >> n;
    vector<int> value;
    vector<int> weight;
    for (int i = 0; i < n; i++)
    {
        int x;
        cin >> x;
        value.push_back(x);
    }
    for (int i = 0; i < n; i++)
    {
        int x;
        cin >> x;
        weight.push_back(x);
    }
    int capacity;
    cin >> capacity;

    cout << knapsack(value, weight, capacity, n);
    return 0;
}