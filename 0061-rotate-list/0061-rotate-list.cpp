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
    ListNode* rotateRight(ListNode* head, int k) {
        if(!head) return head;
        int size = 1;
        
        ListNode* tail = head;
        while(tail and tail->next){
            tail = tail->next;
            size++;
        }
        tail->next = head; //circle the linkedlist
        
        //leetcode rotate array concept
        //leetcode 189
        k = k % size;
        k%=size;
        int curr = 0;
        while(tail and tail->next and size-curr != k){
            tail = tail->next;
            curr++;
        }
        
        ListNode* newhead = tail->next;
        tail->next = NULL;
        return newhead;
    }
};