#include <iostream>

using namespace std;
typedef long long ll;


int main() {
    ll N, M; cin >> N >> M;
    ll K; cin >> K;

    ll knows = 0;

    for(ll i = 0; i < K; i++) {
        ll t; cin >> t;
        knows |= (ll)1 << t;
    }

    ll parties[M];
    ll answer[M];

    for(ll i = 0; i < M; i++) {
        parties[i] = 0; answer[i] = 1;
    }


    for(ll i = 0; i < M; i++) {
        ll t; cin >> t;
        for(ll j = 0; j < t; j++) {
            ll t_; cin >> t_;
            parties[i] |= (ll)1 << t_;
        }
    }

    for(ll i = 0; i < M; i++) {
        for(ll j = 0; j < M; j++) {
            if ((knows & parties[j]) && answer[j]) {
                answer[j] = 0;
                knows |= parties[j];
                i = 0;
            }
        }
    }

    ll res = 0;
    for(ll i = 0; i < M; i++) {
        res += answer[i];
    }

    cout << res;
}
