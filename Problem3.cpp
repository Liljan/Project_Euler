#include <iostream>
#include <vector>

// Good version
std::vector<size_t>& find_primes(long long number)
{
	std::vector<size_t> prime_factors;

	// range error check
	if (number < 2)
	{
		return prime_factors;
	}

	// Special check for factor 2
	if (number % 2 == 0)
	{
		prime_factors.push_back(2);
	}
	
	// Normal check
	for (size_t i = 3; i <= number; i += 2)
	{
		while (number % i == 0)
		{
			number /= i;
			std::cout << i << " , ";
			prime_factors.push_back(i);
		}
	}

	return prime_factors;
}


int main()
{
  long long number = 600851475143;
/*
uint max:		4294967295
range:			600851475143
sqrt range:		775146 
*/

  std::vector<size_t> vec = find_primes(number);

  return 0;
}