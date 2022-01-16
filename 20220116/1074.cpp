#include <iostream>

int main() {
    int n, r, c, res = 0;
    std::cin >> n >> r >> c;
    for(int i = 0; i < n; i++)
        res |= (((int)(r >> i) & 0x1) << (2*i + 1)) | (((int)(c >> i) & 0x1) << (2*i));
    std::cout << res;
}