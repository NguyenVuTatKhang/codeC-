#include <bits/stdc++.h>

using namespace std;

int main(){
	int t;
	cin >> t;
	while (t--){
		int n, k;
		cin >> n >> k;
		int a[n], b = 0, c = 0;
		for (int i = 0; i < n; i++){
			cin >> a[i];
		}
		sort (a, a + n);
		k = min (k, n - k);
		for (int i = 0; i < k; i++){
			b += a[i];
		}
		for (int i = k; i < n; i++){
			c += a[i];
		}
		cout << c - b << "\n";
	}
}
