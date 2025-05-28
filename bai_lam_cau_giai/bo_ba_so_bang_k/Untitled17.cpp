#include <bits/stdc++.h>

using namespace std;

int main(){
	int t;
	cin >> t;
	while (t--){
		int n, k;
		cin >> n >> k;
		int a[n];
		string ans = "NO";
		for (int i = 0; i < n; i++)
			cin >> a[i];
		sort(a, a + n);
		for (int i = 0; i < n; i++){
			for (int j = i + 1; j < n; j++){
				if (binary_search(a + j + 1, a + n, k - a[i] - a[j])){
					ans = "YES";
					break;
				}
			}
			if (ans == "YES")
				break;
		}
		cout << ans << endl;
	}
}
