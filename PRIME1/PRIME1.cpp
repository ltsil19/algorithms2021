#include <vector>
#include <iostream>
#include <math.h>

using namespace std;

const int MAX = 32000; // ~ sqrt of 1000000000

bool mark[MAX + 1];
vector<int> primes;

bool isPrime(int n)
{
    if (n <= MAX)
        return mark[n];

    int ceiling = (int)sqrt((double)n);
    for (int i = 0; i < primes.size(); i++)
    {
        int currPrime = primes[i];
        if (currPrime > ceiling)
        {
            break;
        }

        if (n % currPrime == 0)
        {
            return false;
        }
    }

    return true;
}

int main()
{
    mark[0] = false;
    mark[1] = false;

    for (int i = 2; i <= MAX; i++)
        mark[i] = true;

    for (int p = 2; p * p <= MAX; p++)
    {
        if (mark[p] == true)
        {
            for (int i = p * 2; i <= MAX; i += p)
                mark[i] = false;
        }
    }

    for (int i = 2; i <= MAX; i++)
    {
        if (mark[i])
        {
            primes.push_back(i);
        }
    }

    int t;
    cin >> t;
    for (int j = 0; j < t; j++)
    {
        int n, m;
        cin >> m >> n;

        for (int i = m; i <= n; i++)
        {
            if (isPrime(i))
            {
                printf("%d\n", i);
            }
        }

        if (j != t - 1)
        {
            printf("\n");
        }
    }
}
