#include <iostream>
#include <vector>
using namespace std;

vector<int> findprime(int n)
{
    vector<int> prime(n + 1, 1);

    for (int i = 2; i * i <= n; i++)
    {
        if (prime[i] == 1)
        {
            for (int j = i * i; j <= n; j += i)
            {
                prime[j] = 0;
            }
        }
    }
    vector<int> primes;
    for (int i = 2; i <= n; i++)
        if (prime[i] == 1)
            primes.push_back(i); // all prime numbers

    return primes;
}
