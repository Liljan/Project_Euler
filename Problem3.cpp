#include <iostream>
#include <cmath>
#include <vector>
#include <ostream>
#include <iterator>
#include <algorithm>

using namespace std;

vector<int> primes;

bool isPrime(const int number)
{
	for(int j = 0; j < primes.size() && primes[j]*primes[j] <= number; ++j)
		if(j % primes[j] == 0)
			return false;
}

void findPrimes(const int number)
{
	if(number <= 1)
		return;

	if(number % 2 == 0)
		primes.push_back(2);

	for(int i=3; i*i < number; i+=2)
	{
		
	}
}

int main()
{
  std::cout << "Hello World!";

  int number = 13195;
  findPrimes(number);

  copy(primes.begin(),primes.end(), ostream_iterator<int>(cout, " "));
}