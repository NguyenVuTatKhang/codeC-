#include <bits/stdc++.h>
#define endl "\n"
using namespace std;
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n, k, x;
    cin >> n >> k;
    int a[k + 1];
    vector<int> b;
    map<int, int> m;
    for (int i = 0; i < n; i++)
    {
        cin >> x;
        m[x]++;
    }
    b.push_back(0);
    for (auto i : m)
        b.push_back(i.first);
    n = b.size() - 1;
    for (int i = 1; i <= k; i++)
        a[i] = i;
    while (1)
    {
        for (int i = 1; i <= k; i++)
            cout << b[a[i]] << " ";
        cout << endl;
        int ok = 0;
        for (int i = k; i >= 1; i--)
        {
            if (a[i] != n - k + i)
            {
                ok = 1;
                a[i]++;
                for (int j = i + 1; j <= k; j++)
                    a[j] = a[j - 1] + 1;
                break;
            }
        }
        if (ok == 0)
            break;
    }
}
