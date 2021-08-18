#include <iostream>
#include <vector>

using namespace std;

struct Node {
    char name;
    Node* leftChild;
    Node* rightChild;
};

void print_preorder(vector<Node*>&, Node*);
void print_inorder(vector<Node*>&, Node*);
void print_postorder(vector<Node*>&, Node*);

int main() {
    int N;
    cin >> N;

    // make nodes
    vector<Node*> nodes;
    for (int i=0; i<N; i++) {
        nodes.push_back(new Node{char('A'+i), nullptr, nullptr});
    }
    // get input and make children
    for (int i=0; i<N; i++) {
        char parent, leftChild, rightChild;
        cin >> parent >> leftChild >> rightChild;

        if (leftChild != '.')
            nodes[int(parent - 'A')]->leftChild = nodes[int(leftChild - 'A')];
        if (rightChild != '.')
            nodes[int(parent - 'A')]->rightChild = nodes[int(rightChild - 'A')];
    }

    print_preorder(nodes, nodes[0]); cout << endl;
    print_inorder(nodes, nodes[0]); cout << endl;
    print_postorder(nodes, nodes[0]); cout << endl;
}

void print_preorder(vector<Node*>& nodes, Node* now) {
    if (now == nullptr)
        return;
    cout << now->name;
    print_preorder(nodes, now->leftChild);
    print_preorder(nodes, now->rightChild);
}

void print_inorder(vector<Node*>& nodes, Node* now) {
    if (now == nullptr)
        return;
    print_inorder(nodes, now->leftChild);
    cout << now->name;
    print_inorder(nodes, now->rightChild);
}

void print_postorder(vector<Node*>& nodes, Node* now) {
    if (now == nullptr)
        return;
    print_postorder(nodes, now->leftChild);
    print_postorder(nodes, now->rightChild);
    cout << now->name;
}