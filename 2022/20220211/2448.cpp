#include <iostream>
#include <string>
#include <vector>

using namespace std;

int n, width;

vector<string> tri = {
    "  *  ",
    " * * ",
    "*****"};

vector<string> res;

void recurse(int level, int x, int y)
{
    if (level == 3)
    {
        for (int i = 0; i < 3; i++)
            for (int j = 0; j < 5; j++)
                res[x + i][y + j] = tri[i][j];

        return;
    }

    recurse(level / 2, x, y + level / 2);
    recurse(level / 2, x + level / 2, y);
    recurse(level / 2, x + level / 2, y + level);
}

int main()
{
    cin >> n;
    width = (n * 2);

    res = vector<string>(n, string(width, ' '));

    recurse(n, 0, 0);
    for (int i = 0; i < n; i++)
        cout << res[i] << "\n";
}