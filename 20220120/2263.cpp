#include <iostream>
#include <vector>

using namespace std;

int n;
int index[100001] = { -1 };
int inorder[100001] = { -1 };
int postorder[100001] = { -1 };

void solve(int lower, int upper, int postlower, int postupper) {
    if (lower > upper || postlower > postupper)
        return;

    int root = index[postorder[postupper]];
    int left = root - lower;
    int right = upper - root;

    cout << inorder[root] << " ";

    solve(lower, root-1, postlower, postlower + left - 1);
    solve(root + 1, upper, postlower + left, postupper - 1);
}

struct Node {
    int left, right;
};

int main() {
    cin >> n;

    for(int i = 1; i <= n; i++) {
        cin >> inorder[i];
        index[inorder[i]] = i;
    }
    for(int i = 1; i <= n; i++)
        cin >> postorder[i];

    solve(1, n, 1, n);
}