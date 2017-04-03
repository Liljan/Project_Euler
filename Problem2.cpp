#include <iostream>

int main() {
	int prev = 0;
	int current = 1;

	int range = 4000000;

	int sum = 0;

	int temp;
	while (current < range) {
		temp = current + prev;

		if (temp % 2 == 0)
			sum += temp;

		prev = current;
		current = temp;
	}

	std::cout << sum << std::endl;

	return 0;
}