#include <bits/stdc++.h>

using namespace std;

int main(){
	int t;
	cin >> t;
	while (t--){
		int d;
		cin >> d;
		string s;
		cin >> s;
		int a[30] = {}, ma = 0;
		for (int i = 0; i < s.size(); i++){
			a[s[i] - 'A']++;
		}
		for (int i = 0; i < 30; i++){
			ma = max(a[i], ma);
		}
		if (ma * d > s.size() + 1){
			cout << "-1" << "\n";
		}
		else 
			cout << "1" << "\n";
	}
}
