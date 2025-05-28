#include<bits/stdc++.h>

using namespace std;

int n;
void Duck (string s){
	int k = s.size();
	if (n == k){
		if (s[n - 1] == '6')
			cout << s << "\n";
		return;
	}
	if (s[k - 1] == '8'){
		Duck(s + "6");
	}
	else {
		if (k < 4){
			Duck(s + "6");
		}
		else if (s[k - 2] == '8' || s[k - 3] == '8'){
			Duck(s + "6");
		}
		Duck(s + "8");
	}
}

int main(){
	cin >> n;
	Duck("8");
}
