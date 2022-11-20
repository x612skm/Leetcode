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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode* dummy = new ListNode();
        ListNode* curr = dummy;
        int carry = 0;
        
        while(l1 != nullptr or l2 != nullptr){
            int val1 = l1 != nullptr ? l1->val : 0;
            int val2 = l2 != nullptr ? l2->val : 0;
            
            int sum = val1 + val2 + carry;
            
            carry = sum/10;
            
            curr->next = new ListNode(sum%10);
            curr = curr -> next;
            
            if(l1 != nullptr)
                l1 = l1->next;
        
            if(l2 != nullptr)
                l2 = l2->next;
        }
       
        //condition for the 9 -> 9 -> 9 and 1 = 0->0->0->1
        if(carry == 1)
            curr->next = new ListNode(1);
        
        return dummy->next;    
    }
};