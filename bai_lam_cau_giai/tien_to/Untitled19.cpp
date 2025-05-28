#include <bits/stdc++.h>
using namespace std;

long long applyOp(long long a, long long b, const string &op) {
    if (op == "+") return a + b;
    if (op == "-") return a - b;
    if (op == "*") return a * b;
    if (op == "/") return a / b; 
    return 0;
}

int main() {
    int T;
    cin >> T;
    cin.ignore();

    while (T--) {
        int N;
        cin >> N;
        cin.ignore();

        string line;
        getline(cin, line);
        stringstream ss(line);
        vector<string> tokens;
        string token;

        while (ss >> token) {
            tokens.push_back(token);
        }

        stack<long long> st;

        for (int i = tokens.size() - 1; i >= 0; i--) {
            string tok = tokens[i];
            if (tok == "+" || tok == "-" || tok == "*" || tok == "/") {
                long long a = st.top(); st.pop();
                long long b = st.top(); st.pop();
                st.push(applyOp(a, b, tok));
            } else {
                st.push(stoll(tok));
            }
        }

        cout << st.top() << "\n";
    }
}

