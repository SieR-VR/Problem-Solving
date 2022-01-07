#include <iostream>
#include <vector>

struct Node {
    int parentIndex, thisIndex;
    std::vector<Node *> children;
};

int N;
int erase;
std::vector<Node *> roots;
std::vector<Node *> nodes;

int leafs = 0;

void dfs(Node *node) {
    if (node->thisIndex == erase) return;

    if (!node->children.size()) {
        leafs++;
        return;
    }

    if (node->children.size() == 1 && node->children[0]->thisIndex == erase) {
        leafs++;
        return;
    }

    for (Node *child : node->children) {
        dfs(child);
    }
}

int main() {
    for (int i = 0; i < 50; i++)
        nodes.push_back(new Node({ -1, -1, std::vector<Node *>() }));

    std::cin >> N;
    for (int i = 0; i < N; i++) {
        int temp = 0;
        std::cin >> temp;

        Node *node = new Node({ temp, i, std::vector<Node *>() });

        if (temp == -1) {
            roots.push_back(node);
            if (nodes[i]->children.size()) 
                node->children = nodes[i]->children;
            nodes[i] = node;
        }
        else {
            if (nodes[i]->children.size()) 
                node->children = nodes[i]->children;
            nodes[temp]->children.push_back(node);
            nodes[i] = node;
        }
    }

    std::cin >> erase;

    for (int i = 0; i < roots.size(); i++) {
        dfs(roots[i]);
    }

    std::cout << leafs;
}