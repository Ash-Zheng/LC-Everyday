/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class A :public priority_queue <int, vector<int>, greater<int> > {
public:
 using priority_queue::c;
};

class Solution {
public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        priority_queue <int, vector<int>, greater<int>> que;
        ListNode* Head=new ListNode(0);
        ListNode* result=Head;
        int n=lists.size();
        for(auto p:lists)
        {
            while(p!=NULL)
            {
                que.push(p->val);
                p=p->next;
            }
        }
        while(!que.empty())
        {
            int k=que.top();
            que.pop();
            ListNode* q=new ListNode(k);
            Head->next=q;
            Head=q;
        }
        return result->next;
    }
};