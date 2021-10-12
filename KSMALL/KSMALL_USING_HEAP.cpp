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

void maxHeapFind(unsigned K)
{
    priority_queue<int> maxHeap;
    for (size_t i = 0; i < K; i++)
    {
        maxHeap.push(array[i]);
    }

    for (size_t i = K; i < 5000000; i++)
    {
        if (maxHeap.top() > array[i])
        {
            maxHeap.pop();
            maxHeap.push(array[i]);
        }
    }

    cout << maxHeap.top();
}

void minHeapFind(unsigned K)
{
    priority_queue<int, vector<int>, greater<int> > minHeap;
    for (size_t i = 0; i < 5000000 - K + 1; i++)
    {
        minHeap.push(array[i]);
    }

    for (size_t i = 5000000 - K + 1; i < 5000000; i++)
    {
        if (minHeap.top() < array[i])
        {
            minHeap.pop();
            minHeap.push(array[i]);
        }
    }

    cout << minHeap.top();
}

int main()
{
    unsigned a, b, mod, K;
    cin >> a >> b >> mod >> K;
    randomize(a, b, mod);

    if (K > 5000000 / 2)
    {
        minHeapFind(K);
    }
    else
    {
        maxHeapFind(K);
    }

    return 0;
}