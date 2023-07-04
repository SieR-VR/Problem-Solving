#include <iostream>
#include <string>
#include <vector>

int main()
{
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);

    int T;
    std::cin >> T;

    for (int i = 0; i < T; i++)
    {
        std::string p;
        std::cin >> p;

        int n;
        std::cin >> n;

        std::string temp;
        std::cin >> temp;

        std::vector<int> arr;
        std::string temp2;

        for(int i = 0; i < temp.size(); i++) {
            if(temp[i] == '[') continue;
            else if(temp[i] == ']') {
                if(!temp2.empty()) arr.push_back(stoi(temp2));
                temp2.clear();
                continue;
            }
            else if(temp[i] == ',') {
                arr.push_back(stoi(temp2));
                temp2.clear();
                continue;
            }
            else temp2 += temp[i];
        }

        bool reversed = false;
        bool shouldskip = false;

        int start = 0;
        int end = arr.size();

        for (int i = 0; i < p.size(); i++)
        {
            if (p.at(i) == 'R')
                reversed = !reversed;
            else
            {
                if (start == end)
                {
                    std::cout << "error\n";
                    shouldskip = true;
                    break;
                }

                if (reversed) end--;
                else start++;
            }
        }

        if (shouldskip)
            continue;

        if (start == end)
        {
            std::cout << "[]\n";
            continue;
        }

        if (!reversed)
        {
            std::cout << "[";
            for (int i = start; i < end; i++)
            {
                if (i == end - 1)
                    std::cout << arr[i] << "]\n";
                else
                    std::cout << arr[i] << ",";
            }
        }
        else
        {
            std::cout << "[";
            for (int i = end - 1; i >= start; i--)
            {
                if (i == start)
                    std::cout << arr[i] << "]\n";
                else
                    std::cout << arr[i] << ",";
            }
        }
    }
}