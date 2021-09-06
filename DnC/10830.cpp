#include <iostream>
#include <vector>

typedef long long ll;
typedef std::vector<std::vector<int>> vec2d;

ll N, B;
vec2d A[64];

vec2d dot(const vec2d &a, const vec2d &b)
{
    vec2d res;
    for (int i = 0; i < N; i++)
    {
        std::vector<int> temp1;
        for (int j = 0; j < N; j++)
        {
            int temp2 = 0;
            for (int k = 0; k < N; k++)
            {
                temp2 += a[i][k] * b[k][j];
            }
            temp1.push_back(temp2 % 1000);
        }
        res.push_back(temp1);
    }

    return res;
}

int main()
{
    std::cin >> N >> B;

    for (int i = 0; i < N; i++)
    {
        std::vector<int> temp1;
        for (int j = 0; j < N; j++)
        {
            int temp2;
            std::cin >> temp2;
            temp1.push_back(temp2);
        }
        A[0].push_back(temp1);
    }

    for(int i = 1; i < 64; i++)
        A[i] = dot(A[i-1], A[i-1]);

    vec2d res(N);
    for(int i = 0; i < N; i++) {
        for(int j = 0; j < N; j++) {
            res[i].push_back(i==j);
        }
    }

    for(int i = 0; i < 64; i++) {
        if((B >> i) & 0x01) res = dot(res, A[i]);
    }

    for(int i = 0; i < N; i++) {
        for(int j = 0; j < N; j++) {
            std::cout << res[i][j] << " ";
        }
        std::cout << std::endl;
    }
}