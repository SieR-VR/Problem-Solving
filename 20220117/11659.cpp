#include <iostream>
#include <vector>

using namespace std;

int main() {
    ios::ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int n, m;
    cin >> n >> m;

    vector<int> v(n);
    vector<int> v_sum(n);
    for(int i = 0; i < n; i++) {
        cin >> v[i];
        if (i == 0) v_sum[0] = v[0];
        else v_sum[i] = v_sum[i-1] + v[i];
    }

    for(int i = 0; i < m; i++) {
        int i_, j_;
        cin >> i_ >> j_;

        if (j_ < i_) {
            int t = j_;
            j_ = i_;
            i_ = t;
        }

        cout << v_sum[j_-1] - v_sum[i_-2] << "\n";
    }

}