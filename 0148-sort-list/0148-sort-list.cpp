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
    //LC 21 merge two sorted list
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        ListNode* dummy = new ListNode();
        ListNode* curr;
        curr = dummy;
        
        while(list1 and list2){
            if(list1->val <= list2->val){
                curr->next = list1;
                list1 = list1->next;
            }
            else{
                curr->next = list2;
                list2 = list2->next;
            }
            curr = curr->next;
        }
        if(list1) curr->next = list1;
        if(list2) curr->next = list2;
        return dummy->next;
        delete dummy;
    }
public:
    ListNode* sortList(ListNode* head) {
        //base case
        if(head == nullptr or head->next==nullptr){
            return head;
        }
        ListNode* temp = nullptr;
        ListNode* slow = head;
        ListNode* fast = head;
        while(fast and fast->next){
            temp = slow;
            slow = slow -> next;
            fast = fast -> next-> next;
        }
        temp->next = nullptr; // braking the two into two seprate list
        
        ListNode* l1 = sortList(head);
        ListNode* l2 = sortList(slow);
        
        return mergeTwoLists(l1, l2);
        
 
        
    }
};