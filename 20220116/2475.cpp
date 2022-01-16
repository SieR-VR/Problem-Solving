#include <iostream>

int main() {
    int num = 0;

    for(int i = 0; i < 5; i++) {
        int t; std::cin >> t;
        num += t * t;
    }

    std::cout << (num % 10);
}