#include <bits/stdc++.h>

using namespace std;

int dp[901][8101];

int Cook(int a, int b){
	if (a > b || a < 0 || b < 0 || a > 900 || b > 8100){
		return -1;
	}
	if (a == 0 && b == 0){
		return 0;
	}
	if (dp[a][b] != -1){
		return dp[a][b];
	}
	int n = 101;
	for (int i = 9; i >= 1; i--){
		int tmp = Cook(a - i, b - i * i);
		if (tmp != -1){
			n = min(n, tmp + 1);
		}
	}
	return dp[a][b] = n;
}
int main(){
	int t;
	cin >> t;
	while (t--){
		int a, b;
		cin >> a >> b;
		memset (dp, -1, sizeof(dp));
		dp[0][0] = 0;
		int c = Cook(a,b);
		if(c == -1 || c > 100){
			cout << -1 << "\n";
			continue;
		}
		while (a > 0&& b > 0){
			for(int i = 1; i <= 9; i++){
				if(a >= i && b >= i*i && 1 + dp[a - i][b - i*i] == dp[a][b]){
					cout << i;
					a -= i; 
					b -= i*i;
					break;
				}
			}
		}
		cout << "\n";
	}
}
