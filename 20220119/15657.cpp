#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int m, n;
vector<int> arr;

vector<int> stack;
bool visited[8];

void solve(int level) {
    if(level == m) {
        for(int i = 0; i < stack.size(); i++)
            cout << stack[i] << " ";
        cout << "\n";

        return;
    }

    for(int i = 0; i < n; i++) {
        if (stack.size() && stack[stack.size() - 1] <= arr[i]) {
            stack.push_back(arr[i]);
            solve(level + 1);
            stack.pop_back();
        }
        else if (!stack.size()) {
            stack.push_back(arr[i]);
            solve(level + 1);
            stack.pop_back();
        }
    }
}

int main()
{
    cin >> n >> m;
    for (int i = 0; i < n; i++)
    {
        int t; cin >> t;
        arr.push_back(t);
    }

    sort(arr.begin(), arr.end());

    solve(0);
}