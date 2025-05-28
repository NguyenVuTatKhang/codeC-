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
			if (a[i] == x){
				ans = 1;
			}
		}
		if (ans == 1){
			cout << ans << "\n";
		}
		else
			cout << "-1" << "\n";
	}
} 
