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
        ListNode* slow=head; ListNode* fast = head, *prev = NULL, *temp;
        if(!head and !head->next) return true;
        //find the middle using the tortoise and hare method
        while(fast and fast->next)
        {
            slow = slow->next;
            fast = fast->next->next;
        }
        cout<<slow->val;
        //initilise the middle ekement and after that
        // prev= slow;
        // slow = slow->next;
        // prev->next = NULL;
        
        //reverse from the slow and to the end
        while(slow){
            temp = slow->next;
            slow->next = prev;
            prev = slow;
            slow = temp;
        }
        //initlise fast to the start and compare the vals
        //equals tends to the true
        // fast = head;
        // slow = prev;
        
        while(prev){
        if(head->val != prev->val) return false;
        head = head -> next;
        prev = prev->next;
        }
        return true;
    }
};