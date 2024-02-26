#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int m, n;
vector<int> arr;

vector<int> stack;
int visited_num[8] = {false};
int visited_max[10001] = {0};

void solve(int level)
{
    if (level == 0)
    {
        for (int i = 0; i < stack.size(); i++)
            cout << arr[stack[i]] << " ";
        cout << "\n";
        return;
    }

    for (int i = 0; i < arr.size(); i++)
    {
        if (visited_num[i] < visited_max[arr[i]])
        {
            visited_num[i]++;
            stack.push_back(i);
            solve(level - 1);
            stack.pop_back();
            visited_num[i]--;
        }
    }
}

int main()
{
    cin >> n >> m;
    for (int i = 0; i < n; i++)
    {
        int t;
        cin >> t;
        if (!visited_max[t]) 
            arr.push_back(t);
        visited_max[t]++;
    }

    sort(arr.begin(), arr.end());

    solve(m);
}