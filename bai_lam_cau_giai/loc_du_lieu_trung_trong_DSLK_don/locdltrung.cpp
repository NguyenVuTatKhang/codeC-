#include <bits/stdc++.h>
using namespace std;

int c = 0;

// C?u trúc d? li?u danh sách liên k?t
struct node {
    int data;
    node *next;
};

// Hàm t?o m?t nút m?i
node *makeNode(int x) {
    node *newNode = new node();
    newNode->data = x;
    newNode->next = NULL;
    return newNode;
}

// Hàm thêm ph?n t? vào cu?i danh sách
void pushBack(node **head, int x) {
    node *newNode = makeNode(x);
    node *tmp = *head;

    if (*head == NULL) {
        *head = newNode;
        return;
    }

    while (tmp->next != NULL) {
        tmp = tmp->next;
    }

    tmp->next = newNode;
}

// Hàm hi?n th? danh sách liên k?t
void display(node *head) {
    while (head != NULL) {
        cout << head->data << " ";
        head = head->next;
    }
}

// Hàm ð?m s? ph?n t? trong danh sách liên k?t
int size(node *head) {
    int cnt = 0;
    while (head != NULL) {
        ++cnt;
        head = head->next;
    }
    return cnt;
}

// Hàm xóa ph?n t? ð?u tiên c?a danh sách
void popFront(node **head) {
    if (*head == NULL) return;
    node *tmp = *head;
    *head = tmp->next;
    delete tmp;
}

// Hàm xóa ph?n t? t?i v? trí `pos`
void remove(node **head, int pos) {
    int n = size(*head);
    if (pos < 1 || pos > n) return;

    if (pos == 1) {
        popFront(&*head);
    } else {
        node *tmp = *head;
        for (int i = 1; i <= pos - 2; i++) {
            tmp = tmp->next;
        }
        node *k = tmp->next;
        tmp->next = k->next;
        delete k;
    }
}

// Hàm xóa ph?n t? ð?u tiên có giá tr? `val`
void solve(node **head, int val) {
    int cnt = 1;
    node *tmp = *head;

    while (tmp != NULL) {
        if (tmp->data == val) {
            remove(head, cnt);
            c = 1;
            return;
        }
        ++cnt;
        tmp = tmp->next;
    }
}

int main() {
    node *head = NULL;
    int n, k;

    // Nh?p s? ph?n t?
    cin >> n;
    for (int i = 1; i <= n; i++) {
        int x;
        cin >> x;
        pushBack(&head, x);
    }

    // Nh?p giá tr? c?n xóa
    cin >> k;

    // Xóa t?t c? các ph?n t? có giá tr? `k`
    while (1) {
        c = 0;
        solve(&head, k);
        if (c == 0) break;
    }

    // Hi?n th? danh sách k?t qu?
    display(head);

    return 0;
}
