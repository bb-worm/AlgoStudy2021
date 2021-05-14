#include <iostream>
#include <unordered_map>
#include <vector>
#include <algorithm>
#include <stack>
#include <queue>

using namespace std;

struct Node {
    int num;
    vector<int> connected_num;
    bool visit;
};

int N, M, V;

unordered_map<int, Node> nodes;

void set_input() {
    cin >> N >> M >> V;

    int node_num1, node_num2;
    for (int i=0; i<M; i++) {
        cin >> node_num1 >> node_num2;
        if (nodes.find(node_num1) == nodes.end()) {
            Node node;
            node.num = node_num1;
            node.visit = false;
            nodes.insert(make_pair(node_num1, node));
        }
        if (nodes.find(node_num2) == nodes.end()) {
            Node node;
            node.num = node_num2;
            node.visit = false;
            nodes.insert(make_pair(node_num2, node));
        }
        nodes.find(node_num1)->second.connected_num.push_back(node_num2);
        nodes.find(node_num2)->second.connected_num.push_back(node_num1);
    }
    // sort
    for (auto it=nodes.begin(); it!=nodes.end(); it++)
        sort(it->second.connected_num.begin(), it->second.connected_num.end());
    // no connected node from V
    if (nodes.find(V) == nodes.end()) {
        Node node;
        node.num = V;
        node.visit = false;
        nodes.insert(make_pair(V, node));
    }
}

void dfs_recursive(Node* node) {
    cout << node->num << ' ';
    node->visit = true;

    for (auto node_num : node->connected_num) {
        Node* next_node = &(nodes.find(node_num)->second);
        if (next_node->visit == true)
            continue;
        dfs_recursive(next_node);
    }
}

void dfs_stack() {
    stack<Node*> s;
    s.push(&(nodes.find(V)->second));
    
    while (!s.empty()) {
        Node* now = s.top();
        s.pop();
        if (now->visit)
            continue;
        
        cout << now->num << ' ';
        now->visit = true;

        for (auto it=now->connected_num.rbegin(); it!=now->connected_num.rend(); it++) {
            Node* next = &(nodes.find(*it)->second);
            if (nodes.find(*it)->second.visit)
                continue;
            s.push(next);
        }
    }
}

void bfs() {
    queue<Node*> q;
    q.push(&(nodes.find(V)->second));
    nodes.find(V)->second.visit = true;

    while (!q.empty()) {
        Node* now = q.front();
        q.pop();

        cout << now->num << ' ';
        
        for (auto it=now->connected_num.begin(); it!=now->connected_num.end(); it++) {
            Node* next = &(nodes.find(*it)->second);
            if (next->visit)
                continue;
            q.push(next);
            next->visit = true;
        }
    }
}

void reset_visit() {
    for (auto it=nodes.begin(); it!=nodes.end(); it++)
        it->second.visit = false;
}

int main() {
    set_input();
    // dfs_recursive(&nodes.find(V)->second);
    // cout << endl;
    dfs_stack();
    cout << endl;
    reset_visit();
    bfs();
}