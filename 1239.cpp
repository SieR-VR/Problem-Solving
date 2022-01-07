#include <iostream>

int N;
int *dogs;

int state = 0;
int cool = 0;

void dfs(int index) {
    if (state == 50) {
        cool++;
        return;
    }

    if (state > 50) {
        return;
    }

    for(int i = index; i < N; i++) {
        state += dogs[i];
        dfs(i + 1);
        state -= dogs[i];
    }
}

int main() {
    std::cin >> N;

    dogs = new int[N];
    for(int i = 0; i < N; i++)
        std::cin >> dogs[i];

    dfs(0);

    std::cout << cool / 2;
}