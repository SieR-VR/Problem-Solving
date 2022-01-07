#include <iostream>
#include <algorithm>
#include <vector>

int main() {
    int n;
    std::cin >> n;

    std::vector<int> arr(n);
    for(int i = 0; i < n; i++) std::cin >> arr[i];

    std::sort(arr.begin(), arr.end());

    int max = 0;
    for(int i = 0; i < n; i++) {
        max = std::max(max, (n - i) * arr[i]);
    }

    std::cout << max;
}