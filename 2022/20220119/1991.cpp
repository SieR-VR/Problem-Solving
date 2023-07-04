#include <iostream>

using namespace std;

struct Node
{
    int left, right;
};

Node nodes[26];

void dfs(int node, int mode) {
    if (mode == 1) 
        cout << (char)(node + 'A');

    if (nodes[node].left != -1)
        dfs(nodes[node].left, mode);

    if (mode == 2)
        cout << (char)(node + 'A');

    if (nodes[node].right != -1)
        dfs(nodes[node].right, mode);

    if (mode == 3)
        cout << (char)(node + 'A');
}   

int main()
{
    for(int i = 0; i < 26; i++)
        nodes[i] = { 0, 0 };

    int n; cin >> n;
    for(int i = 0; i < n; i++) {
        char p, l, r;
        cin >> p >> l >> r;

        nodes[p - 'A'].left = (l == '.') ? (-1) : (l - 'A');
        nodes[p - 'A'].right = (r == '.') ? (-1) : (r - 'A');
    }

    dfs(0, 1);
    cout << "\n";
    dfs(0, 2);
    cout << "\n";
    dfs(0, 3);
}