#include <stdio.h>
#include <vector>

using namespace std;

struct Node {
    int num;
    int jump;
    Node* pre;
    Node* next;
};

int main() {
    int n;
    scanf("%d", &n);

    vector<Node*> nodes;
    int num, jump;

    // make nodes
    for (int i=0; i<n; i++) {
        scanf("%d", &jump);
        nodes.push_back(new Node());
        nodes[i]->num = i+1;
        nodes[i]->jump = jump;
    }
    // connect nodes
    for (int i=0; i<n; i++) {
        nodes[i]->pre = nodes[(i+n-1)%n];
        nodes[i]->next = nodes[(i+1)%n];
    }

    // print nodes
    Node* now = nodes[0];
    for (int i=0; i<n; i++) {
        printf("%d ", now->num);

        // pop now node
        now->pre->next = now->next;
        now->next->pre = now->pre;

        // move now node
        jump = now->jump;
        if (jump < 0) {
            jump *= -1;
            for (int j=0; j<jump; j++)
                now = now->pre;
        }
        else {
            for (int j=0; j<jump; j++)
                now = now->next;
        }
    }
}