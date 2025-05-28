#include <bits/stdc++.h>

using namespace std;

int check(string s1, string s2){
	int f[s1.size() + 1][s2.size() + 1] = {};
	for (int i = 0; i < s1.size(); i++){
		for (int j = 0; j < s2.size(); j++){
			if (s1[i] == s2[j]){
				f[i + 1][j + 1] = f[i][j] + 1;
			}
			else {
				f[i + 1][j + 1] = max(f[i][j + 1], f[i + 1][j]);
			}
		}
	}
	return f[s1.size()][s2.size()];
}
int main(){
	int t;
	cin >> t;
	while (t--){
		string a,b;
		cin >> a >> b;
		cout << check(a,b) << "\n";
	}
}
