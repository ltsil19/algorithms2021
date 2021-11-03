/*
    use c++ compiler
*/
#include <iostream>

using namespace std;

int *arr;
const int MAX_N = 30000;

int getParent(int x)
{
    return x == arr[x] ? x : arr[x] = getParent(arr[x]);
}

void joint(int x, int y)
{
    x = getParent(x);
    y = getParent(y);
    if (x != y)
    {
        arr[y] = x;
    }
}

void setFriends(int x, int y, int n)
{
    if (getParent(x) == getParent(y + n) || getParent(y) == getParent(x + n))
    {
        cout << -1 << endl;
    }
    else
    {
        joint(x, y);
        joint(x + n, y + n);
    }
}

void setEnemies(int x, int y, int n)
{
    if (getParent(x) == getParent(y) || getParent(x + n) == getParent(y + n))
    {
        cout << -1 << endl;
    }
    else
    {
        joint(x, y + n);
        joint(y, x + n);
    }
}

void areFriends(int x, int y, int n)
{
    if (getParent(x) == getParent(y) || getParent(x + n) == getParent(y + n))
    {
        cout << 1 << endl;
    }
    else
    {
        cout << 0 << endl;
    }
}

void areEnemies(int x, int y, int n)
{
    if (getParent(x) == getParent(y + n) || getParent(y) == getParent(x + n))
    {
        cout << 1 << endl;
    }
    else
    {
        cout << 0 << endl;
    }
}

void initArr(int n)
{
    for (size_t i = 0; i < MAX_N; i++)
    {
        arr[i] = i;
    }
}

int main()
{
    int n;
    cin >> n;
    arr = new int[MAX_N];
    initArr(n);

    while (true)
    {
        int operation, x, y;
        cin >> operation >> x >> y;
        if (operation == 0)
        {
            break;
        }
        else
        {
            switch (operation)
            {
            case 1:
                setFriends(x, y, n);
                break;
            case 2:
                setEnemies(x, y, n);
                break;
            case 3:
                areFriends(x, y, n);
                break;
            case 4:
                areEnemies(x, y, n);
                break;
            default:
                break;
            }
        }
    }

    return 0;
}
