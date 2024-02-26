#include <iostream>
#include <string>

using namespace std;

int main() {
    int n; cin >> n;
    int m; cin >> m;

    int cnt = 0;
    string s; cin >> s;

    for(int i = 0; i < s.size(); i++) {
        int k = 0;

        if (s[i] == 'O')
            continue;

        while(s[i + 1] == 'O' && s[i + 2] == 'I')
        {
            k++;
            if (k == n) {
                k--; cnt++;
            }
            i += 2;
        }
    }

    cout << cnt;
}