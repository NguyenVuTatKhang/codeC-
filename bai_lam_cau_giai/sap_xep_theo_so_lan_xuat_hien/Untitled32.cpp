#include <bits/stdc++.h>
#define endl "\n"
using namespace std;
bool cmp(pair<int, int> a, pair<int, int> b)
{
	if (a.second > b.second)
		return 1;
	if (a.second == b.second && a.first < b.first)
		return 1;
	return 0;
}
int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int t;
	cin >> t;
	while (t--)
	{
		int n;
		cin >> n;
		int a[n];
		map<int, int> ts;
		vector<pair<int, int>> p;
		for (int i = 0; i < n; i++)
		{
			cin >> a[i];
			ts[a[i]]++;
		}
		for (int i = 0; i < n; i++)
			p.push_back(make_pair(a[i], ts[a[i]]));
		sort(p.begin(), p.end(), cmp);
		for (int i = 0; i < p.size(); i++)
			cout << p[i].first << ' ';
		cout << endl;
	}
}
