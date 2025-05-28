#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

void inra(vector<int>& a, int n) {
    for (int i = 0; i < n; i++) {
        if (a[i]) 
            cout << i + 1;
    }
    cout << " ";
}

void sinh(int n, int k) {
    vector<int> a(k, 1); // k s? 1
    a.resize(n, 0);      // n - k s? 0

    do {
        inra(a, n);
    } while (prev_permutation(a.begin(), a.end()));
}

void test() {
    int n, k;
    cin >> n >> k;
    sinh(n, k);
}

int main() {
    int t;
    cin >> t;

    while (t--) {
        test();
        cout << endl;
    }

    return 0;
}
