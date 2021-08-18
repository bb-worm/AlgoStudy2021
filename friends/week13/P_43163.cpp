// https://programmers.co.kr/learn/courses/30/lessons/43163

#include <stdio.h>
#include <string>
#include <vector>
#include <queue>

using namespace std;

struct node {
    string word; // 단어
    vector<node*> connect; // 연결된 노드들
    bool visit; // bfs 시에 방문 여부
};

void connect_all(vector<node*>&);
int BFS(string, string, vector<node*>&, queue<node*>);

int solution(string begin, string target, vector<string> words) {
    vector<node*> nodes; // 단어들을 node 구조체로 변환해서 담음
    queue<node*> q; // bfs에 사용할 큐
    
    // 시작하는 단어(begin) 노드를 생성
    node b = {begin, vector<node*>(), true};
    nodes.push_back(&b);
    q.push(&b); // 후에 bfs에 사용하기 위해 큐에 넣어줌

    // 단어들을 node 구조체로 바궈서 넣어줌
    bool contain_target = false;
    for (auto& word : words) {
        node* n = new node{word, vector<node*>(), false};
        nodes.push_back(n);
        if (word.compare(target) == 0)
            contain_target = true;
    }
    // 만약 단어 집합에 target이 없다면 바로 종료
    if (!contain_target)
        return 0;

    // 한 글자만 다르면 연결되어 있는 단어이므로 연결시켜줌
    connect_all(nodes);
    
    // 연결 정보 토대로 BFS 실행하고 단계 return
    return BFS(begin, target, nodes, q);
}

// N개의 단어에 대해 서로 체크하는 이중 반복문 O(N^2)
// 이중 반복문 안에서 단어 길이만큼 체크하므로 단어 길이가 K이면 O(K)
// 곱하면 O(K*N^2)
void connect_all(vector<node*>& nodes){
    for (int i=0; i<nodes.size()-1; i++) {
        for (int j=i+1; j<nodes.size(); j++) {
            int diff = 0;
            for (int k=0; k<nodes[i]->word.size() && diff<2; k++) {
                if (nodes[i]->word[k] != nodes[j]->word[k])
                    diff++;
            }
            // 한 글자만 다른 경우 연결
            if (diff == 1) {
                nodes[i]->connect.push_back(nodes[j]);
                nodes[j]->connect.push_back(nodes[i]);
            }
        }
    }
}

// 한 단어를 한 번씩 탐색한다고 볼 수 있으므로 단어가 N개이면 O(N)
int BFS(string begin, string target, vector<node*>& nodes, queue<node*> q) {
    int cnt = 0;
    while (!q.empty()) {
        int size = q.size();
        cnt++;
        for (int i=0; i<size; i++) {
            // 큐에 있는 노드 하나 빼줌
            node* now = q.front();
            q.pop();

            // 연결되어 있는 노드에 대해 체크
            for (auto& node : now->connect) {
                if (node->visit) // 방문 여부
                    continue;
                if (target.compare(node->word) == 0) { // target 단어 여부
                    return cnt;
                }
                q.push(node);
                node->visit = true;
            }
        }
    }
    return 0;
}

int main() {
    string begin = "hit";
    string target = "cog";
    vector<string> words = {"hot", "dot", "dog", "lot", "log", "cog"};

    int ans = solution(begin, target, words);
    printf("%d\n", ans);
}