#include <bits/stdc++.h>
using namespace std;

int c = 0;

// C?u tr�c d? li?u danh s�ch li�n k?t
struct node {
    int data;
    node *next;
};

// H�m t?o m?t n�t m?i
node *makeNode(int x) {
    node *newNode = new node();
    newNode->data = x;
    newNode->next = NULL;
    return newNode;
}

// H�m th�m ph?n t? v�o cu?i danh s�ch
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

// H�m hi?n th? danh s�ch li�n k?t
void display(node *head) {
    while (head != NULL) {
        cout << head->data << " ";
        head = head->next;
    }
}

// H�m �?m s? ph?n t? trong danh s�ch li�n k?t
int size(node *head) {
    int cnt = 0;
    while (head != NULL) {
        ++cnt;
        head = head->next;
    }
    return cnt;
}

// H�m x�a ph?n t? �?u ti�n c?a danh s�ch
void popFront(node **head) {
    if (*head == NULL) return;
    node *tmp = *head;
    *head = tmp->next;
    delete tmp;
}

// H�m x�a ph?n t? t?i v? tr� `pos`
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

// H�m x�a ph?n t? �?u ti�n c� gi� tr? `val`
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

    // Nh?p gi� tr? c?n x�a
    cin >> k;

    // X�a t?t c? c�c ph?n t? c� gi� tr? `k`
    while (1) {
        c = 0;
        solve(&head, k);
        if (c == 0) break;
    }

    // Hi?n th? danh s�ch k?t qu?
    display(head);

    return 0;
}
