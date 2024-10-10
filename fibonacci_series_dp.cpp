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
    vector<int> fibo(n+1,-1);
    fibo[0] = 1;
    fibo[1] = 1;
    for(int i=2; i<=n; i++) {
        fibo[i] = fibo[i-1] + fibo[i-2];
    }
    for(int i : fibo) cout << i << " ";
    return 0;
}