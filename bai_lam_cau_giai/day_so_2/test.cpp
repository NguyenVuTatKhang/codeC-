#include <bits/stdc++.h>

using namespace std;

int main(){
	int t;
	cin >> t;
	while (t--){
		int n;
		cin >> n;
		int c = 0;
		for (int i = n; i > 0; i--){
			c = c + i;
		}
		cout << c << "\n";
	}
}
