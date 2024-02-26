#include <iostream>

typedef long long ll;

int main() {
    ll N;
    ll arr[6];

    std::cin >> N;
    for(int i = 0; i < 6; i++)
        std::cin >> arr[i];

    if (N == 1) {
        ll max = 0; ll sum = 0;
        for (int i = 0; i < 6; i++) {
            max = std::max(max, arr[i]);
            sum += arr[i];
        }

        std::cout << sum - max;
        return 0;
    }

    ll oppo[6] = { 5, 4, 3, 2, 1, 0 };
    ll min_1 = 51, min_2 = 102, min_3 = 153;

    for (int i = 0; i < 6; i++)
        min_1 = std::min(min_1, arr[i]);

    for (int i = 0; i < 6; i++) {
        for(int j = 0; j < 6; j++) {
            if (oppo[i] == j || i == j) continue;
            min_2 = std::min(min_2, arr[i] + arr[j]);
        }
    }

    for (int i = 0; i < 6; i++)  {
        min_1 = std::min(min_1, arr[i]);
        for (int j = 0; j < 6; j++) {
            if (oppo[i] == j || i == j) continue;
            min_2 = std::min(min_2, arr[i] + arr[j]);
            for (int k = 0; k < 6; k++) {
                if (oppo[i] == k || oppo[j] == k || i == k || j == k) continue;
                min_3 = std::min(min_3, arr[i] + arr[j] + arr[k]);
            }
        }
    }

    ll ans = (min_3 * 4) + (min_2 * (8*N - 12)) + (min_1 * (5*N*N - 16*N + 12));
    std::cout << ans;
}