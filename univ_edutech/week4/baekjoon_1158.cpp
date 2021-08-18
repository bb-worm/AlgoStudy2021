#include <stdio.h>
#include <vector>

using namespace std;

struct Node {
    int num;
    Node* next;
};

int main() {
    int n, k;
    scanf("%d %d", &n, &k);

    vector<Node*> nodes;
    nodes.push_back(new Node());
    nodes[0]->num = 1;

    // make nodes
    for (int i=1; i<n; i++) {
        nodes.push_back(new Node());
        nodes[i]->num = i+1;
        nodes[i-1]->next = nodes[i];
    }
    nodes[n-1]->next = nodes[0]; // next of last node is first node

    // print nodes
    printf("<");
    Node* pre = nodes[n-1];
    Node* now = nodes[0];
    for (int i=0; i<n-1; i++) {
        for (int j=0; j<k-1; j++) {
            now = now->next;
            pre = pre->next;
        }
        printf("%d, ", now->num);

        now = now->next;
        pre->next = now;
    }
    printf("%d>\n", now->num);
    
    // free memory
    for (int i=0; i<n; i++)
        delete nodes[i];
}

/*
7 3

1 2 3 4 5 6 7
1 2   4 5 6 7
1 2   4 5   7
1     4 5   7
1     4 5   
1     4 
      4    
*/