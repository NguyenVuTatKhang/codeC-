#include<bits/stdc++.h>

using namespace std;

int main() {
	int t; cin >> t;
	while (t--) {
		int n; cin >> n;
		queue<int> X;
		while (n--) {
			int a; cin >> a;
			if (a == 1)
				cout << X.size() << "\n";
			if (a == 2) {
				if (X.empty())
					cout << "YES\n";
				else 
					cout << "NO\n";
			}
			if (a == 3) {
				int b; cin >> b; X.push(b);
			}
			if (a == 4) {
				if (X.size())
					X.pop();
			}
			if (a == 5) {
				if (X.empty())
					cout << -1 << "\n";
				else 
					cout << X.front() << "\n";
			}
			if (a == 6) {
				if (X.empty())
					cout << -1 << "\n";
				else 
					cout << X.back() << "\n";
			}
		}
	}
}
