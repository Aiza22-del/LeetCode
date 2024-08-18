/*
23. Merge k Sorted Lists
You are given an array of k linked-lists lists, each linked-list is sorted in ascending order.
Merge all the linked-lists into one sorted linked-list and return it.

Example 1:
Input: lists = [[1,4,5],[1,3,4],[2,6]]
Output: [1,1,2,3,4,4,5,6]
Explanation: The linked-lists are:
[
  1->4->5,
  1->3->4,
  2->6
]
merging them into one sorted list:
1->1->2->3->4->4->5->6

Example 2:
Input: lists = []
Output: []

Example 3:
Input: lists = [[]]
Output: []

Constraints:
k == lists.length
0 <= k <= 104
0 <= lists[i].length <= 500
-104 <= lists[i][j] <= 104
lists[i] is sorted in ascending order.
The sum of lists[i].length will not exceed 104.
*/

class Solution {
public:
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) 
    {
        ListNode* tempHead = new ListNode(0);
        ListNode* current = tempHead;
        
        while (l1 != nullptr && l2 != nullptr) 
        {
            if (l1->val <= l2->val) 
            {
                current->next = l1;
                l1 = l1->next;
            } 
            else 
            {
                current->next = l2;
                l2 = l2->next;
            }
            current = current->next;
        }
        
         if (l1 != nullptr) 
         {
            current->next = l1;
        } 
        else 
        {
            current->next = l2;
        }
        
        return tempHead->next;

    }

    ListNode* mergeKLists(vector<ListNode*>& lists) 
    {
        if (lists.empty()) 
        {
            return nullptr;
        }

        ListNode* mergedList = lists[0];

        for (int i = 1; i < lists.size(); i++) 
        {
            mergedList = mergeTwoLists(mergedList, lists[i]);
        }

        return mergedList;
    }
};


