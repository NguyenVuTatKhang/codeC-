#include<bits/stdc++.h>

using namespace std;

bool cmp(int a, int b){
	return a > b;
}

int main(){
	int n, i1 = 0, i2 = 0;
	cin >> n;
	int a[n];
	vector <int> c,l;
	for (int i = 0; i < n; i++){
		cin >> a[i];
		if (i % 2 == 0){
			c.push_back(a[i]);
		}
		else 
			l.push_back(a[i]);
	}
	sort(c.begin(), c.end());
	sort(l.begin(), l.end(), cmp);
	for (int i = 0; i < n; i++){
		if (i % 2 == 0){
			cout << c[i1++] << " ";
		}
		else 
			cout << l[i2++] << " ";
	}
}
