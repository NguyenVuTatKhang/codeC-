#include <iostream>
#include <cstring>
using namespace std;

int n, a[21][21];
int f[1 << 20];

bool checkbit(int i, int mask) {
    return (mask >> (i - 1)) & 1;
}

int getbit(int c, int k, int mask) {
    if (c == 1) 
        mask = mask | (1 << (k - 1));
    else 
        mask = mask & (~(1 << (k - 1)));
    return mask;
}

void solve() {
    f[0] = 0;

    for (int i = 1; i <= n; i++) {
        for (int mask = 1; mask <= (1 << n) - 1; mask++) {
            if (__builtin_popcount(mask) == i) {
                for (int j = 1; j <= n; j++) {
                    if (checkbit(j, mask)) {
                        int pre_mask = getbit(0, j, mask);
                        f[mask] = max(f[mask], f[pre_mask] + a[i][j]);
                    }
                }
            }
        }
    }

    cout << f[(1 << n) - 1] << endl;
}

int main() {
    int t;
    cin >> t;

    while (t--) {
        cin >> n;

        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= n; j++) {
                cin >> a[i][j];
            }
        }

        memset(f, 0, sizeof(f));

        solve();
    }
}
