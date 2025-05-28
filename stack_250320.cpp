#include <bits/stdc++.h>
using namespace std;

//Hay dung trong kiem soat bo nho vi dieu khien, Dang FILO: First In Last Out

int main(){
	stack <int> mystack;
	for (int i = 0; i<5; ++i){
		mystack.push(i*2);
	}	
	cout << "Thuc hien phep pop cac phan tu ...";
	while (!mystack.empty()){
		cout << ' ' << mystack.top();
		mystack.pop();
	}
	cout << '\n';
	return 0;
}


