#include <iostream>
#include <set>
#include <queue>
#include <memory.h>

using namespace std;

struct Node
{
    set<int> friends;
};

int main()
{
    int n;
    cin >> n;
    Node *nodes = new Node[n + 1];
    bool *visited = new bool[n + 1];
    int *parents = new int[n + 1];

    for (int i = 0; i < n - 1; i++)
    {
        int t1, t2;
        cin >> t1 >> t2;
        nodes[t1].friends.insert(t2);
        nodes[t2].friends.insert(t1);
    }

    memset(visited, false, (n + 1) * sizeof(bool));
    memset(parents, 0, (n + 1) * sizeof(int));

    queue<int> q;
    q.push(1);

    while (q.size())
    {
        auto c = q.front();
        q.pop();

        for (int f : nodes[c].friends)
        {
            if (!visited[f])
            {
                q.push(f);
                parents[f] = c;
                visited[f] = true;
            }
        }
    }

    for(int i = 2; i <= n; i++) 
        cout << parents[i] << "\n";
}