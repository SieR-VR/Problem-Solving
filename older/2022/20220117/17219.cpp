#include <iostream>
#include <map>
#include <string>
 
using namespace std;

int main() {
    ios::ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int n, m;
    cin >> n >> m;

    map<string, string> keyring;

    for(int i = 0; i < n; i++) {
        string s1, s2;
        cin >> s1 >> s2;

        keyring.insert({ s1, s2 });
    }

    for(int i = 0; i < m; i++) {
        string s; cin >> s;
        cout << keyring.find(s)->second << "\n";
    }
}