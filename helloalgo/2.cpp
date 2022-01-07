#include <iostream>
#include <vector>

int k;
int *arr;

std::vector<int> stack;

void bfs(int level, int index) {
    if (index > k) return;

	if(level == 0) {
		for(int i = 0; i < 6; i++)
			std::cout << stack[i] << " ";
        std::cout << std::endl;
        return;
	}
	
	for(int i = index; i < k; i++) {
		stack.push_back(arr[i]);
		bfs(level - 1, i + 1);
		stack.pop_back();
	}
}

int main() {
	std::cin >> k;
	arr = new int[k];
	
	for(int i = 0; i < k; i++) std::cin >> arr[i];
	
	bfs(6, 0);
}