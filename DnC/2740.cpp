#include <iostream>
#include <vector>

int main() {
    int AN, AM;
    std::cin >> AN >> AM;

    int A[100][100];

    for(int i = 0; i < AN; i++) {
        for(int j = 0; j < AM; j++) {
            std::cin >> A[i][j];
        }
    }

    int BN, BM;
    std::cin >> BN >> BM;

    int B[100][100];

    for(int i = 0; i < BN; i++) {
        for(int j = 0; j < BM; j++) {
            std::cin >> B[i][j];
        }
    }

    std::vector<int> result;

    for(int i = 0; i < AN; i++) {
        for(int j = 0; j < BM; j++) {
            int temp = 0;
            for(int k = 0; k < AM; k++) {
                temp += A[i][k] * B[k][j];
            }
            std::cout << temp << " ";
        }
        std::cout << std::endl;
    }
}