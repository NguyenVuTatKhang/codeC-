#include <bits/stdc++.h>

using namespace std;

int main(){
	string a;
	cin >> a;
	stack<char> a1, a2;
	for (int i = 0; i < a.length(); i++){
		if(a[i] == '<'){
			if (a1.size()){
				a2.push(a1.top());
				a1.pop();
			}
		}
		
		else if(a[i] == '>'){
			if (a2.size()){
				a1.push(a2.top());
				a2.pop();
			}
		}
		
		else if(a[i] == '-'){
			if (a1.size()){
				a1.pop();
			}
		}
		else {
			a1.push(a[i]);
		}
	}
	while (a1.size()){
		a2.push(a1.top());
		a1.pop();
	}
	while (a2.size()){
		cout << a2.top();
		a2.pop();
//		if (a2.top() == '<' || a2.top() == '>' || a2.top() == '-'){
//			a2.pop();			
//		}
//		else{
//			cout << a2.top();
//			a2.pop();
//		}
	}
}
