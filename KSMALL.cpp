#include <iostream>

using namespace std;

const int MAX = 5000000;

unsigned array[MAX];

void randomize(unsigned a, unsigned b, unsigned mod)
{
    for (int i = 0; i < MAX; i++)
    {
        a = 31014 * (a & 65535) + (a >> 16);
        b = 17508 * (b & 65535) + (b >> 16);
        array[i] = ((a << 16) + b) % mod;
    }
}

int partition(int l, int r)
{
    int x = array[r], i = l;
    for (int j = l; j <= r - 1; j++)
    {
        if (array[j] <= x)
        {
            swap(array[i], array[j]);
            i++;
        }
    }
    swap(array[i], array[r]);
    return i;
}

int quickSelectKthSmallest(int l, int r, int K)
{
    if (l == r)
    {
        return array[l];
    }

    int pivot = partition(l, r);

    if (K == pivot)
    {
        return array[K];
    }
    else if (K < pivot)
    {
        return quickSelectKthSmallest(l, pivot - 1, K);
    }
    else
    {
        return quickSelectKthSmallest(pivot + 1, r, K);
    }

    return 0;
}

int main()
{
    unsigned a, b, mod, K;
    cin >> a >> b >> mod >> K;
    randomize(a, b, mod);

    cout << quickSelectKthSmallest(0, MAX - 1, K);

    return 0;
}