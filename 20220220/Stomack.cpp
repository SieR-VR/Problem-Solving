#include <string>
#include <vector>
#include <map>

using namespace std;

int solution(vector<vector<string>> clothes) {
    map<string, int> m;

    for(auto c : clothes) {
        m[c[1]]++;
    }

    int answer = 1;
    for(auto i : m) {
        answer *= (i.second + 1);
    }

    return answer - 1;
}