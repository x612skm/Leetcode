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
    ListNode* mergeTwoList(ListNode* l1, ListNode* l2){
        //writing the format of merging two list
        //writing the base case for the format
        if(NULL == l1){
            return l2;
        }
        else if(NULL == l2) return l1;
        
        //writing the condiotins
        if(l1->val <= l2->val){
            l1->next = mergeTwoList(l1->next,l2);
            return l1;
        }
        else{
            l2->next = mergeTwoList(l2->next,l1);
            return l2;
        }
            
    }
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        if(lists.empty()) return NULL;
        int length = lists.size();
        //when the list is greater then 1
        while(length > 1){
        for(int i=0; i<length/2; ++i)//using the divide and conquer approach
            lists[i] = mergeTwoList(lists[i], lists[length-1-i]);
        
        length = (length+1)/2;
        }
        return lists.front();
    }
};