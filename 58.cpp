// You are using GCC
#include<bits/stdc++.h>
using namespace std;
struct HuffmanNode {
    int data;
    char c;
    HuffmanNode* left;
    HuffmanNode* right;
};

struct MyComparator {
    bool operator()(HuffmanNode* l, HuffmanNode* r) {
        return (l->data > r->data);
    }
};

void printCode(HuffmanNode* root, string s) {
    if (!root)
        return;
       
    if(root->c != '#')
        cout<<root->c<<":"<<s<<endl;

    printCode(root->left, s + "0");
    printCode(root->right, s + "1");
}

int main() {
    int n;
    cin >> n;
    char charArray[n];
    int charfreq[n];
    for (int i = 0; i < n; i++) {
        cin >> charArray[i];
    }
    for (int i = 0; i < n; i++) {
        cin >> charfreq[i];
    }
    priority_queue<HuffmanNode*, vector<HuffmanNode*>, MyComparator> q; //Max Heap
    for (int i = 0; i < n; i++) {
        HuffmanNode* hn = new HuffmanNode();
        hn->c = charArray[i];
        hn->data = charfreq[i];
        hn->left = nullptr;
        hn->right = nullptr;
        q.push(hn);
    }
    HuffmanNode* root = nullptr;
    while (q.size() > 1) {
        HuffmanNode* x = q.top();
        q.pop();
        HuffmanNode* y = q.top();
        q.pop();
        HuffmanNode* f = new HuffmanNode();
        f->data = x->data + y->data;
        f->c = '#';
        f->left = x;
        f->right = y;
        root = f;
        q.push(f);
    }
    printCode(root, "");
    return 0;
}