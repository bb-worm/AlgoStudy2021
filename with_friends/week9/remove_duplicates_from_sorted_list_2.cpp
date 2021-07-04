#include <iostream>

using namespace std;

 struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};


// 입력으로 들어온 ListNode 순회하면서 중복되지 않은 노드 값을 정답에 넣어줌

// 한 번만 순회하면 되므로 시간 복잡도 O(n)

// 공간 복잡도가 애매한데, 만약 head에 들어있는 노드 그대로 사용한다면 추가로 필요한 노드는 O(1)일 것 같음
// 그런데 이러면 입력으로 들어온 노드의 영향을 많이 받으므로 그냥 새로 생성해서 할당해줬음. 이러면 O(n)
class Solution {
public:
    ListNode* deleteDuplicates(ListNode* head) {
        ListNode* ans = nullptr; // 이거 안해주면 빈 head 들어왔을 때 런타임 에러 남
        ListNode* point = nullptr;
        bool isHead = true;

        ListNode *now = head; // now를 이용하여 한 번만 순회
        while (now != nullptr) {
            int val = now->val;
            int cnt = 0;
            
            while (val == now->val) { // 다음 노드 순회하면서 값이 같을 때까지 반복
                cnt++;
                now = now->next;
                if (now == nullptr) break;
            }

            if (cnt == 1) { // 만약 중복된 값이 없는 노드였다면 정답에 넣어줌
                // ans의 처음 부분인지 아닌지 체크할 방법이 딱히 떠오르지 않아서 이렇게 처리함
                if (isHead) { // ans의 처음 부분이면 ans에 바로 ListNode 할당해줌
                    ans = new ListNode(val);
                    point = ans;
                    isHead = false;
                } else { // 처음 부분이 아니면 point를 이용해서 다음 노드에 ListNode 할당
                    point->next = new ListNode(val);
                    point = point->next;
                }
            }
        }
        return ans;
    }
};


int main() {
    Solution s = Solution();

    // make test data
    int headVal[5] = {1, 1, 1, 2, 3};
    ListNode* head = new ListNode(headVal[0]);
    ListNode* pre = head;
    for (int i=1; i<5; i++) {
        ListNode *node = new ListNode(headVal[i]);
        pre->next = node;
        pre = node;
    }

    // run
    ListNode *listnode = s.deleteDuplicates(head);

    // free memory
    ListNode* next;
    while (head != nullptr) {
        next = head->next;
        delete head;
        head = next;
    }
    while (listnode != nullptr) {
        next = listnode->next;
        delete next;
        listnode = next;
    }
}