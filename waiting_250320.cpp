//Cac thuat toan voi hang doi, theo quy tac FIFO: First In First Out
/*
Co 2 ham
- Cuoi vao
- Dau ra
Cac thao tac
- Khoi tao
- bool isEmpty()
- bool isFull()
- Enqueue(hoac push)
- Dequeue(hoac pop)
Su dung trong ky thuat BFS (tim kiem theo chieu sau)
*/

/*
Khai bao: queue <type> Q;

Cac phuong thuc co ban
- front(): Xem phan tu o dau
- back(): Xem phan tu o cuoi
- push(x): Them vao cuoi
- pop(): Xoa o dau
- empty()
- size()
*/

#include<bits/stdc++.h>
#include <queue>
using namespace std;

void showq(queue<int> Q){
	queue <int> newQ = Q;
	while (!newQ.empty()){
		cout << '\t' << newQ.front();
		newQ.pop();
	}
	cout << endl;
}


int main(){
	queue<int> Q;
	Q.push(10); 	Q.push(20);		Q.push(30);		Q.push(40);
	showq(Q);
	cout<< "Q.size():	" << Q.size() << endl;
	cout<< "Q.front():	" << Q.front() << endl;
	cout<< "Q.back():	" << Q.back() << endl;
	cout<< "Q.pop():	" << endl; Q.pop();
	cout<< "Remain:	";
	showq(Q);
}
