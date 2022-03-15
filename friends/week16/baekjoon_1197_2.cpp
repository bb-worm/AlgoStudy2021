// kruskal algorithm

#include <iostream>
#include <vector>
#include <queue>

using namespace std;

struct Node {
    Node(int num) : num(num) {}
    int num;
    Node* parent = nullptr;
};

struct Edge {
    Edge(int weight, Node* left, Node* right) 
    : weight(weight), left(left), right(right) {}
    int weight;
    Node* left;
    Node* right;
};

struct cmp {
    bool operator()(Edge* a, Edge* b) {
        return a->weight > b->weight;
    }
};

Node* find_root(Node* node) {
    if (node->parent == nullptr)
        return node;
    return node->parent = find_root(node->parent);
}

int main() {
    int V, E;
    scanf("%d %d", &V, &E);

    vector<Node*> nodes;
    for (int i=0; i<V; i++)
        nodes.push_back(new Node(i));

    priority_queue<Edge*, vector<Edge*>, cmp> pq;
    int a, b, w;
    for (int i=0; i<E; i++) {
        scanf("%d %d %d", &a, &b, &w);
        pq.push(new Edge(w, nodes[a-1], nodes[b-1]));
    }

    int sum = 0;
    Edge* edge;
    while (!pq.empty()) {
        edge = pq.top();
        pq.pop();

        Node* left_root = find_root(edge->left);
        Node* right_root = find_root(edge->right);

        // already connected
        if (left_root->num == right_root->num)
            continue;
        
        // connect
        left_root->parent = right_root;
        sum += edge->weight;
    }

    printf("%d\n", sum);
}