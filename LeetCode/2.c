/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */


struct ListNode* addTwoNumbers(struct ListNode* l1, struct ListNode* l2){
    struct ListNode* head = NULL ; 
    struct ListNode* tail = NULL ;
    int num1 = 0 ,  num2 = 0 ,  carry = 0 ;
    int sub ;
    while( l1 || l2){
        num1 = (l1 ? l1->val : 0);
        num2 = (l2 ? l2->val : 0);
        sub = num1 + num2 + carry ;

        if(!head){
            head = tail = malloc (sizeof(struct ListNode));
            tail->val = sub % 10 ;
            tail->next = NULL ;
        }
        else {
            tail->next = malloc(sizeof(struct ListNode));
            tail->next->val = sub % 10 ;
            tail = tail->next ;
            tail->next = NULL ;

        }
        carry = sub / 10 ;
        if(l1)
        {l1 = l1->next;}
        if(l2)
        {l2 = l2->next;}
    } 
    if(carry > 0)
    {
        tail->next = malloc(sizeof(struct ListNode));
        tail->next->val = carry ;
        tail->next->next = NULL ;
    }
    return head ;
}