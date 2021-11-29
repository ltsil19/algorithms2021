#include <iostream>
#include <memory.h>
#include <string.h>

using namespace std;

#define mod 1000000007

long long memo[100009];
int l[100000];

int main()
{
    int T;
    cin >> T;

    while (T--)
    {
        memset(memo, 0, sizeof memo);
        memset(l, 0, sizeof l);
        string str;
        cin >> str;
        int len = str.length();

        memo[0] = 1;
        for (int i = 1; i <= len; i++)
        {
            memo[i] = (memo[i - 1] * 2) % mod;
            if (l[str[i - 1]] != 0)
            {
                memo[i] = (memo[i] - memo[l[str[i - 1]] - 1] + mod) % mod;
            }
            l[str[i - 1]] = i;
        }
        cout << memo[len] << endl;
    }

    return 0;
}