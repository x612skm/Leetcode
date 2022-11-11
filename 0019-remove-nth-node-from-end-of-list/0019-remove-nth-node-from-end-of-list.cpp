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
    // TC = O(n) + O(n) = O(n);
    //SC = O(1);
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode* dummy = new ListNode();
        dummy->next = head;
        ListNode* slow = dummy;
        ListNode* fast = dummy;
        
        // while(n--)
        //     fast = fast->next;
        for(int i=1; i<=n; i++)
            fast = fast->next;
        
        while(fast->next){
            fast = fast->next;
            slow = slow->next;
        }
        slow->next = slow -> next->next;
        return dummy->next;
        delete dummy;
    }
};