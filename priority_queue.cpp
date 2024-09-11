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
    int a [6] = { 10, 2, 4, 8, 6, 9 };
    priority_queue<int> pq; // pq sorted thakbe bigger to smaller

    for (int i : a) 
    {
        pq. push(i);
    }

    while(!pq.empty()) {
        cout << pq.top() << endl;
        pq.pop();
    }

    priority_queue<int, vector<int>, greater<int>> pqq; //pq sorted thakbe smaller to bigger

    for(int i : a) {
        pqq.push(i);
    }
    cout << "Reverse Sorting" << endl;
    while (!pqq.empty())
    {
        cout << pqq.top() << endl;
        pqq.pop();
    }
    

    return 0;
}