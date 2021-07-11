// https://programmers.co.kr/learn/courses/30/lessons/1837

#include <iostream>
#include <vector>
#include <unordered_map>
#include <unordered_set>

using namespace std;

const int MAX_VAL = 101;

// 방문하지 않았을 경우: -2
// 답을 찾지 못하는 경우: -1
vector<vector<int>> visit;
unordered_map<int, vector<int>> connected;

int go(int, int, int, vector<int>);

int solution(int n, int m, vector<vector<int>> edge_list, int k, vector<int> gps_log) {
    // 연결 관계 만들어주기
    unordered_set<int> nums;
    for (auto& edge : edge_list) {
        connected[edge[0]].push_back(edge[1]);
        connected[edge[1]].push_back(edge[0]);
        nums.insert(edge[0]);
        nums.insert(edge[1]);
    }
    // 자기 자신도 연결관계 집어넣기
    for (auto& num : nums)
        connected[num].push_back(num);
    
    // 방문하지 않았다는 의미로 -2로 초기화
    for (int i=0; i<k; i++){
        vector<int> tmp(n+1, -2);
        visit.push_back(tmp);
    }
    
    // 재귀 시작!
    int ans = go(0, gps_log[0], k, gps_log);

    // 빈 자료형이랑 swap 해서 초기화해줌
    vector<vector<int>>().swap(visit);
    unordered_map<int, vector<int>>().swap(connected);

    return ans;
}

// 재귀 함수
// 현재 gps_log idx에 특정 num이 왔을 때를 다룸
int go(int idx, int num, int k, vector<int> gps_log) {
    // -2가 아니란 건 방문한 적이 있다는 뜻이니 visit에 저장해뒀던 값 return
    if (visit[idx][num] != -2)
        return visit[idx][num];

    // 끝 지점
    // 마지막 지점은 고정되어 있으므로, 해당 지점과 같은 숫자인지 확인
    // 같으면 0을 return
    // 다르면 -1을 return : 갈 수 없는 경로라는 의미
    if (idx == k-1) {
        if (gps_log[idx] == num)
            return visit[idx][num] = 0;
        else
            return visit[idx][num] = -1;
    }

    // 중간 탐색 지점
    // 현재 num과 연결된 지점을 다음 지점으로 설정했을 때 결과를 받아옴
    // 갈 수 없는 경로(-1)가 아니라면 min_result가 수정이 됨
    int min_result = MAX_VAL;
    for (auto& next : connected[num]) {
        int result = go(idx+1, next, k, gps_log);
        if (result != -1)
            min_result = min(min_result, result);
    }

    // min_result가 수정되지 않았다면, 현재 idx의 num으론 갈 수 없는 경로라는 의미
    if (min_result == MAX_VAL)
        min_result = -1;
    // 기존 idx의 num과 다르다면 수정이 필요하단 의미이므로 min_result에 1 더해줌
    else if (gps_log[idx] != num)
        min_result += 1;

    // idx 위치의 num을 방문했을 때의 결과를 넣어주고 return
    return visit[idx][num] = min_result;
}

int main() {
    int n = 7;
    int m = 10;
    vector<vector<int>> edge_list = {{1, 2}, {1, 3}, {2,3}, {2, 4}, {3, 4}, 
                                    {3, 5}, {4, 6}, {5, 6}, {5, 7}, {6, 7}};
    int k = 6;
    vector<int> gps_log = {1, 2, 3, 3, 6, 7};

    int ans = solution(n, m, edge_list, k, gps_log);
    cout << ans << endl;
}