#include <bits/stdc++.h>

using namespace std;

int main(){
    int t;
    cin >> t;
    while (t--){
        string s;
        cin >> s;
        stack<pair<char, int>> st;
        int ans = 0, n = s.size();
        vector<int> F(n, 0);
        for (int i = 0; i < n; i++){
            if (s[i] == ')' && !st.empty() && st.top().first == '('){
                F[i] = F[i - 1];
                if (st.top().second != 0)
                    F[i] += F[st.top().second - 1];
                F[i] += 2;
                st.pop();
            }
            else
                st.push({s[i], i});
        }
        for (int i = 0; i < n; i++)
            ans = max(ans, F[i]);
        cout << ans << "\n";
    }
}
