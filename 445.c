class Solution {
public:
    ListNode* addTwoNumbers(const ListNode* l1, const ListNode* l2) {
        int add=0;
        stack<int> stk1;
        stack<int> stk2;
        while(l1!=NULL)
        {
            stk1.push(l1->val);
            l1=l1->next;
        }
        while(l2!=NULL)
        {
            stk2.push(l2->val);
            l2=l2->next;
        }
        ListNode* Head = new ListNode(0);
        while(!stk1.empty()||!stk2.empty()||add>0)
        {
            int sum=add;       
            if(!stk1.empty())
            {
                sum+= stk1.top();
                stk1.pop();
            }    
            if(!stk2.empty())
            {
                sum+=stk2.top();
                stk2.pop();
            }
            ListNode *p=new ListNode(sum%10);
            p->next=Head->next;
            Head->next=p;
            add=sum/10; 
        }
        return Head->next;
    }
};