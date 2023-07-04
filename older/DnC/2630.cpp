#include <iostream>
#include <vector>

int N;
bool paper[128][128];

int bluecount = 0;
int whitecount = 0;

int iLower = 0;
int jLower = 0;

int iUpper = 0;
int jUpper = 0;

bool isOnePiece()
{
    bool color = paper[iLower][jLower];

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
        if (paper[iLower][jLower])
            bluecount++;
        else
            whitecount++;

        return;
    }

    if (isOnePiece())
    {
        if (paper[iLower][jLower])
            bluecount++;
        else
            whitecount++;

        return;
    }

    int it, jt;

    it = iUpper;
    iUpper = (iLower + iUpper) / 2;
    jt = jUpper;
    jUpper = (jLower + jUpper) / 2;

    recurse(level / 2);

    iUpper = it;
    jUpper = jt;

    it = iUpper;
    iUpper = (iLower + iUpper) / 2;
    jt = jLower;
    jLower = (jLower + jUpper) / 2;

    recurse(level / 2);

    iUpper = it;
    jLower = jt;

    it = iLower;
    iLower = (iLower + iUpper) / 2;
    jt = jUpper;
    jUpper = (jLower + jUpper) / 2;

    recurse(level / 2);

    iLower = it;
    jUpper = jt;

    it = iLower;
    iLower = (iLower + iUpper) / 2;
    jt = jLower;
    jLower = (jLower + jUpper) / 2;

    recurse(level / 2);

    iLower = it;
    jLower = jt;
}

int main()
{
    std::cin >> N;
    iUpper = N;
    jUpper = N;

    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
        {
            int t;
            std::cin >> t;

            paper[i][j] = (bool)t;
        }
    }

    recurse(N);

    std::cout << whitecount << std::endl
              << bluecount << std::endl;
}