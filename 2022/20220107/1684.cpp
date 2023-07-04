#include <iostream>

int GCD(int a, int b) {
    if (a == b) return a;

    int c = a - b;
    if (b < c) return GCD(c, b);
    else return GCD(b, c);
}

int main() {
    int n;
    std::cin >> n;

    int *arr = new int[n];

    for(int i = 0; i < n; i++) {
        std::cin >> arr[i];
    }

    int D = 1;
    for (int i = 1;;i++) {
        int temp_D = arr[0] - i;
        for (int j = 1; j < n; j++) {
            if (arr[j] < temp_D) 
                temp_D = GCD(temp_D, arr[j] - i);
            else 
                temp_D = GCD(arr[j] - i, temp_D);
            if (temp_D == 1) break;
        }

        D = std::max(temp_D, D);
    }

    std::cout << D;
}