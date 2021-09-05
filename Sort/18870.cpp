#include <iostream>
#include <vector>
#include <algorithm>

int main()
{
    std::cin.tie(nullptr);
    std::ios_base::sync_with_stdio(false);

    int n;
    std::cin >> n;

    std::vector<int> arr1;

    for (int i = 0; i < n; i++) {
        int temp;
        std::cin >> temp;

        arr1.push_back(temp);
    }

    std::vector<int> arr2 = arr1;
    std::sort(arr1.begin(), arr1.end());
    arr1.erase(std::unique(arr1.begin(), arr1.end()), arr1.end());

    for (int i = 0; i < n; i++) {
        if(i == n - 1) std::cout << std::lower_bound(arr1.begin(), arr1.end(), arr2[i]) - arr1.begin();
        else std::cout << std::lower_bound(arr1.begin(), arr1.end(), arr2[i]) - arr1.begin() << " ";
    }
}