#include <bits/stdc++.h>
using namespace std;

vector<int> fibonacci_up_to(int limit) {
    vector<int> fib = {1, 2};
    while (true) {
        int next = fib[fib.size() - 1] + fib[fib.size() - 2];
        if (next > limit) break;
        fib.push_back(next);
    }
    return fib;
}

string to_binary(int x, int n) {
    string res = "";
    while (x) {
        res = char('0' + (x % 2)) + res;
        x /= 2;
    }
    while (res.size() < n) res = "0" + res;
    return res;
}

int main() {
    int N;
    cin >> N;
    int total = 1 << N;
    vector<int> fib = fibonacci_up_to(total);

    set<int> fib_set(fib.begin(), fib.end());

    for (int i = 1; i <= total; i++) {
        if (fib_set.count(i)) {
            cout << i << ": ";
			string s = to_binary(i - 1, N);
			for (int j = 0; j < s.size(); j++){
				cout << s[j] << " ";
			}
			cout << "\n";
        }
    }
    return 0;
}
