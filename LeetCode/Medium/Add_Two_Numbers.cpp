// You are given two non-empty linked lists representing two non-negative integers. The digits are stored in reverse order, and each of their nodes contains a single digit. Add the two numbers and return the sum as a linked list.

// You may assume the two numbers do not contain any leading zero, except the number 0 itself.

// Example 1:
// Input: l1 = [2,4,3], l2 = [5,6,4]
// Output: [7,0,8]
// Explanation: 342 + 465 = 807.

// Example 2:
// Input: l1 = [0], l2 = [0]
// Output: [0]

// Example 3:
// Input: l1 = [9,9,9,9,9,9,9], l2 = [9,9,9,9]
// Output: [8,9,9,9,0,0,0,1]
 
// Constraints:
// The number of nodes in each linked list is in the range [1, 100].
// 0 <= Node.val <= 9
// It is guaranteed that the list represents a number that does not have leading zeros.

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

 #include <iostream>

 using namespace std;

 struct ListNode {
    int val;
    ListNode *next;
    ListNode(): val(0), next(nullptr) {}
    ListNode(int x): val(x), next(nullptr) {}
    ListNode(int x, ListNode *next): val(x), next(next) {}
 };

class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode* answer = new ListNode();
        ListNode* current = answer;

        bool add = false;

        while (l1 || l2) {
            int v1 = l1 ? l1->val : 0;
            int v2 = l2 ? l2->val : 0;
            int sum = v1 + v2;

            if (add) {
                sum++;
                add = false;
            }

            if (sum >= 10) {
                add = true;
                sum -= 10;
            }

            current->val = sum;

            if (l1) l1 = l1->next;
            if (l2) l2 = l2->next;

            if (l1 || l2) {
                current->next = new ListNode();
                current = current->next;
            }
        }

        if (add) {
            current->next = new ListNode();
            current = current->next;
            current->val = 1;
        }

        return answer;
    }
};

int main() {
    // q.
    ListNode* l1 = new ListNode(2, new ListNode(4, new ListNode(3)));
    ListNode* l2 = new ListNode(5, new ListNode(6, new ListNode(4)));

    Solution s;
    ListNode* answer = s.addTwoNumbers(l1, l2);

    cout << "answer: ";
    while (answer) {
        cout << answer->val;
        answer = answer->next;
    }
    cout << endl;

    return 0;
}

/**
 * Runtime: 0ms 100.00%
 * Memory: 77.18MB 43.16%
 */