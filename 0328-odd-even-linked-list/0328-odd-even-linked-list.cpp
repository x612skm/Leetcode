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
    ListNode* oddEvenList(ListNode* head) {
        //od even odd even odd => odd odd odd even even
        
        if(head == nullptr) return nullptr;
        ListNode* odd = head;
        ListNode* even = head->next;
        ListNode* evenhead = even;
        
        //lets check for the even node
        if(head != nullptr){
        while(even != nullptr and even->next != nullptr){
            //1(head)->3->5
            odd->next = odd->next->next;
            //2(head->next)->4
            even->next = even->next->next;
            //1->3->5
            odd = odd->next;
            //2->4
            even = even->next;
            
            //once this while conditions terminate
        }
        //1->3->5 -> []= 2->4 
        odd->next = evenhead;
        }
        //1->3->5->2->4
        return head;
    }
};