#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

struct User
{
    int index;
    int age;
    std::string name;
};

int main() {
    int n;
    std::cin >> n;

    std::vector<User> users;

    for(int i = 0; i < n; i++) {
        User user;
        user.index = i;
        std::cin >> user.age >> user.name;

        users.push_back(user);
    }

    std::sort(users.begin(), users.end(), [](const User &lhs, const User &rhs) {
        if (lhs.age != rhs.age)
            return lhs.age < rhs.age;
        else
            return lhs.index < rhs.index;
    });

    for(int i = 0; i < n; i++) {
        std::cout << users[i].age << " " << users[i].name << "\n";
    }
}
