#include <bits/stdc++.h>

using namespace std;

int nam(string s){
	int n = 0;
	for (int i = 0; i < s.size(); i ++){
		if (s[i] == '6'){
			s[i] = '5';
		}
		n = n * 10 + s[i] -'0';
	}
	return n;
}

int sau(string s){
	int n = 0;
	for (int i = 0; i < s.size(); i++){
		if (s[i] == '5'){
			s[i] = '6';
		}
		n = n * 10 + s[i] -'0';
	}
	return n;
}

int main(){
	string a,b;
	cin >> a >> b;
	cout << nam(a) + nam(b) << " " << sau(a) + sau(b);
}
