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
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        ListNode* p=l1;
        ListNode* q=l2;
        ListNode* k=new ListNode(0);
        ListNode* Head=k;
        while(p!=NULL&&q!=NULL)
        {
            int temp;
            if(p->val<=q->val)
            {
                temp=p->val;
                p=p->next;
            }
            else
            {
                temp=q->val;
                q=q->next;
            }
            ListNode* t=new ListNode(temp);
            k->next=t;
            k=k->next;
        }
        while(p!=NULL)
        {
            ListNode* t=new ListNode(p->val);
            k->next=t;
            k=k->next;
            p=p->next;
        }
        while(q!=NULL)
        {
            ListNode* t=new ListNode(q->val);
            k->next=t;
            k=k->next;
            q=q->next;
        }
        return Head->next;
    }
};