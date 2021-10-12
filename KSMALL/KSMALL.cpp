#include <iostream>
#include <queue>

using namespace std;

unsigned array[5000000];

void randomize(unsigned a, unsigned b, unsigned mod)
{
    for (int i = 0; i < 5000000; i++)
    {
        a = 31014 * (a & 65535) + (a >> 16);
        b = 17508 * (b & 65535) + (b >> 16);
        array[i] = ((a << 16) + b) % mod;
    }
}

int main()
{
    unsigned a, b, mod, K;
    cin >> a >> b >> mod >> K;
    randomize(a, b, mod);


    return 0;
}