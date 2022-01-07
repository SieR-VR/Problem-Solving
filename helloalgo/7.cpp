#include <iostream>

int R, C;
char board[21][21];
bool visit[21][21];
bool visit_alphabet[26] = { 0, };

int x = 0, y = 0;
int max = 0;

bool bfs(int level) {
    if (x < 0 || x >= R || y < 0 || y >= C || visit[x][y] || visit_alphabet[board[x][y] - 'A']) return false;
    visit[x][y] = true;
    visit_alphabet[board[x][y] - 'A'] = true;

    bool found = false;

    x++;
    if(bfs(level+1)) found = true;
    x--;

    x--;
    if(bfs(level+1)) found = true;
    x++;

    y++;
    if(bfs(level+1)) found = true;
    y--;

    y--;
    if(bfs(level+1)) found = true;
    y++;
    
    if (!found) max = std::max(level, max);  
    return true;
}

int main() {
    std::cin >> R >> C;
    for(int i = 0; i < R; i++) {
        for(int j = 0; j < C; j++) {
            scanf("%c", &board[i][j]);
            visit[i][j] = false;
        }
    }

    bfs(1);

    std::cout << max;
}