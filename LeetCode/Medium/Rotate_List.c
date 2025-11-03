// Given the head of a linked list, rotate the list to the right by k places.

// Example 1:

// Input: head = [1,2,3,4,5], k = 2
// Output: [4,5,1,2,3]

// Example 2:

// Input: head = [0,1,2], k = 4
// Output: [2,0,1]

// Constraints:

// The number of nodes in the list is in the range [0, 500].
// -100 <= Node.val <= 100
// 0 <= k <= 2 * 109

#include <stdio.h>
#include <stdlib.h>

struct ListNode {
    int val;
    struct ListNode *next;
};

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode* rotateRight(struct ListNode* head, int k) {
    if (head == NULL || head->next == NULL) return head;
    struct ListNode* cur = head;

    int len = 1;
    while (cur->next != NULL) {
        len++;
        cur = cur->next;
    }
    
    k = k % len;
    if (k == 0) return head;
    
    cur->next = head;

    struct ListNode* newTail = head;
    for (int i = 1; i < (len - k); i++) {
        newTail = newTail->next;
    }

    struct ListNode* newHead = newTail->next;
    newTail->next = NULL;

    return newHead;
}

int main() {
    // g.
    // int arr[] = {1,2,3,4,5};
    // int arr_len = 5;
    // int arr[] = {0,1,2};
    // int arr_len = 3;
    int arr[] = {1,2};
    int arr_len = 2;
    struct ListNode* head = NULL;
    struct ListNode* head_temp = NULL;
    for (int i = 0; i < arr_len; i++) {
        if (i == 0) {
            head = malloc(sizeof(struct ListNode));
            head_temp = head;
        } else {
            head_temp->next = malloc(sizeof(struct ListNode));
            head_temp = head_temp->next;
        }
        head_temp->val = arr[i];
    }
    head_temp->next = NULL;
    // int k = 2;
    // int k = 4;
    int k = 0;

    struct ListNode* answer = rotateRight(head, k);
    struct ListNode* answer_temp = answer;
    while (answer_temp != NULL) {
        printf("%d ", answer_temp->val);
        struct ListNode* t = answer_temp;
        answer_temp = answer_temp->next;
        free(t);
    }
    printf("\n");
    
    return 0;
}

/**
 * Runtime: 0ms 100.00%
 * Memory: 10.71MB 26.21%
 */