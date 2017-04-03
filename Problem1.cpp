#include <iostream>

int main() {

	int sum = 0;
	int range = 1000;

	for (int i = 3; i < range; ++i)
	{
		if (i % 3 == 0 || i % 5 == 0)
			sum += i;
	}

	std::cout << sum << std::endl;

	return 0;
}