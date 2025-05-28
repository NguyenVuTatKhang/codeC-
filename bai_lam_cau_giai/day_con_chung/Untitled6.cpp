#include<bits/stdc++.h>

using namespace std;

int main(){
	int t;
	cin >> t;
	while (t--){
		int n,m,k;
		cin >> n >> m >> k;
		long long a[n], b[m], c[k];
		for (int i = 0; i < n; i++){
			cin >> a[i];
		}
		for (int i = 0; i < m; i++){
			cin >> b[i];
		}
		for (int i = 0; i < k; i++){
			cin >> c[i];
		}
		vector <long long> o;
		int d = 0,e = 0,f = 0;
		while (d < n && e < m && f < k){
			if (a[d] == b[e] && b[e] == c[f]){
				o.push_back(a[d]);
				d++;
				e++;
				f++;
			}
			else if (a[d] < b[e]){
				d++;
			}
			else if (b[e] < c[f]){
				e++;
			}
			else
				f++;
		}
		if (o.size() == 0){
			cout << "NO";
		}
		else{
			for (int i = 0; i < o.size(); i++){
				cout << o[i] << " ";
			}
		}
		cout << "\n";
	}
}
