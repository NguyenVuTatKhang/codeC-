#include <bits/stdc++.h>

using namespace std;
int n, a[100];
bool check(){
    for (int i = 2; i <= n - 1; i++)
        if ((a[i] == 1 || a[i] == 5) && 
        (a[i - 1] != 1 && a[i - 1] != 5) && 
        (a[i + 1] != 1 && a[i + 1] != 5))
            return 0;
    return 1;
}
int main(){
    char c;
    cin >> c;
    n = c - 'A' + 1;
    for (int i = 1; i <= n; i++)
        a[i] = i;
    while (1){
        if (check()){
            for (int i = 1; i <= n; i++)
                cout << (char)(a[i] + 'A' - 1);
            cout << "\n";
        }
        int ok = 0;
        for (int i = n - 1; i >= 1; i--){
            if (a[i] < a[i + 1]){
                ok = 1;
                sort(a + i + 1, a + n + 1);
                for (int j = i + 1; j <= n; j++){
                    if (a[j] > a[i]){
                        swap(a[i], a[j]);
                        break;
                    }
                }
                break;
            }
        }
        if (ok == 0)
            break;
    }
}
