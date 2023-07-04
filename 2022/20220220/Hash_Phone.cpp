#include <string>
#include <vector>
#include <set>
#include <algorithm>

using namespace std;

bool solution(vector<string> phone_book) {
    sort(phone_book.begin(), phone_book.end(), [](const string &a, const string &b) {
        return a.length() > b.length();
    });
    set<string> s;
    
    for(string phone : phone_book) {
        if (s.find(phone) != s.end()) return false;
        
        for(int i = 1; i <= phone.size(); i++) {
            string sub = phone.substr(0, i);
            s.insert(sub);
        }
    }
    
    return true;
}