// Given a linked list, swap every two adjacent nodes and return its head. You must solve the problem without modifying the values in the list's nodes (i.e., only nodes themselves may be changed.)

// Example 1:

// Input: head = [1,2,3,4]

// Output: [2,1,4,3]

// Explanation:

// Example 2:

// Input: head = []

// Output: []

// Example 3:

// Input: head = [1]

// Output: [1]

// Example 4:

// Input: head = [1,2,3]

// Output: [2,1,3]

// Constraints:

// The number of nodes in the list is in the range [0, 100].
// 0 <= Node.val <= 100

#include <vector>
#include <unordered_map>
#include <string>
#include <iostream>

using namespace std;

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
struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
    ListNode* swapPairs(ListNode* head) {
        ListNode dummy;
        ListNode* prev = &dummy;

        while (head && head->next) {
            ListNode* first = head;
            ListNode* second = head->next;
    
            first->next = second->next;
            second->next = first;
    
            prev->next = second;

            head = first->next;
            prev = first;
        }

        if (head) prev->next = head;
        return dummy.next;
    }
};

int main() {
    // g.
    ListNode* head = new ListNode(1, new ListNode(2, new ListNode(3)));
    // ListNode* head = new ListNode(1, new ListNode(2, new ListNode(3, new ListNode(4))));
    
    Solution sol;
    ListNode* answer = sol.swapPairs(head);
    while (answer) {
        cout << answer->val << " ";
        answer = answer->next;
    }
    cout << endl;

    return 0;
}

/**
 * Runtime: 0ms 100.00%
 * Memory: 11.23MB 19.92%
 */