#include <iostream>
#include <map>

using namespace std;

int main() {
    int n, m;
    cin >> n >> m;

    map<int, int> start_end_map;
    map<int, int> end_start_map;
    for(int i = 1; i <= n; i++) {
        start_end_map.insert({ i, i });
        end_start_map.insert({ i, i });
    }

    for(int i = 0; i < m; i++) {
        int a, b;
        cin >> a >> b;

        if (a > b) std::swap(a, b);

        auto start_it = start_end_map.upper_bound(a);
        if (start_end_map.find(a) != start_end_map.end()) start_it--;

        auto end_it = end_start_map.lower_bound(b);

        start_end_map.erase(start_it, start_end_map.find(end_it->first));
        end_start_map.erase(end_start_map.find(start_it->first), end_it);
    }

    cout << start_end_map.size();
}