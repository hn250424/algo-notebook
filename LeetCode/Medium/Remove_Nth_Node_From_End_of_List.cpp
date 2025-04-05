// Given the head of a linked list, remove the nth node from the end of the list and return its head.

// Example 1:
// Input: head = [1,2,3,4,5], n = 2
// Output: [1,2,3,5]

// Example 2:
// Input: head = [1], n = 1
// Output: []

// Example 3:
// Input: head = [1,2], n = 1
// Output: [1]

// Constraints:
// The number of nodes in the list is sz.
// 1 <= sz <= 30
// 0 <= Node.val <= 100
// 1 <= n <= sz

// Follow up: Could you do this in one pass?

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */

 #include <vector>
 #include <iostream>
 
using namespace std;

struct ListNode {
    int val;
    ListNode* next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode* cur = head;
        ListNode* jmp = cur;

        for (int i = 0; i < n; i++) {
            jmp = jmp->next;
        }

        if (! jmp) return head->next;

        while (1) {
            if (! jmp->next) {
                if (cur->next->next) cur->next = cur->next->next;
                else cur->next = nullptr;
                break;
            }

            cur = cur->next;
            jmp = jmp->next;
        }

        return head;
    }
};

int main() {
    // g.
    vector<ListNode*> v_head = {
        new ListNode(1, new ListNode(2, new ListNode(3, new ListNode(4, new ListNode(5))))),
        new ListNode(1, new ListNode(2)),
        new ListNode(1),
        new ListNode(1, new ListNode(2)),
    };
    vector<int> v_n = {2, 1, 1, 2};

    Solution s;
    for (int i = 0; i < v_head.size(); i++) {
        ListNode* answer = s.removeNthFromEnd(v_head[i], v_n[i]);    
        cout << "answer: ";
        while (answer) {
            cout << answer->val << " ";
            answer = answer->next;
        }
        cout << endl;
    }

    return 0;
}

/**
 * Runtime: 0ms 100.00%
 * Memory: 14.84MB 91.71%
 */