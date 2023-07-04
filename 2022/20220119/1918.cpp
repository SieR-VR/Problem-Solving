#include <iostream>
#include <stack>
#include <string>

using namespace std;

int main()
{
    string str;
    cin >> str;
    string res;
    string stk;
    for (char c : str)
    {
        if ('A' <= c && c <= 'Z')
        {
            res.push_back(c);
        }
        if (c == '+' || c == '-')
        {
            while (!stk.empty() && stk.back() != '(')
            {
                res.push_back(stk.back());
                stk.pop_back();
            }
            stk.push_back(c);
        }
        if (c == '*' || c == '/')
        {
            while (!stk.empty() && (stk.back() == '*' || stk.back() == '/'))
            {
                res.push_back(stk.back());
                stk.pop_back();
            }
            stk.push_back(c);
        }
        if (c == '(')
        {
            stk.push_back(c);
        }
        if (c == ')')
        {
            while (!stk.empty() && stk.back() != '(')
            {
                res.push_back(stk.back());
                stk.pop_back();
            }
            stk.pop_back();
        }
    }

    while (!stk.empty() && stk.back() != '(')
    {
        res.push_back(stk.back());
        stk.pop_back();
    }

    cout << res;
}