#include <bits/stdc++.h>

using namespace std;

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int t;
	cin >> t;
	while (t--){
		int n, b;
		cin >> n;
		vector<int> a(n);
		stack<vector<int>> st;
		for (int i = 0; i < n; i++)
			cin >> a[i];
		for (int i = 0; i < n - 1; i++){
			bool k = false;
			for (int j = 0; j < n - i - 1; j++){
				if (a[j] > a[j + 1]){
					swap(a[j], a[j + 1]);
					k = true;
				}
			}
			if (k == false)
				break;
			st.push(a);
		}
		b = st.size();
		while (st.size()){
			a = st.top();
			st.pop();
			cout << "Buoc " << b-- << ": ";
			for (int j = 0; j < n; j++)
				cout << a[j] << " ";
			cout << endl;
		}
	}
}
