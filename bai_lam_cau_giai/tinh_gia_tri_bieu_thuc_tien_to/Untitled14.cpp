#include <bits/stdc++.h>

using namespace std;

bool Var(char c){
    return (c >= '1' && c <= '9');
}
int main(){
    int t;
    cin >> t;
    while (t--){
        string s;
        cin >> s;
        int st[s.size()] = {}, p = -1;
        for (int i = s.size() - 1; i >= 0; i--){
            if (Var(s[i])){
                st[++p] = s[i] - '0';
                continue;
            }
            if (s[i] == '*'){
                st[p - 1] = st[p] * st[p - 1];
                p--;
                continue;
            }
            if (s[i] == '/'){
                st[p - 1] = st[p] / st[p - 1];
                p--;
                continue;
            }
            if (s[i] == '+'){
                st[p - 1] = st[p] + st[p - 1];
                p--;
                continue;
            }
            if (s[i] == '-'){
                st[p - 1] = st[p] - st[p - 1];
                p--;
                continue;
            }
        }
        cout << st[0] << "\n";
    }
}
