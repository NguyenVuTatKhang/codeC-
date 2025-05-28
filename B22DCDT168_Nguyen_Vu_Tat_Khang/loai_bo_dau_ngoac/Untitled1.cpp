#include <bits/stdc++.h>

using namespace std;

int a = 0;
string b;

map <string, int> check;

bool kt(string t){
	if(t.size() < 2){
		return 0;
	}
	
	stack <int> m;
	
	for (int i = 0; i < t.size(); i++){
		if(t[i] == '('){
			m.push (1);
		}
		
		if(t[i] == ')'){
			if(m.empty()){
				return 0;
			}
			
			else{
				m.pop();
			}
		}
	}
	if(m.empty()){
		return 1;
	}
	return 0;
} 

void test (string c, int d){
	if (kt (c)) {
		if (c.size() > a){
			a = c.size();
			check.clear();
			check[c] ++;
		}
		if (c.size() == a){
			check[c]++;
		}
		return;
	}
	for(int i = d + 1; i < c.size(); i++){
		if (c[i] == '(' || c[i] == ')'){
			string x = c;
			x.erase(x.begin() + i, x.begin() + i + 1);
			test (x, i - 1);
		}
	}
}

int main(){
	int t;
	cin >> t;
	while (t--){
		a = 0;
		check.clear();
		cin >> b;
		test (b, -1);
		
		if(check.empty()){
			cout << -1;
		}
		else{
			for(auto i : check){
				cout << i.first << " ";
			}
		}
		cout << "\n";
	}
}
