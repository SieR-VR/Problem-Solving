#include <iostream>
#include <map>
#include <vector>
#include <algorithm>
#include <cmath>

int getLength(const std::pair<int, int> &p1, const std::pair<int, int> &p2) {
    return (p2.first - p1.first) * (p2.first - p1.first) + (p2.second - p1.second) * (p2.second - p1.second);
}

int main() {
    int n;
    std::cin >> n;

    std::vector<std::pair<int, int>> v(n);
    std::map<int, int> m;
    for(int i = 0; i < n; i++) {
        int ts1, ts2;
        std::cin >> ts1 >> ts2;

        v[i] = {ts1, ts2};
    }

    std::sort(v.begin(), v.end(), [](const std::pair<int, int> &p1, const std::pair<int, int> &p2) {
        return p1.first < p2.first;
    });

    int min_length = getLength(v[0], v[1]);
    int idx = 0;

    for(int i = 2; i < n; i++) {
        while (idx < i) {
            int d = v[i].first - v[idx].first;
            if(d * d <= min_length) break;
            else {
                v.erase(v.begin() + idx);
                idx++;
            }
        }

        auto start = m.lower_bound((v[i].first - std::sqrt(min_length)));
        auto end = m.upper_bound((v[i].first + std::sqrt(min_length)));

        for(auto it = start; it != end; it++) {
            min_length = std::min(min_length, getLength(v[i], { it->first, it->second }));
        }

        m.insert({ v[i].first, v[i].second });
    }

    std::cout << min_length << "\n";
}