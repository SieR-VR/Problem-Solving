#include <iostream>

using namespace std;

typedef long long ll;
ll table[1000000] = {0};
bool real_table[1000001] = { 0 };

int main() {
    ll mi, ma;
    cin >> mi >> ma;

    for(ll i = 2; i * i <= ma; i++) {
        table[i] = i * i;
    }

    for(ll i = 2; i * i <= ma; i++) {
        for(ll j = (mi % table[i]) ? (mi - (mi % table[i]) + table[i]): mi; j <= ma; j += table[i]) {
            real_table[j - mi] = true;
        }
    }

    ll count = 0;

    for(ll i = mi; i <= ma; i++) {
        if (!real_table[i - mi]) count++;
    }

    cout << count; 
}