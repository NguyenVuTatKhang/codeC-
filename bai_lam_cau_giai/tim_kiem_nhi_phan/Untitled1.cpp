#include<bits/stdc++.h>

using namespace std;

int main(){
	int t;
	cin >> t;
	while (t--){
		int n,k;
		cin >> n >> k;
		int a[n];
		for(int i = 0; i < n; i++){
			cin >> a[i];
		}
		int b = lower_bound (a, a + n, k) - a;
		if (a[b] != k){
			cout << "NO" << "\n";
		}
		else 
			cout << b + 1<< "\n";
	}
}
