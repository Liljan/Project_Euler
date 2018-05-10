#include <iostream>
#include <string>

bool is_palindrome(size_t number)
{
	std::string str = std::to_string(number);
	return std::equal(str.begin(), str.begin() + str.size() / 2, str.rbegin());
}

size_t largest_palindrome(size_t digits)
{
	size_t n = pow(10, digits) - 1;

	for (size_t y = n; y > 0; --y)
	{
		for (size_t x = n; x >= y; --x)
		{
			if (is_palindrome(x*y))
			{
				return x*y;
			}
		}
	}

	return 0;
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
	const int digits = 3;

	size_t b = largest_palindrome_dumb(digits);

	return 0;
}