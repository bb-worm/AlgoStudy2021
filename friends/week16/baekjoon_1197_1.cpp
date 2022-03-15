// prim algorithm

#include <iostream>
#include <vector>
#include <limits.h>

using namespace std;

struct Node {
    int weight = INT_MAX;
    bool visit = false;
    vector<pair<Node*, int>> next;
};

Node* select_smallest_node(vector<Node*> nodes) {
    Node* smallest = nullptr;
    for (int i=0; i<nodes.size(); i++) {
        if (nodes[i]->visit)
            continue;

        if (smallest == nullptr || smallest->weight > nodes[i]->weight)
            smallest = nodes[i];
    }
    return smallest;
}

void relaxation(Node* node) {
    for (int i=0; i<node->next.size(); i++) {
        pair<Node*, int> n = node->next[i];
        if (n.first->visit)
            continue;
        if (n.second < n.first->weight)
            n.first->weight = n.second;
    }
}

int main() {
    int V, E;
    scanf("%d %d", &V, &E);

    vector<Node*> nodes;
    for (int i=0; i<V; i++)
        nodes.push_back(new Node());

    int a, b, w;
    for (int i=0; i<E; i++) {
        scanf("%d %d %d", &a, &b, &w);
        nodes[a-1]->next.push_back(make_pair(nodes[b-1], w));
        nodes[b-1]->next.push_back(make_pair(nodes[a-1], w));
    }

    for (int i=0; i<V; i++) {
        Node* smallest = select_smallest_node(nodes);
        if (i == 0)
            smallest->weight = 0;
        smallest->visit = true;
        relaxation(smallest);
    }

    int sum = 0;
    for (auto& node : nodes)
        sum += node->weight;
    
    printf("%d\n", sum);
}