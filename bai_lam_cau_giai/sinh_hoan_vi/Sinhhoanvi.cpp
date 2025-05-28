#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

void inra(int a[], int n) {
    for (int i = 0; i < n; i++) {
        cout << a[i];
    }
    cout << " ";
}

void sinh(int n) {
    int a[n];

    for (int i = 0; i < n; i++) 
        a[i] = i + 1;

    do {
        inra(a, n);
    } while (next_permutation(a, a + n));
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
