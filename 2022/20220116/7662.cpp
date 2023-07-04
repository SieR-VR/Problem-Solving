#include <iostream>
#include <map>
#include <string>

int main() {
    int t; std::cin >> t;

    for(int i = 0; i < t; i++) {
        int k; std::cin >> k;
        std::map<int, int> m;

        for(int i = 0; i < k; i++) {
            std::string c; int n;
            std::cin >> c >> n;

            if(c.at(0) == 'I') {
                auto found = m.find(n);

                if(found != m.end()) found->second++;
                else m.insert({ n, 1 });
            }
            else {
                if(!m.empty()) {
                    if(n == 1) {
                        if (std::prev(m.end())->second == 1)
                            m.erase(std::prev(m.end())->first);
                        else std::prev(m.end())->second--;
                    }
                    else {
                        if (m.begin()->second == 1)
                            m.erase(m.begin()->first);
                        else m.begin()->second--;
                    }
                }
            }
        }

        if(m.empty()) {
            std::cout << "EMPTY\n";
        }
        else {
            std::cout << std::prev(m.end())->first << " " << m.begin()->first << "\n";
        }
    }
}