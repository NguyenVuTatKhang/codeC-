#include<bits/stdc++.h>

using namespace std;

int main(){
	int t;
	cin >> t;
	while (t--){
		int n, x, ans = 0;
		cin >> n >> x;
		int a[n];
		for (int i = 0; i < n; i++){
			cin >> a[i];
		}
		for (int i = 0; i < n; i++){
			if (a[i] == x){
				ans++;
			}
		}
		if (ans == 0){
			cout << "-1" << "\n";
		}
		else
			cout << ans << "\n";
	}
}
