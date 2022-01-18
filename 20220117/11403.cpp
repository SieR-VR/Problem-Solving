#include <iostream>

using namespace std;

int mat[100][100];

int main() {
    ios::ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int n; cin >> n;
    for(int i = 0; i < n; i++)
        for(int j = 0; j < n; j++)
            cin >> mat[i][j];

    for(int k = 0; k < n; k++)
        for(int i = 0; i < n; i++)
            for(int j = 0; j < n; j++)
                if (mat[i][k] && mat[k][j]) 
                    mat[i][j] = true;

    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) 
            cout << mat[i][j] << " ";
        cout << "\n";
    }
}