#include <iostream>
#include <vector>
#include <set>
#include <cmath>
#include <algorithm>

struct Point
{
    int x, y;

    bool operator<(const Point &other) const {
        if (y == other.y) return x < other.x;
        else return y < other.y;
    }
};

int dist(const Point &p1, const Point &p2)
{
    return (p1.x - p2.x) * (p1.x - p2.x) + (p1.y - p2.y) * (p1.y - p2.y);
}

int main()
{
    int n;
    std::cin >> n;

    std::vector<Point> points(n);

    for (int i = 0; i < n; i++) 
        std::cin >> points[i].x >> points[i].y;

    std::sort(points.begin(), points.end(), [](const Point &lhs, const Point &rhs) {
        return lhs.x < rhs.x;
    });

    std::set<Point> candidate = { points[0], points[1] }; 
    int ans = dist(points[0], points[1]);
    int pos = 0;

    for(int i = 2; i < n; i++) {
        while(pos < i) {
            int dx = points[i].x - points[pos].x;
            if (dx * dx > ans) {
                candidate.erase(points[pos]);
                pos++;
            }
            else break;
        }

        int d = (int)std::sqrt((double)ans)+1;
        Point lower_bound = { -100001, points[i].y - d };
        Point upper_bound = { 100001, points[i].y + d };

        auto lower = candidate.lower_bound(lower_bound);
        auto upper = candidate.upper_bound(upper_bound);

        for (auto it = lower; it != upper; it++)
            ans = std::min(dist(points[i], *it), ans);

        candidate.insert(points[i]);
    }

    std::cout << ans;
}