#include <iostream>
#include <string>
#include <vector>
#include <unordered_map>
#include <algorithm>

using namespace std;


#define DST_INFO vector<pair<string, bool>>

bool find_ans = false;
void dfs(string src, int idx, unordered_map<string, DST_INFO>& paths, vector<string>& ans) {
    if (idx == ans.size()) {
        find_ans = true;
        return;
    }
    if (find_ans)
        return;

    for (auto& next : paths[src]) {
        string dst = next.first;

        if (next.second)
            continue;
        next.second = true;
        ans[idx] = dst;
        dfs(dst, idx+1, paths, ans);
        if (find_ans)
            return;
        next.second = false;
    }
}

vector<string> solution(vector<vector<string>> tickets) {
    // make paths
    unordered_map<string, DST_INFO> paths;
    for (auto& ticket : tickets) {
        string src = ticket[0];
        string dst = ticket[1];

        auto it = paths.find(src);
        if (it == paths.end())
            paths[src] = DST_INFO();
        
        paths[src].push_back({dst, false});
    }

    // sort
    for (auto& path : paths)
        sort(path.second.begin(), path.second.end());

    // dfs
    vector<string> ans(tickets.size() + 1);
    ans[0] = "ICN";
    dfs("ICN", 1, paths, ans);
    return ans;
}

int main() {
    vector<vector<string>> tickets = {{"ICN", "SFO"}, 
                                      {"ICN", "ATL"},
                                      {"SFO", "ATL"}, 
                                      {"ATL", "ICN"}, 
                                      {"ATL", "SFO"}};
    vector<string> ans = solution(tickets);
    for (auto s : ans)
        cout << s << " ";
    cout << endl;
}