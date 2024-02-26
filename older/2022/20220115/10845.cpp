#include <iostream>
#include <string>
#include <deque>

int main() {
    std::ios::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);

    int n; std::cin >> n;
    std::deque<int> dq;
    
    for(int i = 0; i < n; i++) {
        std::string c; std::cin >> c;
        int n_;
        if (c.at(0) == 'p' && c.at(1) == 'u') {
            std::cin >> n_;
            dq.push_back(n_);
        }
        else if (c.at(0) == 'p') {
            if (dq.size()) {
                n_ = dq.front();
                std::cout << n_ << "\n";
                dq.pop_front();
            }
            else std::cout << "-1\n";
        }
        else if (c.at(0) == 's') std::cout << dq.size() << "\n";
        else if (c.at(0) == 'e') std::cout << dq.empty() << "\n";
        else if (c.at(0) == 'f') {
            if (dq.size()) std::cout << dq.front() << "\n";
            else std::cout << "-1\n";
        }
        else if (c.at(0) == 'b') {
            if (dq.size()) std::cout << dq.back() << "\n";
            else std::cout << "-1\n";
        }
    }
}