#include <iostream>
#include <string>
#include <vector>
#include <queue>

using namespace std;


struct Word {
    Word(string word) : word(word) {}
    string word;
    vector<Word*> connected;
    bool is_visit = false;
};

bool validate(Word w1, Word w2) {
    bool diff = false;
    for (int i=0; i<w1.word.size(); i++) {
        if (w1.word[i] == w2.word[i])
            continue;
        if (diff)
            return false;
        diff = true;
    }
    return true;
}

void connect(vector<Word>& words) {
    for (int i=0; i<words.size()-1; i++) {
        for (int j=i+1; j<words.size(); j++) {
            auto& w1 = words[i];
            auto& w2 = words[j];
            if (validate(w1, w2)) {
                w1.connected.push_back(&w2);
                w2.connected.push_back(&w1);
            }
        }
    }
}

int bfs(Word& begin, string target) {
    queue<Word*> q;
    q.push(&begin);
    begin.is_visit = true;

    int stage = 0;
    while (!q.empty()) {

        stage++;
        int size = q.size();
        for (int i=0; i<size; i++) {
            auto& now = q.front();
            q.pop();

            for (auto& next : now->connected) {
                if (next->is_visit)
                    continue;
                if (next->word == target)
                    return stage;
                q.push(next);
                next->is_visit = true;
            }
        }
     }
    return 0;
}

int solution(string begin, string target, vector<string> words) {
    // make Word nodes
    vector<Word> word_nodes;
    word_nodes.push_back(Word(begin));
    for (int i=0; i<words.size(); i++)
        word_nodes.push_back(Word(words[i]));

    // connect words
    connect(word_nodes);

    // get answer with bfs
    int ans = bfs(word_nodes[0], target);
    return ans;
}

int main() {
    string begin = "hit";
    string target = "cog";
    vector<string> words = {"hot", "dot", "dog", "lot", "log", "cog"};

    int ans = solution(begin, target, words);
    cout << ans << endl;
}