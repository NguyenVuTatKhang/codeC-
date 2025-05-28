#include <bits/stdc++.h>

using namespace std;

int main(){
    int t;
    cin >> t;
    cin.ignore();
    while (t--){
        string s, x = "";
        stack<string> st;
        getline(cin, s);
        s += ' ';
        for (int i = 0; i < s.size(); i++){
            if (s[i] == ' '){
                if (x != ""){
                    st.push(x);
                    x = "";
                }
            }
            else
                x += s[i];
        }
        while (st.size()){
            cout << st.top() << " ";
            st.pop();
        }
        cout << "\n";
    }
}
