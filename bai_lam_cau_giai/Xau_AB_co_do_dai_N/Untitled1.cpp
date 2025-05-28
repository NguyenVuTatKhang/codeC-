#include<bits/stdc++.h>

using namespace std;

int main(){
	int t;
	cin >> t;
	while (t--){
		int n;
		cin >> n;
		string a;
		for(int i = 0; i < n; i++){
			a += 'A';
		}
		while (1){
			cout << a << " ";
			int check = 0;
			for(int i = n - 1; i >= 0; i--){
				if(a[i] == 'A'){
					a[i] = 'B';
					check = 1;
					for(int j = i + 1; j < n; j++){
						a[j] = 'A';
					}
					break;
				}
				
			}
			if(check == 0){
				break;
			}
		}
		cout << "\n";
	}
}
