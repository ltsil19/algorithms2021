#include <iostream>
#include <string>

using namespace std;

string input;
int len;

int i, j;
int n, m;

int memo[1000][1000];
int out[1000][1000];

void printOutput(int i, int j)
{
    if (i > j)
    {
        return;
    }

    if (i == j)
    {
        if (input[i] == '(' || input[i] == ')')
            cout << "()";
        else
            cout << "[]";
    }
    else
    {
        if (out[i][j] == 0)
        {
            if (input[i] == '(' && input[j] == ')')
            {
                cout << '(';
                printOutput(i + 1, j - 1);
                cout << ')';
            }

            if (input[i] == '[' && input[j] == ']')
            {
                cout << '[';
                printOutput(i + 1, j - 1);
                cout << ']';
            }
        }

        if (out[i][j] > 0)
        {
            printOutput(i, out[i][j]);
            printOutput(out[i][j] + 1, j);
        }

        if (out[i][j] == -1)
        {
            if (input[i] == '[')
            {
                cout << input[i];
                printOutput(i + 1, j);
                cout << ']';
            }
            if (input[i] == '(')
            {
                cout << input[i];
                printOutput(i + 1, j);
                cout << ')';
            }
        }
        if (out[i][j] == -2)
        {
            if (input[i] == ']')
            {
                cout << '[';
                printOutput(i, j - 1);
                cout << input[i];
            }
            if (input[i] == ')')
            {
                cout << '(';
                printOutput(i, j - 1);
                cout << input[i];
            }
        }
    }
}

int main()
{
    cin >> input;
    len = input.length();

    for (int i = len; i >= 1; i--)
    {
        input[i] = input[i - 1];
    }

    for (int i = 1; i <= len; i++)
    {
        memo[i][i] = 1;
    }

    for (m = 1; m < len; m++)
        for (i = 1; i <= len - m; i++)
        {
            j = i + m;
            memo[i][j] = INT_MAX;
            if ((input[i] == '(' && input[j] == ')') || (input[i] == '[' && input[j] == ']'))
            {
                memo[i][j] = memo[i + 1][j - 1];
                out[i][j] = 0;
            }
            for (int k = i; k < j; k++){

                if (memo[i][k] + memo[k + 1][j] < memo[i][j])
                {
                    memo[i][j] = memo[i][k] + memo[k + 1][j];
                    out[i][j] = k;
                }
            }

            if (input[i] == '(' || input[i] == '['){
                if (memo[i + 1][j] + 1 < memo[i][j])
                {
                    memo[i][j] = memo[i + 1][j] + 1;
                    out[i][j] = -1;
                }
            }
            if (input[i] == ')' || input[i] == ']'){
                if (memo[i][j - 1] + 1 < memo[i][j])
                {
                    memo[i][j] = memo[i][j - 1] + 1;
                    out[i][j] = -2;
                }
            }
        }

    printOutput(1, len);
    return 0;
}