#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int m, n;
vector<int> arr;

vector<int> stack;
bool visited[8];

void solve(int level) {
    if(level == 0) {
        for(int i = 0; i < stack.size(); i++)
            cout << stack[i] << " ";
        cout << "\n";

        return;
    }

    for(int i = 0; i < n; i++) {
        if(!visited[i]) {
            visited[i] = true;
            stack.push_back(arr[i]);
            solve(level - 1);
            stack.pop_back();
            visited[i] = false;
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

    solve(m);
}