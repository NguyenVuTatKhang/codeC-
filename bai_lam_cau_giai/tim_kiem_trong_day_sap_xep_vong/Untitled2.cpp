#include<bits/stdc++.h>

using namespace std;

int main(){
	int t;
	cin >> t;
	while (t--){
		int n, x;
		cin >> n >> x;
		pair <int, int> a[n];
		for (int i = 0; i < n; i++){
			cin >> a[i].first;
			a[i].second = i + 1;
		}
		for (int i = 0; i < n; i++){
			if (a[i].first == x){
				cout << a[i].second << "\n";
			}
		}
	}
}
