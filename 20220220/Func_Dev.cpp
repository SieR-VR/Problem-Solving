#include <string>
#include <vector>

using namespace std;

vector<int> solution(vector<int> progresses, vector<int> speeds) {
    vector<int> answer;

    while(progresses.size()) {
        for(int i = 0; i < progresses.size(); i++) {
            progresses[i] += speeds[i];
        }

        int a;

        while(progresses.size() || progresses[0] >= 100) {
            progresses.erase(progresses.begin());
            a++;
        }

        answer.push_back(a);
    }

    return answer;
}