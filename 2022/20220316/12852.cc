#include <iostream>
#include <queue>

using namespace std;

int main() {
    int n;
    cin >> n;

    int arr[n+1];
    for(int i = 0; i <= n; i++)
        arr[i] = 0;

    queue<pair<int, int>> q;
    q.push({ n, 0 });

    while (q.size())
    {
        auto p = q.front();
        q.pop();

        if (p.first == 1) break;

        if (!(p.first % 3) && !arr[p.first / 3]) {
            q.push({ p.first / 3, p.first + 1 });
            arr[p.first / 3] = p.first;
        }
        if (!(p.first % 2) && !arr[p.first / 2]) {
            q.push({ p.first / 2, p.first + 1 });
            arr[p.first / 2] = p.first;
        }
        if (p.first > 1 && !arr[p.first - 1]) {
            q.push({ p.first - 1, p.first + 1 });
            arr[p.first - 1] = p.first;
        }
    }

    vector<int> result;

    int p = 1;
    int count = 0;
    while(p) {
        result.push_back(p);
        p = arr[p];
    }

    cout << result.size() - 1 << "\n";
    for(int i = result.size() - 1; i >= 0; i--) {
        cout << result[i] << " ";
    }
}