#include <iostream>

int N;
int paper[2187][2187];

int count[3] = {0};

int iLower = 0;
int jLower = 0;

int iUpper = 0;
int jUpper = 0;

bool isOnePiece()
{
    int color = paper[iLower][jLower];

    for (int i = iLower; i < iUpper; i++)
        for (int j = jLower; j < jUpper; j++)
            if (color != paper[i][j])
                return false;

    return true;
}

void recurse(int level)
{
    if (level == 1)
    {
        count[paper[iLower][jLower] + 1]++;
        return;
    }

    if (isOnePiece())
    {
        count[paper[iLower][jLower] + 1]++;
        return;
    }

    int itu = iUpper, jtu = jUpper, itl = iLower, jtl = jLower;

    for(int k = 0; k < 3; k++) {
        for(int l = 0; l < 3; l++) {
            iLower = itl + ((itu - itl) / 3) * k;
            iUpper = itl + ((itu - itl) / 3) * (k+1);
            jLower = jtl + ((jtu - jtl) / 3) * l;
            jUpper = jtl + ((jtu - jtl) / 3) * (l+1);

            recurse(level / 3);

            iLower = itl;
            iUpper = itu;
            jLower = jtl;
            jUpper = jtu;
        }
    }
}

int main()
{
    std::cin >> N;
    iUpper = N;
    jUpper = N;

    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
            std::cin >> paper[i][j];
    }

    recurse(N);

    std::cout << count[0] << std::endl
              << count[1] << std::endl
              << count[2] << std::endl;
}