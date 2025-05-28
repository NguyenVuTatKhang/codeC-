#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

void inra(vector<int>& a, int n) {
    for (int i = 0; i < n; i++) {
        cout << a[i];
    }
    cout << " ";
}

void sinh(int n) {
    vector<int> a(n);

    for (int i = 0; i < n; i++) {
        a[i] = n - i;
    }

    do {
        inra(a, n);
    } while (prev_permutation(a.begin(), a.end()));
}

void test() {
    int n;
    cin >> n;
    sinh(n);
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
