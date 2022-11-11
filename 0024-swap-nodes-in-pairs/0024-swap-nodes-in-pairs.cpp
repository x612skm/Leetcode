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
//Runtime: 0 ms, faster than 100.00% of C++ online submissions for Swap Nodes in Pairs.
//Memory Usage: 7.5 MB, less than 91.68% of C++ online submissions for Swap Nodes in Pairs.

class Solution {
public:
    ListNode* swapPairs(ListNode* head) {
        //calling recursion for help
        //1,2,3,4 => 2 = curr => calling recursion to handle for the rest case
        //attchng 2 -> 1 rec[4->3]
        //2->1->4->3
        if(head==nullptr or head->next==nullptr)
            return head;
        ListNode* curr = head->next;
        head->next = swapPairs(head->next->next);
        curr->next = head;
        return curr;
    }
};