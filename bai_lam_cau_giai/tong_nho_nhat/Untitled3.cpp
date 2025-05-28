#include <bits/stdc++.h>

using namespace std;

int main(){
	int t;
	cin >> t;
	while (t--){
		int n;
		cin >> n;
		int a[n];
		for (int i = 0; i < n; i++){
			cin >> a[i];
		}
		long long b = 0,c = 0;
		sort (a, a + n);
		for (int i = 0; i < n; i+=2){
			b = b * 10 + a[i];
		}
		for (int i = 1; i < n; i+=2){
			c = c * 10 + a[i];
		}
		cout << b + c << "\n";
	}
}
