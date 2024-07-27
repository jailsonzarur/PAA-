#include <bits/stdc++.h>

using namespace std;

const int MAX = 1e6 + 10;

int e1, e2;
int x1, x2;
int l1[MAX];
int l2[MAX];
int t1[MAX];
int t2[MAX];
int memo1[MAX];
int memo2[MAX];

int f2(int k);

int f1(int k)
{
    if(memo1[k] != -1)
        return memo1[k];
    if (k >= 1)
        return memo1[k] = min(f1(k - 1), f2(k - 1) + t2[k - 1]) + l1[k];
    if (k == 0)
        return memo1[k] = e1 + l1[k];
}

int f2(int k)
{
    if(memo2[k] != -1)
        return memo2[k];
    if (k >= 1)
        return memo2[k] = min(f2(k - 1), f1(k - 1) + t1[k - 1]) + l2[k];
    if (k == 0)
        return memo2[k] = e2 + l2[k];
}

int f(int k)
{
    return min(f1(k - 1) + x1, f2(k - 1) + x2);
}

int main()
{
    int n;
    while (cin >> n)
    {
        cin >> e1 >> e2;
        for (int i = 0; i < n; i++)
        {
            cin >> l1[i];
        }

        for (int i = 0; i < n; i++)
        {
            cin >> l2[i];
        }

        for (int i = 0; i < n - 1; i++)
        {
            cin >> t1[i];
        }

        for (int i = 0; i < n - 1; i++)
        {
            cin >> t2[i];
        }

        cin >> x1 >> x2;

        fill(memo1, memo1 + n, -1);
        fill(memo2, memo2 + n, -1);

        cout << f(n) << endl;
    }
}