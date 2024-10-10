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

int fibo (int n)
{
    if(n <= 1) return 1;
    return fibo(n-1) + fibo(n-2);

}

int main ()
{
    int n;
    cin >> n;
    cout << fibo(n) << endl;
    return 0;
}