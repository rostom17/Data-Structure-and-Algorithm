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
    queue<int> q;
    int n;
    cin >> n;
    while(n--) {
        int x;
        cin >> x;
        q.push(x);
    }
    cout << q.size() << endl;
    cout << q.front() << endl;
    cout << q.back() << endl;
    q.pop();
    cout << q.front() << endl;
    cout << endl;
    while(!q.empty()) {
        cout << q.front() << endl;
        q.pop();
    }
    return 0;
}