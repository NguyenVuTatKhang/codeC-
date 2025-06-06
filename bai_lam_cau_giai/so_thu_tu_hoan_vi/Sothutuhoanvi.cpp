#include <bits/stdc++.h>

using namespace std;

int n, a[10], b[10];
bool check()
{
    for (int i = 1; i <= n; i++)
        if (a[i] != b[i])
            return 0;
    return 1;
}
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int t;
    cin >> t;
    while (t--)
    {
        int p = 0;
        cin >> n;
        for (int i = 1; i <= n; i++)
        {
            a[i] = i;
            cin >> b[i];
        }
        while (++p)
        {
            if (check())
            {
                cout << p << "\n";
                break;
            }
            for (int i = n - 1; i >= 1; i--)
            {
                if (a[i] < a[i + 1])
                {
                    sort(a + i + 1, a + n + 1);
                    for (int j = i + 1; j <= n; j++)
                    {
                        if (a[j] > a[i])
                        {
                            swap(a[i], a[j]);
                            break;
                        }
                    }
                    break;
                }
            }
        }
    }
}
