#include<bits/stdc++.h>

using namespace std;

long long mod = 1e9 + 7;
long long luy_thua(long long n, long long k){
	if (k == 1){
		return n;
	}
	long long x = luy_thua(n, k / 2);
	if (k % 2 == 0){
		return (x * x) % mod;
	}
	else{
		return (((x * x) % mod) *n) % mod;
	}
}
int main(){
	int t;
	cin >> t;
	while (t--){
		int n,k;
		cin >> n >> k;
		cout << luy_thua(n,k) << "\n";
	}
}
