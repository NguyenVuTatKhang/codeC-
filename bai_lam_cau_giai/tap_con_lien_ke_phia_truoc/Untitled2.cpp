#include <bits/stdc++.h>

using namespace std;

int main(){
	int t;
	cin >> t;
	while (t --){
		int n, k;
		cin >> n >> k;
		int a[k+1], cook = k - 1;
		for(int i = 1; i <= k; i++){
			cin >> a[i];
		}
		
		while (a[cook] + 1 == a[cook + 1]){
			cook --;
		}
		if(cook == 0){
			for (int i = n - k + 1; i <= n; i++){
				cout << i << " ";
			}
		}
		else {
			cook++;
			a[cook]--;
			for(int i = k; i > cook; i--){
				a[i] = n - k + i;
			}
			for(int i = 1; i <= k; i++){
				cout << a[i] << " ";
			}
		}
		cout << "\n";
	}
}
