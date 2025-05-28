#include <bits/stdc++.h>
using namespace std;

int n, ok, a[100];
string s;

void ktao() {
    for (int i = 0; i < s.size(); i++) {
        a[i + 1] = s[i] - '0';
    }
}

void sinh() {
    int i = s.size();

    while (i > 0 && a[i] == 1) {
        a[i] = 0;
        i--;
    }

    if (i == 0) {
        for (int i = 1; i <= s.size(); i++) {
            cout << 0;
        }
        cout << endl;
        return;
    } else {
        a[i] = 1;
    }

    for (int j = 0; j < s.size(); j++) {
        cout << a[j + 1];
    }
    cout << endl;
}

int main() {
    int t;
    cin >> t;
    cin.ignore();

    while (t--) {
        getline(cin, s);
        ktao();
        sinh();
    }
}
