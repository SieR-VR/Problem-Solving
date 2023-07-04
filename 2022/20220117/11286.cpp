#include <iostream>
#include <vector>
#include <queue>

using namespace std;

struct Compare
{
    bool operator()(int a, int b) {
        if (abs(a) == abs(b)) return a > b;
        return abs(a) > abs(b);
    }
};


int main() {
    std::ios::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);

    int n; std::cin >> n;
    priority_queue<int, vector<int>, Compare> pq;
    vector<int> cs(n);

    for(int i = 0; i < n; i++) {
        std::cin >> cs[i];
    }

    for(int i = 0; i < n; i++) {
        if (cs[i] == 0) {
            if (pq.empty()) std::cout << "0\n";
            else {
                std::cout << pq.top() << "\n";
                pq.pop();
            }
        }
        else {
            pq.push(cs[i]);
        }
    }
}