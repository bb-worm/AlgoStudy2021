// https://programmers.co.kr/learn/courses/30/lessons/43164?language=cpp

#include <stdio.h>
#include <string>
#include <vector>
#include <unordered_map>
#include <algorithm>

using namespace std;

unordered_map<string, vector<int>> ports; // 특정 공항이 출발지인 티켓들의 인덱스를 저장
vector<bool> is_use; // 티켓 사용 여부
vector<string> ans;

bool DFS(string, int, vector<vector<string>>&);

vector<string> solution(vector<vector<string>> tickets) {
    // 알파벳 순서대로 탐색을 해야 하는데, 이차원 벡터도 그냥 정렬하면 차례대로 비교해서 정렬해주는 것 같음
    // 이러면 정렬 시간복잡도가 O(NlgN)인데, 전체에 대해서 정렬하지 않고 출발지가 같은 티켓만 정렬해서 복잡도 줄일 수도 있음 
    sort(tickets.begin(), tickets.end());
    
    // 출발지 공항 기준으로 티켓들의 인덱스 저장해줌
    for (int i=0; i<tickets.size(); i++) {
        vector<string> ticket = tickets[i];
        if (ports.find(ticket[0]) == ports.end())
            ports[ticket[0]] = vector<int>();
        ports[ticket[0]].push_back(i);
        is_use.push_back(false);
    }

    // 시작 지점은 ICN
    string begin = "ICN";
    ans.push_back(begin);
    DFS(begin, 0, tickets);

    return ans;
}

// 음.. 시간복잡도를 어떻게 계산해야 될지 잘 모르겠음
// 단순히 생각하면 티켓 길이를 E라고 할 때, 티켓을 껴넣는 경우의 수니까 O(E!)일 거 같은데 그것보단 복잡도 낮을 거 같음
// 찾아보니 한붓그리기 알고리즘이랑 비슷한 거 같은데 이건 시간복잡도가 O(NE)라고 함
bool DFS(string start_port, int use_num, vector<vector<string>>& tickets) {
    if (use_num >= tickets.size())
        return true;

    // 시작 공항에서 사용할 수 있는 티켓 순회
    for (int i=0; i<ports[start_port].size(); i++) {
        int port_idx = ports[start_port][i];
        if (is_use[port_idx]) // 이미 사용한 티켓 체크
            continue;
        is_use[port_idx] = true;
        string next_port = tickets[port_idx][1];
        ans.push_back(next_port);
        if (DFS(next_port, use_num+1, tickets)) // 정답 찾았으면 그대로 return
            return true;
        is_use[port_idx] = false;
        ans.pop_back();
    }
    return false;
}

int main() {
    // vector<vector<string>> tickets = {
    //                                   {"ICN", "SFO"}, 
    //                                   {"ICN", "ATL"},
    //                                   {"SFO", "ATL"},
    //                                   {"ATL", "ICN"},
    //                                   {"ATL", "SFO"}
    //                                   };
    vector<vector<string>> tickets = {
                                      {"ICN", "BBB"}, 
                                      {"ICN", "CCC"},
                                      {"BBB", "CCC"},
                                      {"CCC", "BBB"},
                                      {"CCC", "ICN"}
                                      };
    vector<string> ans = solution(tickets);
    for (auto& port : ans) {
        printf("%s ", port.c_str());
    }
}