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
private:
     ListNode* reverseList(ListNode* head) {
        ListNode* prev= NULL;
        
        while(head){
            ListNode * curr = head->next;
            head->next = prev;
            prev = head;
            head = curr;
            
        }
        return prev;
    }
private:
    void merge(ListNode* head1, ListNode* head2){
        while(head1!= NULL and head2 != NULL){
            ListNode* next = head1->next;
            head1->next = head2;
            head1 = head2;
            head2 = next;
        }
    }
public:
    void reorderList(ListNode* head) {
        if(head==nullptr or head->next == nullptr) return;
        ListNode* slow = head;
        ListNode* fast = head;
        while(fast and fast->next){
            slow = slow->next;
            fast = fast->next->next;
        }
        //reverse the list
        ListNode* head2 = reverseList(slow->next);
        slow->next = NULL;
        //mergelist
        merge(head, head2);
        
        
    }
};