#include <iostream>
#include <string>
#include <deque>

using namespace std;

int D(int c) {
    return ((c * 2) % 10000);
}

int S(int c) {
    if (c == 0) return 9999;
    return c - 1;
}

int L(int c) {
    if (c >= 1000) {
        int digit = c / 1000;
        return (c % 1000) * 10 + digit;
    }
    else return c * 10;
}

int R(int c) {
    int digit = c % 10;
    c /= 10;
    c += digit * 1000;
    return c;
}

struct State
{
    int cal;
    string command;
};


int main()
{
    std::ios::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);
    int t; cin >> t;

    for(int i = 0; i < t; i++) {
        bool visited[10000] = { 0 };
        int a, b; cin >> a >> b;
        deque<State> dq;
        dq.push_back({ a, "" });
        visited[a] = true;

        string res;

        while (dq.size())
        {
            State c = dq.front(); dq.pop_front();

            if (c.cal == b) {
                res = c.command;
                break;
            }

            int D_ = D(c.cal);
            if (!visited[D_]) {
                visited[D_] = true;
                dq.push_back({ D_, c.command + "D" });
            }
            int S_ = S(c.cal);
            if (!visited[S_]) {
                visited[S_] = true;
                dq.push_back({ S_, c.command + "S" });
            }
            int L_ = L(c.cal);
            if (!visited[L_]) {
                visited[L_] = true;
                dq.push_back({ L_, c.command + "L" });
            }
            int R_ = R(c.cal);
            if (!visited[R_]) {
                visited[R_] = true;
                dq.push_back({ R_, c.command + "R" });
            }
        }
        
        cout << res << "\n";
    }
}