#include <iostream>
#include <string>
#include <queue>
#include <unordered_map>

using namespace std;

int main() {
    unordered_map<string, int> tree_map;
    priority_queue<string, vector<string>, greater<string>> tree_q;

    string tree;
    int total_tree = 0;
    while (getline(cin, tree)) {
        auto it = tree_map.find(tree);
        if (it == tree_map.end()) {
            tree_map[tree] = 0;
            tree_q.push(tree);
        }
        tree_map[tree] += 1;
        total_tree++;
    }

    while (!tree_q.empty()) {
        string t = tree_q.top();
        tree_q.pop();
        printf("%s %.4f\n", t.c_str(), float(tree_map[t])/total_tree*100);
    }
}