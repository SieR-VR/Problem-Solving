#include <iostream>
#include <vector>

int main() {
	int m, n;
	std::cin >> m >> n;
	
	std::vector<int> arr;
	for(int i = 1; i <= m; i++)
		arr.push_back(i);
	
	int pos = n - 1;
	for(int i = 0; i < m; i++) {
		std::cout << arr[pos] << " ";
		arr.erase(arr.begin() + pos); 
        pos += n - 1; 
        if (arr.size()) pos %= arr.size(); 
	}	
}