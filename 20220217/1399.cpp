#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <map>

using namespace std;

typedef long long ll;

bool used_alphabets[26] = { 0 };
int used_alphabet_count = 0;
vector<char> used;

int main() {
    ll n; cin >> n;

    vector<string> str_vec;
    for(ll i = 0; i < n; i++) {
        string temp; cin >> temp;
        str_vec.push_back(temp);
    }

    for(ll i = 0; i < n; i++) {
        for(char c : str_vec[i]) {
            if (!used_alphabets[c - 'A']) {
                used_alphabet_count++;
                used.push_back(c);
            }
            used_alphabets[c - 'A'] = 1;
        }
    }

    sort(used.begin(), used.end());
    ll max_result = 0;

    do {
        map<char, ll> m;
        for(ll i = 9; i > 9 - used_alphabet_count; i--) 
            m.insert({ used[9 - i], i });

        ll result = 0;
        for(auto s : str_vec) {
            ll temp = 0;

            for(ll i = 0; i < s.length(); i++) {
                temp *= 10;
                temp += m[s[i]];
            }

            result += temp;
        }

        max_result = max(result, max_result);
    }
    while (next_permutation(used.begin(), used.end()));

    cout << max_result;
}