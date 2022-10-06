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
    bool isPalindrome(ListNode* head) {
        ListNode* slow = head;
        ListNode* fast = head;
        
        while(fast and fast->next){
            slow = slow->next;
            fast = fast->next->next;
        }
        ListNode *newhead, *prev = NULL;
        while(slow){
            newhead = slow->next;
            slow -> next = prev;
            prev = slow;
            slow = newhead;
        }
        
        while(prev){
            if(head->val != prev->val) return false;
            head = head->next;
            prev = prev -> next;
            
        }
        return true;
    }
};