#include <iostream>
#include <vector>

using namespace std;

vector<vector<int>> dp;

struct State {
    vector<int> bloqs;
    vector<int> used;
    vector<int> mul;
    int begin_dp_x;
    int begin_dp_y;
};

int count_bits(int a) {
    int count = 0;
    for(int i = 0; i < 4; i++) 
        if((a >> i) & 0x1) count++;

    return count;
}

bool check(vector<int> prev, vector<int> used, vector<int> current) {
    vector<int> isConnected(prev.size(), 0);

    for(int i = 0; i < prev.size(); i++) {
        for(auto c : current) {
            if (prev[i] & c && (used[i] + count_bits(c) < 5)) isConnected[i] = 1;
        }
    }

    for(int is : isConnected) {
        if (!is) return false;
    }
    return true;
}



int main() {
    int n;
    cin >> n;

    int table[4][n];
    for(int i = 0; i < 4; i++) {
        for(int j = 0; j < n; j++) {
            cin >> table[i][j];
        }
    }

    dp.resize(16, vector<int>(n, 0));
    dp[15][0] = table[0][0] * table[1][0] * table[2][0] * table[3][0];

    vector<vector<int>> availables = {
        {}, 
        {1}, {2}, {4}, {8},
        {1,2}, {1,4}, {1,8}, {2,4}, {2,8}, {4,8},
        {1,2,4}, {1,2,8}, {1,4,8}, {2,4,8},
        {1,2,4,8},
        {3}, {6}, {12},
        {3,4}, {3,8}, {1,6}, {6,8}, {1,12}, {2,12},
        {3,4,8}, {1,6,8}, {1,2,12},
        {7}, {14},
        {7, 8}, {1, 14},
        {15}
    };

    vector<State> states = {
        { { 3 }, { 2 }, { table[0][0] * table[1][0] }, 0, 0 },
        { { 3, 4 }, { 2, 1 }, { table[0][0] * table[1][0], table[2][0] }, 0, 0 },
        { { 3, 8 }, { 2, 1 }, { table[0][0] * table[1][0], table[3][0] }, 0, 0 },
        { { 3, 4, 8 }, { 2, 1, 1 }, { table[0][0] * table[1][0], table[2][0], table[3][0] }, 0, 0 },
        { { 6 }, { 2 }, { table[1][0] * table[2][0] }, 0, 6 },
        { { 1, 6 }, { 1, 2 }, { table[0][0], table[1][0] * table[2][0] }, 0, 0 },
        { { 6, 8 }, { 2, 1 }, { table[1][0] * table[2][0], table[3][0] }, 0, 0 },
        { { 1, 6, 8 }, { 1, 2, 1 }, { table[0][0], table[1][0] * table[2][0], table[3][0] }, 0, 0 },
        { { 12 }, { 2 }, { table[2][0] * table[3][0] }, 0, 12 },
        { { 1, 12 }, { 1, 2 }, { table[0][0], table[2][0] * table[3][0] }, 0, 0 },
        { { 2, 12 }, { 1, 2 }, { table[1][0], table[2][0] * table[3][0] }, 0, 0 },
        { { 1, 2, 12 }, { 1, 1, 2 }, { table[0][0], table[1][0], table[2][0] * table[3][0] }, 0, 0 },
        { { 7 }, { 3 }, { table[0][0] * table[1][0] * table[2][0] }, 0, 0 },
        { { 7, 8 }, { 3, 1 }, { table[0][0] * table[1][0] * table[2][0], table[3][0] }, 0, 0 },
        { { 14 }, { 3 }, { table[1][0] * table[2][0] * table[3][0] }, 0, 0 },
        { { 1, 14 }, { 1, 3 }, { table[0][0], table[1][0] * table[2][0] * table[3][0] }, 0, 0 },
    };

    for(int i = 0; i < 16; i++) {
        State state;
        state.begin_dp_x = 0;
        state.begin_dp_y = 0;

        for(int j = 0; j < 4; j++) {       
            if ((i >> j) & 0x1) {
                state.bloqs.push_back(1 << j);
                state.used.push_back(1);
                state.mul.push_back(table[j][0]);
            }
        }

        states.push_back(state);
    }

    for(int i = 1; i < n; i++) {
        vector<State> state_temp;
        for(auto state : states) {
            for(auto avail : availables) {
                if (!check(state.bloqs, state.used, avail)) continue;
                State new_state;
                vector<int> merged(avail.size(), 0);

                for(int j = 0; j < state.bloqs.size(); j++) {
                    for(int k = 0; k < avail.size(); k++) {
                        if (state.bloqs[j] & avail[k]) {
                            merged[k] = 1;
                            state.used[j] += count_bits(avail[k]);
                            for(int m = 0; m < 4; m++)
                                if ((avail[k] >> m) & 0x1) state.mul[i] *= table[k][i];
                        }
                    }
                }

                int complete_ = 0;
                int complete_sum_ = 0;
                bool exists = false;

                for(int j = 0; j < state.bloqs.size(); j++) {
                    if (state.used[j] == 4) {
                        exists = true;
                        complete_ += state.bloqs[j];
                        complete_sum_ += state.mul[j];
                    }
                    else {
                        new_state.bloqs.push_back(state.bloqs[j]);
                        new_state.mul.push_back(state.mul[j]);
                        new_state.used.push_back(state.used[j]);
                    }
                }

                for(int j = 0; j < merged.size(); j++) {
                    if (!merged[j]) {
                        new_state.bloqs.push_back(avail[j]);
                        new_state.used.push_back(count_bits(avail[j]));
                        int mul = 1;
                        for(int k = 0; k < 4; k++) {
                            if ((avail[j] >> k) & 0x1) mul *= table[k][i];
                        }
                        new_state.mul.push_back(mul);
                    }
                }

                dp[complete_][i] = max(dp[complete_][i], dp[state.begin_dp_x][state.begin_dp_y] + complete_sum_);
                if (new_state.bloqs.size()) {
                    new_state.begin_dp_x = exists ? complete_ : state.begin_dp_x;
                    new_state.begin_dp_y = exists ? i : state.begin_dp_y;
                    state_temp.push_back(new_state);
                } 
            }
        }
        states = state_temp;
    }

    int max_res = 0;
    for(int i = 0; i < 16; i++) {
        max_res = max(max_res, dp[i][n-1]); 
    }

    cout << max_res;
}