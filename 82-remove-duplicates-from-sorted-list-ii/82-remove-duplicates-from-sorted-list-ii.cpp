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
    ListNode* deleteDuplicates(ListNode* head) {
        if (head == NULL) return NULL;
        ListNode* fakeHead = new ListNode(0,head);
        fakeHead -> next = head;
        ListNode* pre = fakeHead;
        ListNode* curr = head;
        
        while(curr != NULL){
            while(curr->next != NULL && curr->val == curr->next->val){
                curr=curr->next;
            }
            if(pre->next == curr){
                pre=pre->next;
            }
            else{
                pre->next = curr -> next;
            }
            curr = curr -> next;
        }
        return fakeHead -> next;
    }
};