#include <iostream>
#include <string>
#include <vector>
#include <unordered_map>

using namespace std;

int solution(vector<vector<string>> clothes) {
    // distribute clothes
    unordered_map<string, vector<string>> cloth_sort;
    for (auto& v  : clothes) {
        // if (cloth_sort.find(v[1]) == cloth_sort.end()) {}
        //     cloth_sort[v[1]] = vector<string>();
        cloth_sort[v[1]].push_back(v[0]);
    }

    int ans = 1;
    for (auto& it : cloth_sort)
        ans *= (it.second.size() + 1);

    return ans - 1;
}

int main () {
    vector<vector<string>> clothes = {{"yellowhat", "headgear"}, {"bluesunglasses", "eyewear"}, {"green_turban", "headgear"}};
    auto ans = solution(clothes);
    cout << ans << endl;
}