#include <bits/stdc++.h>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n, k;
    cin >> n >> k;
    string x;
    vector<string> a;
    map<string, int> m;
    cin.ignore();
    for (int i = 0; i < n; i++)
    {
        cin >> x;
        m[x]++;
    }
    for (auto i : m)
        a.push_back(i.first);
    n = a.size();
    a.insert(a.begin(), 1, "");
    int dd[k + 1];
    for (int i = 1; i <= k; i++)
        dd[i] = i;
    while (1)
    {
        for (int i = 1; i <= k; i++)
            cout << a[dd[i]] << " ";
        cout << "\n";
        int ok = 0;
        for (int i = k; i >= 1; i--)
        {
            if (dd[i] != n - k + i)
            {
                ok = 1;
                dd[i]++;
                for (int j = i + 1; j <= k; j++)
                    dd[j] = dd[j - 1] + 1;
                break;
            }
        }
        if (ok == 0)
            return 0;
    }
}
