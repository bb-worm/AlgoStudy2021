#include <stdio.h>
#include <string>
#include <vector>
#include <unordered_map>

using namespace std;

int main() {
    int K, L;
    scanf("%d %d", &K, &L);

    unordered_map<string, int> idmap;
    vector<string> ids;

    char id[9];
    for (int i=0; i<L; i++) {
        scanf("%s", id);
        auto it = idmap.find(id);
        if (it != idmap.end()) // already exist
            ids[it->second] = "";
        idmap[id] = i;
        ids.push_back(id);
    }
    
    int cnt = 0;
    for (auto& id : ids) {
        if (id == "")
            continue;
        printf("%s\n", id.c_str());
        cnt++;
        if (cnt >= K)
            break;
    }
}