#include <iostream>
#include <string>

using namespace std;

int main() {
    string str;
    string bomb;

    cin >> str >> bomb;
    string stack;

    for(char c : str) {
        stack.push_back(c);
        if(stack.length() >= bomb.length()) {
            string temp = stack.substr(stack.length() - bomb.length());
            if (temp == bomb) 
                for(int i = 0; i < bomb.length(); i++)
                    stack.pop_back();
        }
    }

    if(stack.length()) {
        cout << stack;
    }
    else cout << "FRULA";
}