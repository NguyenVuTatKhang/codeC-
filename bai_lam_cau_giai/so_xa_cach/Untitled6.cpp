#include<bits/stdc++.h>

using namespace std;

int n, check[15];
void Try(string s){
    int k = s.size();
    if (k == n)
        cout << s << "\n";
    for (int i = 1; i <= n; i++)
        if (k == 0 || (!check[i] && abs(s[k - 1] - '0' - i) != 1)){
            check[i] = 1;
            Try(s + to_string(i));
            check[i] = 0;
        }
}
int main (){
	int t;
	cin >> t;
	while (t--){
		cin >> n;
		Try("");
	}
}
