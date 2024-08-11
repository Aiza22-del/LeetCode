/*
25. Reverse Nodes in k-Group
Given the head of a linked list, reverse the nodes of the list k at a time, and return the modified list.
k is a positive integer and is less than or equal to the length of the linked list. If the number of nodes is not a multiple of k then left-out nodes, in the end, should remain as it is.
You may not alter the values in the list's nodes, only nodes themselves may be changed.

Example 1:
Input: head = [1,2,3,4,5], k = 2
Output: [2,1,4,3,5]

Example 2:
Input: head = [1,2,3,4,5], k = 3
Output: [3,2,1,4,5] 

Constraints:
The number of nodes in the list is n.
1 <= k <= n <= 5000
0 <= Node.val <= 1000
*/

class Solution {
public:
    ListNode* reverseKGroup(ListNode* head, int k) 
    {
        if (head == nullptr || k == 1) 
        {
            return head; 
        }

        ListNode temp(0);
        temp.next = head;
        ListNode* prevEnd = &temp;
        ListNode* current = head;

        while (true) 
        {
            ListNode* kNode = prevEnd;
            for (int i = 0; i < k; i++) 
            {
                kNode = kNode->next;
                if (kNode == nullptr) 
                {
                    return temp.next; 
                }
            }

            ListNode* nextGroup = kNode->next;
            ListNode* prev = nullptr;
            ListNode* curr = prevEnd->next;
            ListNode* temp;

            for (int i = 0; i < k; i++) 
            {
                temp = curr->next;
                curr->next = prev;
                prev = curr;
                curr = temp;
            }

            ListNode* firstReverse = prevEnd->next;
            prevEnd->next = prev;
            firstReverse->next = nextGroup;
            prevEnd = firstReverse;
        }
    }
};

