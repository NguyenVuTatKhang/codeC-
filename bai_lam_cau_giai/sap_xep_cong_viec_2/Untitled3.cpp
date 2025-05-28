#include <bits/stdc++.h>

using namespace std;

int main(){
	int t;
	cin >> t;
	while (t --){
		int a, b, c = 0, d = 0;
		cin  >> a;
		int check[a + 1] = {};
		vector<pair<int, int >> e(a+1);
		for(int i = 1; i <= a; i++){
			cin >> b >> e[i].second >> e[i].first;
		}
		sort (e.begin() + 1, e.end(), greater<pair<int, int >>());
		for (int i = 1; i <= a; i++){
			for (int j = min(a, e[i].second); j >= 1; j--){
				if(!check[j]){
					d += e[i].first;
					c++;
					check [j] = 1;
					break;
				}
			}
		}
		cout << c << " " << d << "\n";
	}
}
