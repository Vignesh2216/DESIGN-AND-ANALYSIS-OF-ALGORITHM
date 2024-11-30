// You are using GCC
#include <bits/stdc++.h>
using namespace std;
struct HuffmanNode {
    int data;
    char c;
    HuffmanNode *left;
    HuffmanNode *right;
    HuffmanNode(char character, int frequency) {
        c = character;
        data = frequency;
        left = right = nullptr;
    }
};
struct Compare {
    bool operator()(HuffmanNode* left, HuffmanNode* right) {
        return left->data > right->data;
    }
};
void printCode(HuffmanNode* root, string str) {
    if (!root)
        return;
    if (!root->left && !root->right && isalpha(root->c)) {
        cout << root->c << ": " << str << endl;
    }
    printCode(root->left, str + "0");
    printCode(root->right, str + "1");
}
int main() {
    int n;
    cin >> n;
    vector<char> charArray(n);
    vector<int> charfreq(n);
    for (int i = 0; i < n; i++) {
        cin >> charArray[i];
    }

    for (int i = 0; i < n; i++) {
        cin >> charfreq[i];
    }
    priority_queue<HuffmanNode*, vector<HuffmanNode*>, Compare> pq;
    for (int i = 0; i < n; i++) {
        pq.push(new HuffmanNode(charArray[i], charfreq[i]));
    }
    HuffmanNode* root = nullptr;
    while (pq.size() > 1) {
        HuffmanNode* left = pq.top();
        pq.pop();
        HuffmanNode* right = pq.top();
        pq.pop();
        HuffmanNode* sum = new HuffmanNode('-', left->data + right->data);
        sum->left = left;
        sum->right = right;
        pq.push(sum);
        root = sum;
    }
    printCode(root, "");
    return 0;
}