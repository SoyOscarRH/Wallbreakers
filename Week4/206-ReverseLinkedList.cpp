/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
 public:
  ListNode* reverseList(ListNode* head, bool is_head = true) {
    if (not head or not head->next) return head;
    auto* next = head->next;
    auto* new_head = reverseList(next, false);

    next->next = head;
    if (is_head) head->next = nullptr;

    return new_head;
  }
};