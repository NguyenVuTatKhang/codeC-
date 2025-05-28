#include <bits/stdc++.h>
using namespace std;

int main() {
    int t;
    cin >> t;
    cin.ignore(); 

    while (t--) {
        int N;
        cin >> N;
        cin.ignore();

        string line;
        getline(cin, line);
        stringstream ss(line);

        string token;
        long long st[10005]; 
        int p = -1;

        while (ss >> token) {
            if (token == "+" || token == "-" || token == "*" || token == "/") {
                long long b = st[p--];
                long long a = st[p--]; 
                if (token == "+") st[++p] = a + b;
                else if (token == "-") st[++p] = a - b;
                else if (token == "*") st[++p] = a * b;
                else if (token == "/") st[++p] = a / b;
            } else {
                st[++p] = stoll(token); 
            }
        }

        cout << st[0] << "\n";
    }
}
