#include <bits/stdc++.h>

using namespace std;

int main() {
    int n;
    cin >> n;
    vector<int> a(n);

    for (int &x : a) cin >> x;

    sort(a.begin(), a.end());

    int max2 = max(a[n - 1] * a[n - 2], a[0] * a[1]); 
    int max3 = max({
        a[n - 1] * a[n - 2] * a[n - 3],     
        a[0] * a[1] * a[n - 1]              
    });

    cout << max(max2, max3) << endl;

    return 0;
}
