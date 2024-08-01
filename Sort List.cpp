/*
148. Sort List
Given the head of a linked list, return the list after sorting it in ascending order.

Example 1:
Input: head = [4,2,1,3]
Output: [1,2,3,4]

Example 2:
Input: head = [-1,5,3,4,0]
Output: [-1,0,3,4,5]

Example 3:
Input: head = []
Output: []
 
Constraints:
The number of nodes in the list is in the range [0, 5 * 104].
-105 <= Node.val <= 105   
*/

class Solution {
public:
    ListNode* getMiddle(ListNode* head) 
    {
        if (!head) 
        {
            return nullptr;
        }

        ListNode* slow = head;
        ListNode* fast = head->next;

        while (fast != nullptr && fast->next != nullptr) 
        {
            slow = slow->next;
            fast = fast->next->next;
        }
        return slow;
    }

    ListNode* merge(ListNode* left, ListNode* right) 
    {
        if (!left) 
        {
            return right;
        }
        if (!right) 
        {
            return left;
        }

        if (left->val < right->val) 
        {
            left->next = merge(left->next, right);
            return left;
        } 
        else 
        {
            right->next = merge(left, right->next);
            return right;
        }
    }

    ListNode* sortList(ListNode* head) 
    {
        if (!head || !head->next) 
        {
            return head;
        }

        ListNode* middle = getMiddle(head);
        ListNode* left = head;
        ListNode* right = middle->next;
        middle->next = nullptr;

        left = sortList(left);
        right = sortList(right);

        return merge(left, right);
    }
};



