#include <iostream>

int N;
int **arr;

int getSum(int K, int xIndex, int yIndex) {
    int result = 0;
    for (int i = 0; i < K; i++) {
        for (int j = 0; j < K; j++) {
            result += arr[i + xIndex][j + yIndex];
        }
    }

    return result;
}

int main()
{
    std::cin >> N;

    arr = new int*[N];
    for (int i = 0; i < N; i++)
        arr[i] = new int[N];

    for (int i = 0; i < N; i++)
        for (int j = 0; j < N; j++)
            std::cin >> arr[i][j];

    int _max = -2000;
    for (int i = 1; i <= N; i++) {
        const int toMoveDistance = N - i;
        for (int xIndex = 0; xIndex <= toMoveDistance; xIndex++) {
            int sum = getSum(i, xIndex, 0);
            _max = std::max(sum, _max);
            for (int yIndex = 0; yIndex < toMoveDistance; yIndex++) {
                for(int blockIndex = xIndex; blockIndex < i + xIndex; blockIndex++) {
                    sum -= arr[blockIndex][yIndex];
                    sum += arr[blockIndex][yIndex + i];
                }
                _max = std::max(sum, _max);
            }
        }
    }

    std::cout << _max;
}