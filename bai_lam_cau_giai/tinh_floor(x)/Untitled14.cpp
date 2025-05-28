#include <bits/stdc++.h>

using namespace std;

int main(){
	int t;
	cin >> t;
	while (t--){
		int n, x;
		cin >> n >> x;
		vector<long long> a(n + 2);
        for (int i = 0; i < n; i++)
            cin >> a[i];
        a[n + 1] = 1e18;
        int ans = lower_bound(a.begin(), a.end() - 1, x) - a.begin();
        if (a[ans] != x)
            ans--;
        if (ans != -1)
            ans++;
        cout << ans << endl;
	}
}
