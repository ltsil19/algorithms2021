#include <iostream>
#include <string>
#include <math.h>

using namespace std;

struct Employee
{
    int superior;
    long long salary;
};

const string EMPLOYEE = "employee";
const string DEPARTMENT = "department";

Employee *arr;
long long *seg;

inline long long averageOfTwo(long long a, long long b)
{
    if (a == 0)
    {
        return b;
    }
    else if (b == 0)
    {
        return a;
    }
    else
    {
        return (a + b) / 2;
    }
}

void buildTree(int curr, int l, int r)
{
    if (l == r)
    {
        seg[curr] = arr[l].salary;
    }
    else
    {
        int mid = (l + r) / 2;
        buildTree(curr * 2, l, mid);
        buildTree(curr * 2 + 1, mid + 1, r);
        seg[curr] = averageOfTwo(seg[curr * 2], seg[curr * 2 + 1]);
    }
}

int main()
{
    int n, q, s;
    cin >> n >> q >> s;

    arr = new Employee[n];
    seg = new long long[4 * n + 1];

    arr[0].salary = s;
    arr[0].superior = -1;

    for (size_t i = 1; i < n; i++)
    {
        cin >> arr[i].superior >> arr[i].salary;
    }

    buildTree(1, 0, n - 1);

    for (size_t i = 0; i < q; i++)
    {
        string TYPE;
        int x;
        long long y, z;
        cin >> TYPE >> x >> y >> z;
        if (TYPE == EMPLOYEE)
        {
            // TODO
        }
        else
        {
            // TODO
        }
    }

    for (size_t i = 1; i < n * 4 + 1; i++)
    {
        cout << seg[i] << endl;
    }

    return 0;
}