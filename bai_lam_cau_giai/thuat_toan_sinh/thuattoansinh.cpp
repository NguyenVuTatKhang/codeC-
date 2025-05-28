#include <iostream>
#include <vector>

using namespace std;

int main() {
    int n;
    cin >> n;

    int len = (n + 1) / 2;
    vector<int> s(len, 0);

    while (true) {
        // In d?y ð?i x?ng
        for (int i = 0; i < len; i++) {
            cout << s[i] << " ";
        }
        for (int i = len - 1; i >= 0; i--) {
            cout << s[i] << " ";
        }
        cout << endl;

        // Sinh t? h?p nh? phân k? ti?p
        int i = len - 1;
        while (i >= 0 && s[i] == 1) {
            s[i] = 0;
            i--;
        }

        if (i < 0) 
            break;
        
        s[i] = 1;
    }

    return 0;
}
