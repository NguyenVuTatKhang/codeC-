#include <bits/stdc++.h>

using namespace std;

int main(){
	int t;
	cin >> t;
	while (t--){
		int n, k;
		cin >> n >> k;
		int a[n];
		long long s = 0;
		map<int, long long> m;
		for (int i = 0; i < n; i++){
			cin >> a[i];
			m[a[i]]++;
		}
		for (auto i : m){
			if (i.first * 2 == k)
				s += i.second * (i.second - 1);
			else
				s += i.second * m[k - i.first];
		}
		cout << s / 2 << "\n";
	}
}
