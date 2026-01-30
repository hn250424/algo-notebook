// Given the head of a sorted linked list, delete all duplicates such that each element appears only once. 
// Return the linked list sorted as well.

// Example 1:

// Input: head = [1,1,2]
// Output: [1,2]

// Example 2:

// Input: head = [1,1,2,3,3]
// Output: [1,2,3]

// Constraints:

// The number of nodes in the list is in the range [0, 300].
// -100 <= Node.val <= 100
// The list is guaranteed to be sorted in ascending order.

#include <iostream>

using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

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
class Solution {
public:
    ListNode* deleteDuplicates(ListNode* head) {
        if (!head) return nullptr;

        ListNode* pre = head;
        ListNode* cur = head->next;

        while (cur) {
            if (pre->val != cur->val) pre = pre->next;
            else pre->next = cur->next;
            cur = cur->next;
        }

        return head;
    }
};

int main() {
    // g.
    ListNode* head;
    ListNode* cur;
    
    int arr[5] = {1,1,2,3,3};

    ListNode* node = new ListNode(arr[0]);
    head = node;
    cur = node;

    for (int i = 1; i < 5; i++) {
        cur->next = new ListNode(arr[i]);
        cur = cur->next;
    }

    Solution sol;
    ListNode* answer = sol.deleteDuplicates(head);

    cout << "answer: ";
    while (answer) {
        cout << answer->val << " ";
        ListNode* temp = answer;
        answer = answer->next;
        delete temp;
    }
    cout << endl;

    return 0;
}

/**
 * Runtime: 0ms 100.00%
 * Memory: 16.28MB 31.86%
 */