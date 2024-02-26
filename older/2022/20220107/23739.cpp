#include <iostream>

int main() {
  int n;
  std::cin >> n;

  int buf = 30;
  int studied = 0;
  for(int i = 0; i < n; i++) {
    int t;
    std::cin >> t;

    buf -= t;
    if (buf > 0) {
      studied++;
    }
    else {
      if (-buf <= (t / 2)) studied++;
      buf = 30;
    }
  }

  std::cout << studied;
}