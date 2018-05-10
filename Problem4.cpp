#include <iostream>
#include <string>

#include <time.h>

bool is_palindrome(size_t number)
{
	std::string str = std::to_string(number);
	return std::equal(str.begin(), str.begin() + str.size() / 2, str.rbegin());
}

bool is_palindrome_fast(size_t number)
{
	size_t reversed = 0;
	size_t original = number;

	if (number < 10)
		return true;

	if (number % 10 == 0)
		return false;

	while (number >= 1)
	{
		reversed = (reversed * 10) + (number % 10);
		number /= 10;
	}

	return original == reversed;
}


size_t largest_palindrome(size_t digits)
{
	size_t n = pow(10, digits) - 1;

	size_t y = n;
	size_t max = 0;

	while (y > pow(10,digits-1))
	{
		size_t x = n;
		while (x >= y)
		{
			if (is_palindrome_fast(x*y) && x*y > max)
			{
				max = x*y;
			}
			x--;
		}
		y--;
	}

	return max;
}

size_t largest_palindrome_dumb(size_t digits)
{
	size_t n = pow(10, digits);

	size_t largest = 0;

	int xb, yb;

	for (size_t x = 1; x < n; x++)
	{
		for (size_t y = 1; y <= x; y++)
		{
			if (is_palindrome(x*y) && x*y > largest)
			{
				largest = x*y;
			}
				
		}
	}

	return largest;
}

int main()
{
	float ratio = 1. / CLOCKS_PER_SEC;
	clock_t t1 = clock();

	const int digits = 3;

	size_t b = largest_palindrome(digits);

	clock_t t2 = clock();

	float time = ratio*(long)t1 + ratio*(long)t2;

	std::cout << "The largest palindrome " << b << " was found in " << time << " s." << std::endl;

	return 0;
}