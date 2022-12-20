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
//logic will be as followed we reverse the secondhalf of the list then merge the list
class Solution {
private:
    ListNode* reverseList(ListNode* head){
        ListNode* prev = NULL;
        while(head){
            ListNode* next = head->next;
            head->next = prev;
            prev = head;
            head = next;
        }
        return prev;
    }
    void merge(ListNode* head1, ListNode* head2){
        while(head1 and head2){
            ListNode* next = head1->next;
            head1->next = head2;
            head1 = head2;
            head2 = next;
        }
    }
public:
    void reorderList(ListNode* head) {
        if(!head and !head->next)
            return;
        ListNode* fast = head;
        ListNode* slow = head;
        while(fast and fast->next){
            slow = slow->next;
            fast = fast->next->next;
        }
        ListNode* head2 = reverseList(slow->next);
        slow->next = nullptr;
        merge(head,head2);
    }
};