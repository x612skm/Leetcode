/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        ListNode* curra = headA;
        ListNode* currb = headB;
        
        
        if(curra == nullptr or currb == nullptr) return nullptr;
            
        
        while(curra != nullptr and currb != nullptr and curra != currb){
            curra = curra -> next;
            currb = currb -> next;
            
            if(curra == currb)
                return curra;
            
            if(!curra) curra = headB;
            if(!currb) currb = headA;
        }
        return curra;
    }
};