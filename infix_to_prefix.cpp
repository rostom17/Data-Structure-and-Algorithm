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

bool isOperator(char c)
{
    if (c == '+' || c == '-' || c == '*' || c == '/')
        return true;
    else
        return false;
}

bool isNumber(char c)
{
    if (c >= '0' && c <= '9')
        return true;
    else
        return false;
}

int main()
{
    string s;
    cin >> s;
    reverse(s.begin(), s.end());

    string output;
    stack<char> stk;
    unordered_map<char, int> pcdnc = {
        {'/', 4},
        {'*', 3},
        {'+', 1},
        {'-', 2}

    };

    for (char c : s)
    {
        if (isNumber(c))
        {
            output += c;
        }
        else if (isOperator(c))
        {
            if (!stk.empty())
            {
                if (isOperator(c) && pcdnc[c] <= pcdnc[stk.top()])
                {
                    output += stk.top();
                    stk.pop();
                    stk.push(c);
                }
                else
                {
                    stk.push(c);
                }
            }
            else
            {
                stk.push(c);
            }
        }
        else if (c == ')')
        {
            stk.push(')');
        }
        else
        {
            while (!stk.empty() && stk.top() != ')')
            {
                output += stk.top();
                stk.pop();
            }
            stk.pop();
        }
    }

    while (!stk.empty())
    {
        output += stk.top();
        stk.pop();
    }
    reverse(output.begin(), output.end());
    cout << output << endl;

    return 0;
}