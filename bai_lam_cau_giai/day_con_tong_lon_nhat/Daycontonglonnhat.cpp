#include <bits/stdc++.h>
using namespace std;

int n, q;
int a[100000];
int t[100000 * 4];

void tao(int v, int l, int r) {
    if (l == r) {
        t[v] = a[l];
    } else {
        int m = (l + r) / 2;
        tao(2 * v, l, m);
        tao(2 * v + 1, m + 1, r);
        t[v] = t[2 * v] + t[2 * v + 1];
    }
}

int sql(int v, int tl, int tr, int l, int r) {
    if (l > r) 
        return 0;

    if (tl == l && tr == r) {
        return t[v];
    } else {
        int tm = (tl + tr) / 2;
        int s1 = sql(2 * v, tl, tm, l, min(r, tm));
        int s2 = sql(2 * v + 1, tm + 1, tr, max(l, tm + 1), r);
        return s1 + s2;
    }
}

int main() {
    cin >> n >> q;

    for (int i = 0; i < n; i++) {
        int x;
        cin >> x;
        a[i] = (x > 0) ? x : 0;
    }

    tao(1, 0, n - 1);

    while (q--) {
        int l, r;
        cin >> l >> r;
        cout << sql(1, 0, n - 1, l - 1, r - 1) << endl;
    }
}
