#include <bits/stdc++.h>
using namespace std;

struct Node {
    int val;
    Node* left;
    Node* right;
    Node(int x) : val(x), left(NULL), right(NULL) {}
};

void insert(Node*& root, int x) {
    if (!root) {
        root = new Node(x);
        return;
    }
    if (x < root->val) insert(root->left, x);
    else insert(root->right, x);
}

void NRL(Node* root, vector<int>& res) {
    if (!root) return;
    res.push_back(root->val);      // Node
    NRL(root->right, res);         // Right
    NRL(root->left, res);          // Left
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int T; cin >> T;
    while (T--) {
        int N; cin >> N;
        vector<int> A(N);
        for (int i = 0; i < N; i++) cin >> A[i];

        Node* root = nullptr;
        root = new Node(A[0]);
        for (int i = 1; i < N; i++) {
            insert(root, A[i]);
        }

        vector<int> res;
        NRL(root, res);
        for (int i = 0; i < (int)res.size(); i++) {
            cout << res[i];
            if (i < (int)res.size() - 1) cout << " ";
        }
        cout << "\n";

        // Gi?i phóng b? nh? (tu? ch?n)
        // có th? dùng hàm d? quy d? xóa cây n?u c?n
    }
    return 0;
}
