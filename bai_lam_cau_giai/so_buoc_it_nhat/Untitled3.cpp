#include<bits/stdc++.h>

using namespace std;

int main(){
	int t;
	cin >> t;
	while (t--){
		int n;
		cin >> n;
		int a[n], l[n], s = 0;
		for (int i = 0; i < n; i++){
			cin >> a[i];
			l[i] = 1;
			for (int j = 0; j < i; j++){
				if (a[i] >= a[j] && l[i] <= l[j]){
					l[i] = l[j] + 1;
				}
			}
			s = max (s,l[i]);
		}
		cout << n - s << "\n";
	}
}
