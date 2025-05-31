#include <bits/stdc++.h>

using namespace std;

int a[10] = {1, 2, 3, 5, 8, 13, 21, 34, 55, 89};
int b[10] = {0, 1, 2, 4, 7, 12, 20, 33, 54, 88};

string bi(int n, int a){
	string s = "";
	if (a == 0){
		for (int i = 0; i < n; i++){
			s += '0';
		}
	}
	while (a > 0){
		if (a % 2 == 0){
			s = '0' + s;
		}
		else {
			s = '1' + s;
		}
		a = a/2;
	}
	while (s.size() < n){
			s = '0' + s;
	}
	return s;
}

int main(){
	int n, x = 1, y = 1;
	string s;
	cin >> n;
	for (int i = 0; i < n; i++){
		x = 2 * x;
	}
	for (int i = 0; i < 10; i++){
		if (x >= b[i]){
			y = i;
		}
	}
	for (int i = 0; i <= y; i++){
		s = bi(n, b[i]);
		cout << a[i] << ": ";
		for (int j =0; j < s.size(); j++){
			cout << s[j] << " ";
		}
		cout << "\n";
	}
}
