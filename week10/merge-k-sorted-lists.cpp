#include <iostream>
#include <vector>
#include <queue>

using namespace std;


 // Definition for singly-linked list.
 struct ListNode {
    int val;
     ListNode *next;
     ListNode() : val(0), next(nullptr) {}
     ListNode(int x) : val(x), next(nullptr) {}
     ListNode(int x, ListNode *next) : val(x), next(next) {}
     };


class Solution {
public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        priority_queue<int, vector<int>, greater<int>> pq;

        for (auto &node : lists) {
            ListNode* now = node;
            while (now != nullptr) {
                pq.push(now->val);
                now = now->next;
            }
        }

        if (pq.size() == 0)
            return nullptr;

        ListNode* ans = new ListNode(pq.top());
        pq.pop();

        ListNode* now = ans;
        while (!pq.empty()) {
            now->next = new ListNode(pq.top());
            now = now->next;
            pq.pop();
        }

        return ans;
    }
};

class Solution2 {
public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        priority_queue<ListNode*, vector<ListNode*>, cmp> pq;

        int size = lists.size();
        for (int i=0; i<size; i++) {
            if (lists[i] == nullptr)
                continue;
            pq.push(lists[i]);
        }

        if (pq.empty())
            return nullptr;

        // make head of ans
        ListNode* ans = pq.top();
        pq.pop();
        if (ans->next != nullptr)
            pq.push(ans->next);

        ListNode* now = ans;
        // make body of ans
        while (!pq.empty()) {
            now->next = pq.top();
            pq.pop();
            if (now->next->next != nullptr)
                pq.push(now->next->next);
            now = now->next;
        }
        return ans;
    }

    struct cmp {
        bool operator()(ListNode* a, ListNode* b) {
            return a->val > b->val;
        }
    };
};


int main() {
    // test data
    vector<ListNode*> lists;
    lists.push_back(new ListNode(1));
    lists[0]->next = new ListNode(4);
    lists[0]->next->next = new ListNode(5);
    lists.push_back(new ListNode(1));
    lists[1]->next = new ListNode(3);
    lists[1]->next->next = new ListNode(4);
    lists.push_back(new ListNode(2));
    lists[2]->next = new ListNode(6);

    //run
    Solution s = Solution();
    s.mergeKLists(lists);
    Solution2 s2 = Solution2();
    ListNode* ans = s2.mergeKLists(lists);
    
    ListNode* now = ans;
    while (now != nullptr) {
        cout << now->val << " ";
        now = now->next;
    }

    // free memory
    // for (auto &node : lists) {
    //     ListNode* now = node;
    //     ListNode* next = nullptr;
    //     while (now != nullptr) {
    //         next = now->next;
    //         delete now;
    //         now = next;
    //     }
    // }
}