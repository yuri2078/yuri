#include <iostream>
#include <queue>
#include <stack>

using std::queue;
using std::stack;

void queueReverse(queue<int>& q_1) {
	stack<int> s_1;
	while (!q_1.empty()) {
		s_1.push(q_1.front());
		q_1.pop();
	}

	while (!s_1.empty()) {
		std::cout << s_1.top() << " ";
		s_1.pop();
	}
	std::cout << std::endl;
}

int main() {
	queue<int> q_1;
	
	int n;
	std::cin >> n;
	for (int i=0; i<n; i++) {
		int x;
		std::cin >> x;
		q_1.push(x);
	}

	queueReverse(q_1);
	return 0;
}