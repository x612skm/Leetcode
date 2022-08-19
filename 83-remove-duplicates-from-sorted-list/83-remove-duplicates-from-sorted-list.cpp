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
        ListNode* newHead = head;

        while(newHead and newHead->next){
            ListNode* nextNode = newHead->next;
            if(newHead->val == nextNode->val){
                newHead->next = nextNode->next;
                //delete nextNode;
            }
            else
                newHead = nextNode;
        }
        return head;
    }
};