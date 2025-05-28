#include <bits/stdc++.h>

using namespace std;

int main(){
	int t;
	cin >> t;
	while (t--){
		int n, a;
		cin >> n;
		long long s = 0;
		priority_queue <int, vector<int>, greater<int>> q;
		for (int i = 0; i < n; i++){
			cin >> a;
			q.push(a);
		}
		while (q.size() > 1){
			int b = q.top();
			q.pop();
			int c = q.top();
			q.pop();
			int k = b + c;
			s += k;
			q.push(k);
		}
		cout << s << "\n";
	}
}
