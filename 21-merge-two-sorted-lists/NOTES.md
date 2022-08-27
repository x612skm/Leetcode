We have to get the values to be checked by the values of the linkedlist after making a dummy node
whenever there is a linkage to another preference to give the dummy node
```
class Solution {
public:
ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
ListNode* dummy = new ListNode();
ListNode * temp;
temp = dummy;
while(list1 and list2){
if(list1->val < list2->val)
{
temp -> next = list1;
list1 = list1->next;
}
else{
temp->next = list2;
list2 = list2->next;
}
temp = temp->next;
}
//while if one of it present
if(list1) temp->next = list1;
if(list2) temp->next = list2;
return dummy->next;
}
};
```