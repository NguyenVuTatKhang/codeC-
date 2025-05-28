#include<bits/stdc++.h>

using namespace std;

int main(){
	int t;
	cin >> t;
	while (t--){
		int n, min1 = 1e9, min2 = 1e9;
		cin >> n;
		vector<int> a(n);
		for (int i = 0; i < n; i++)
		{
			cin >> a[i];
			min1 = min(min1, a[i]);
		}
		for (int i = 0; i < n; i++)
		{
			if (a[i] < min2 && a[i] > min1)
				min2 = a[i];
		}
		if (min2 == 1e9)
			cout << -1 << "\n";
		else
			cout << min1 << " " << min2 << "\n";
	}
}
