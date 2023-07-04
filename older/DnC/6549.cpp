#include <iostream>
#include <vector>

typedef long long ll;

int main()
{
    for(;;) {
        int n;
        std::cin >> n;

        if(n == 0) break;

        std::vector<ll> arr(n);
        ll max = -1;

        for(int i = 0; i < n; i++)
            std::cin >> arr[i];

        std::vector<ll> s;

        for(int i = 0; i < n; i++) {
            while (!s.empty() && arr[s.back()] > arr[i]) {
                ll ht = arr[s.back()];
                s.pop_back();

                ll w = i;

                if(!s.empty()) w = i - s.back() - 1;
                max = std::max(max, w * ht);
            }
            s.push_back(i);
        }

        while(!s.empty()) {
            ll ht = arr[s.back()];
            s.pop_back();

            ll w = n;
            if(!s.empty()) w = n - s.back() - 1;
            max = std::max(max, w * ht);
        }

        std::cout << max << "\n";
    }
}