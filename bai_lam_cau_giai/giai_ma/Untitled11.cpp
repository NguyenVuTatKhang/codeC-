#include <bits/stdc++.h>

using namespace std;

int main(){
	int t;
	cin >> t;
	while (t--){
		string s;
		cin >> s;
		s = ' ' + s;
		int n = s.size(), k;
		int a[n];
		a[0] = a[1] = 1;
		if (s[1] == '0'){
			cout << 0 << "\n";
			continue;
		}
		for (int i = 2; i < n; i++){
			if (s[i] == '0'){
				if (s[i - 1] > '2'){
					a[n - 1] = 0;
					break;
				}
				a[i] = 0;
			}
			else
				a[i] = a[i - 1];
			k = (s[i - 1] - '0') * 10 + s[i] - '0';
			if (k <= 26 && k >= 10)
				a[i] += a[i - 2];
		}
		cout << a[n - 1] << "\n";
	}
}
