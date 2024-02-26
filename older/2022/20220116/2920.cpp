#include <iostream>

int main() {
    bool asc_flag = true;
    bool desc_flag = true;

    for(int i = 1; i <= 8; i++) {
        int t = 0; std::cin >> t;

        if (t != i) asc_flag = false;
        if (t != (9 - i)) desc_flag = false;
    }    
    
    if (asc_flag)
        std::cout << "ascending";
    else if(desc_flag)
        std::cout << "descending";
    else
        std::cout << "mixed";
}