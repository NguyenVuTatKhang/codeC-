#include <bits/stdc++.h>

using namespace std;

string s;
int a[1000], dd[1000] = {};
void Try(int n){
	for (int i = 0; i < s.size(); i++){
		if (!dd[i]){
			a[n] = i;
			dd[i] = 1;
			if (n == s.size() - 1){
				for (int i = 0; i < s.size(); i++){
					cout << s[a[i]];
				}
				cout << " ";
			}
			else {
				Try(n + 1);
			}
			dd[i] = 0;
		}
	}
}

int main(){
	int t;
	cin >> t;
	while (t--){
		cin >> s;
		Try(0);
		cout << "\n";
	}
} 
