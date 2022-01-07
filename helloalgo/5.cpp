#include <iostream>

int main() {
    int n;
    std::cin >> n;

    int *arr = new int[n];
    for(int i = 0; i < n; i++) std::cin >> arr[i];

    for(int i = 0; i < n; i++) {
        bool found = false;

        for(int j = i - 1; j >= 0; j--) {
            if (arr[i] <= arr[j]) {
                std::cout << j + 1 << " "; 
                found = true; break;
            }
        }

        if (!found) std::cout << 0 << " ";
    }
}