#include <bits/stdc++.h>
using namespace std;

class node {
private:
    int data;
    string alp;
    node *left;
    node *right;

public:
    node() : data(-1), left(nullptr), right(nullptr), alp("") {}
    node(string _alp, int _data) : alp{_alp}, data{_data}, left{nullptr}, right{nullptr} {}
    friend class tree;
};

class tree {
public:
    void init(int n);
    void set();
    void show();
    static bool compare(const node* a, const node* b);
    priority_queue<node*, vector<node*>, decltype(&tree::compare)> pq{&tree::compare};
};

bool tree::compare(const node* a, const node* b) {
    return a->data > b->data;
}

void tree::init(int n) {
    int f;
    string s;
    for (int i = 0; i < n; i++) {
        cout << "enter char and freq ";
        cin >> s >> f;
        node* x = new node(s, f);
        pq.push(x);
    }
}

void tree::set() {
    while (pq.size() != 1) {
        node* a = pq.top();
        pq.pop();

        node* b = pq.top();
        pq.pop();

        string newAlp = a->alp + b->alp;
        int newData = a->data + b->data;
        node* z = new node(newAlp, newData);
        z->left = a;
        z->right = b;

        pq.push(z);
    }
}

void tree::show() {
    node* r = pq.top();
    cout << "at start " << r->data << endl;
    while (r != NULL) {
        cout << "feq  " << r->data << endl;
        r = r->left;
    }
}

int main() {
    int n, i, j, k, l;
    cout << "no of characters: ";
    cin >> n;
    tree tr;
    tr.init(n);
    cout << "setting tree  " << endl;
    tr.set();
    cout << "setting done***********" << endl;
    tr.show();
    return 0;
}
