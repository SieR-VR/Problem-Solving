#include <iostream>

using namespace std;

int gcd(int a, int b) {
    if (a % b == 0)
        return b;
    
    return gcd(b, a % b);
}

int main() {
    int t; cin >> t;

    for(int i = 0; i < t; i++) {
        int m, n, x, y;
        cin >> m >> n >> x >> y;

        int gcd_ = gcd(m, n);
        int max_year = m * n / gcd_;
        bool flag = true;

        while (true)
        {
            if (x > max_year || ((x - 1) % n) + 1 == y)
                break;
            
            x += m;
        }

        if (x > max_year)
            cout << "-1\n";
        else
            cout << x << "\n";
        
    }
}