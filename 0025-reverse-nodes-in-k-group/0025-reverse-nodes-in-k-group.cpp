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
    ListNode* reverse(ListNode* start, ListNode* end){
        ListNode* prev = end;
        while(start != end){
            ListNode* curr = start->next;
            start->next = prev;
            prev = start;
            start = curr;
        }
        return prev;
    }
public:
    ListNode* reverseKGroup(ListNode* head, int k) {
        //start form the front go till k make a window then reverse
        //call recrusing
        auto node = head;
        //traverse till k then mark the node
        for(int i=0; i<k; i++){
            while(!node)
                return head;
            node = node->next;
        }
        auto newhead = reverse(head, node);
        head->next = reverseKGroup(node, k);
        return newhead;
        
    }
};