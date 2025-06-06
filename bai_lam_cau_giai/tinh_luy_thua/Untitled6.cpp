#include<bits/stdc++.h>

using namespace std;
long long mod = 1e9 + 7;

long long test(long long n, long long k){
	if (k == 1){
		return n;
	}
	long long x = test (n, k/2);
	if (k % 2 == 0){
		return (x * x) % mod;
	}
	else {
		return (((x * x) % mod) * n) % mod;
	}
}

int main (){
	while (1){
		long long n,k;
		cin >> n >> k;
		if (n == 0 && k == 0){
			return 0;
		}
		if (k == 0){
			cout << "1" << "\n";
		}
		else {
			cout << test (n, k) << "\n";
		}
	}
}
